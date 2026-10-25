#include <string.h>
#if HAS_OLD_LIBDWARF || HAS_LIBDWARF
#include <stdio.h>
#include <libdwarf.h>
#include <dwarf.h>
#endif

#include "diagnostic_internal.h"
#include "debug.h"
#include "buffer.h"
#include "str.h"


#if HAS_OLD_LIBDWARF

static
int
dwarfAccessGetSectionInfo(
    void* obj,
    Dwarf_Half sectionIndex,
    Dwarf_Obj_Access_Section* accessSection,
    int* error
) {
    WasmDebugSections* sections = (WasmDebugSections*) obj;
    WasmDebugSection section = sections->debugSections[sectionIndex];

    accessSection->addr = 0;
    accessSection->name = section.name.data;
    accessSection->size = section.buffer.length;
    accessSection->info = 0;
    accessSection->link = 0;
    accessSection->type = 0;
    accessSection->entrysize = 0;

    return DW_DLV_OK;
}

static
Dwarf_Endianness
dwarfAccessGetByteOrder(
    void* obj
) {
    return DW_END_little;
}

static
Dwarf_Small
dwarfAccessGetPointerSize(
    void* obj
) {
    return 4;
}

static
Dwarf_Small
dwarfAccessGetLengthSize(
    void* obj
) {
    return 4;
}

static
Dwarf_Unsigned
dwarfAccessGetSectionCount(
    void* obj
) {
    WasmDebugSections* sections = (WasmDebugSections*) obj;
    return sections->length;
}

static
int
dwarfAccessLoadSection(
    void* obj,
    Dwarf_Half sectionIndex,
    Dwarf_Small** sectionData,
    int* error
) {
    WasmDebugSections* sections = (WasmDebugSections*) obj;
    WasmDebugSection section = sections->debugSections[sectionIndex];

    *sectionData = section.buffer.data;

    return DW_DLV_OK;
}

static
int
dwarfAccessRelocateASection(
    void* obj,
    Dwarf_Half sectionIndex,
    Dwarf_Debug debug,
    int* error
) {
    return DW_DLV_NO_ENTRY;
}

static const struct Dwarf_Obj_Access_Methods_s dwarfAccessMethods = {
    dwarfAccessGetSectionInfo,
    dwarfAccessGetByteOrder,
    dwarfAccessGetLengthSize,
    dwarfAccessGetPointerSize,
    dwarfAccessGetSectionCount,
    dwarfAccessLoadSection,
    dwarfAccessRelocateASection
};

static
int
compareDebugLines(const void *a, const void *b) {
    WasmDebugLine* l1 = (WasmDebugLine*) a;
    WasmDebugLine* l2 = (WasmDebugLine*) b;
    if (l1->address < l2->address) {
        return -1;
    } else if (l1->address > l2->address) {
        return 1;
    } else {
        return 0;
    }
}

static
void
appendSubprogramDebugLine(
    Dwarf_Debug debug,
    Dwarf_Die die,
    char** files,
    Dwarf_Signed fileCount,
    WasmDebugLines* debugLines,
    WasmDiagnosticContext* diagnostics
) {
    int res = DW_DLV_ERROR;
    Dwarf_Error error = NULL;
    Dwarf_Addr address = 0;
    Dwarf_Bool hasDeclLine = false;
    Dwarf_Bool hasDeclFile = false;
    Dwarf_Attribute attr = NULL;
    Dwarf_Unsigned line = 0;
    Dwarf_Unsigned fileIndex = 0;

    res = dwarf_lowpc(die, &address, &error);
    if (res != DW_DLV_OK || address >= 0xffffffff) {
        goto cleanup;
    }

    res = dwarf_hasattr(die, DW_AT_decl_line, &hasDeclLine, &error);
    if (res != DW_DLV_OK || !hasDeclLine) {
        goto cleanup;
    }

    res = dwarf_hasattr(die, DW_AT_decl_file, &hasDeclFile, &error);
    if (res != DW_DLV_OK || !hasDeclFile) {
        goto cleanup;
    }

    res = dwarf_attr(die, DW_AT_decl_line, &attr, &error);
    if (res != DW_DLV_OK) {
        goto cleanup;
    }

    res = dwarf_formudata(attr, &line, &error);
    if (res != DW_DLV_OK) {
        goto cleanup;
    }
    dwarf_dealloc(debug, attr, DW_DLA_ATTR);
    attr = NULL;

    res = dwarf_attr(die, DW_AT_decl_file, &attr, &error);
    if (res != DW_DLV_OK) {
        goto cleanup;
    }

    res = dwarf_formudata(attr, &fileIndex, &error);
    if (res != DW_DLV_OK) {
        goto cleanup;
    }
    dwarf_dealloc(debug, attr, DW_DLA_ATTR);
    attr = NULL;

    if (fileIndex == 0 || fileIndex > (Dwarf_Unsigned)fileCount) {
        goto cleanup;
    }

    {
        WasmDebugLine debugLine = {0, NULL, 0};
        debugLine.address = address;
        debugLine.path = strdup(files[fileIndex - 1]);
        debugLine.number = line;

        if (debugLine.path == NULL
            || !wasmDebugLinesAppend(debugLines, debugLine)) {

            wasmDiagnosticReportDwarfFailure(diagnostics, wasmDiagnosticDwarfAllocate);
            /* TODO: bubble up error? */
            free(debugLine.path);
        }
    }

cleanup:
    if (attr != NULL) {
        dwarf_dealloc(debug, attr, DW_DLA_ATTR);
    }
    if (error != NULL) {
        wasmDiagnosticReportDwarfFailure(diagnostics, wasmDiagnosticDwarfAttribute);
        dwarf_dealloc(debug, error, DW_DLA_ERROR);
    }
}

static
void
appendSubprogramDebugLines(
    Dwarf_Debug debug,
    Dwarf_Die rootDie,
    char** files,
    Dwarf_Signed fileCount,
    WasmDebugLines* debugLines,
    WasmDiagnosticContext* diagnostics
) {
    int res = DW_DLV_ERROR;
    Dwarf_Die childDie = NULL;
    Dwarf_Error error = NULL;

    res = dwarf_child(rootDie, &childDie, &error);
    if (res != DW_DLV_OK) {
        if (res == DW_DLV_ERROR) {
            wasmDiagnosticReportDwarfFailure(diagnostics, wasmDiagnosticDwarfChild);
        }
        if (error != NULL) {
            dwarf_dealloc(debug, error, DW_DLA_ERROR);
        }
        return;
    }

    while (true) {
        Dwarf_Half childDieTag = 0;
        Dwarf_Die nextChildDie = NULL;

        res = dwarf_tag(childDie, &childDieTag, &error);
        if (res != DW_DLV_OK) {
            if (res == DW_DLV_ERROR) {
                wasmDiagnosticReportDwarfFailure(diagnostics, wasmDiagnosticDwarfTag);
            }
            if (error != NULL) {
                dwarf_dealloc(debug, error, DW_DLA_ERROR);
                error = NULL;
            }
        }

        if (childDieTag == DW_TAG_subprogram) {
            appendSubprogramDebugLine(
                debug,
                childDie,
                files,
                fileCount,
                debugLines,
                diagnostics
            );
        }

        if (childDieTag != DW_TAG_base_type
            && childDieTag != DW_TAG_lexical_block) {

            appendSubprogramDebugLines(
                debug,
                childDie,
                files,
                fileCount,
                debugLines,
                diagnostics
            );
        }

        res = dwarf_siblingof(debug, childDie, &nextChildDie, &error);
        dwarf_dealloc(debug, childDie, DW_DLA_DIE);
        childDie = nextChildDie;

        if (res != DW_DLV_OK) {
            if (res == DW_DLV_ERROR) {
                wasmDiagnosticReportDwarfFailure(diagnostics, wasmDiagnosticDwarfSibling);
            }
            if (error != NULL) {
                dwarf_dealloc(debug, error, DW_DLA_ERROR);
            }
            return;
        }
    }
}

static
WasmDebugLines
wasmParseDebugInfoInternal(
    WasmDebugSections sections,
    WasmDiagnosticContext* diagnostics
) {
    WasmDebugLines debugLines = emptyWasmDebugLines;
    const char* version = dwarf_package_version();
    int res = DW_DLV_ERROR;
    Dwarf_Obj_Access_Interface* interface = NULL;
    Dwarf_Debug debug = NULL;
    Dwarf_Error error = NULL;

    if (version == NULL
        || strlen(version) != 8
        || strspn(version, "0123456789") != 8
        || strcmp(version, "20201020") < 0) {

        wasmDiagnosticReportDwarfVersionUnsupported(diagnostics, version);
        goto end;
    }

    interface = (Dwarf_Obj_Access_Interface*)calloc(1, sizeof(*interface));
    if (!interface) {
        wasmDiagnosticReportDwarfFailure(diagnostics, wasmDiagnosticDwarfAllocate);
        goto end;
    }

    interface->object = &sections;
    interface->methods = &dwarfAccessMethods;

    res = dwarf_object_init(interface, NULL, NULL, &debug, &error);
    if (res != DW_DLV_OK) {
        if (res == DW_DLV_ERROR) {
            wasmDiagnosticReportDwarfFailure(diagnostics, wasmDiagnosticDwarfInitialize);
        }
        goto end;
    }

    while (true) {
        Dwarf_Die cuDie = NULL;
        Dwarf_Half tag = 0;
        Dwarf_Signed fileCount = 0;
        char** files = NULL;
        Dwarf_Signed lineCount = 0;
        Dwarf_Line *lines = NULL;
        int lineIndex = 0;

        res = dwarf_next_cu_header(debug, NULL, NULL, NULL, NULL, NULL, &error);
        if (res != DW_DLV_OK) {
            if (res == DW_DLV_ERROR) {
                wasmDiagnosticReportDwarfFailure(diagnostics, wasmDiagnosticDwarfNextUnit);
            }
            if (error != NULL) {
                dwarf_dealloc(debug, error, DW_DLA_ERROR);
                error = NULL;
            }
            break;
        }

        res = dwarf_siblingof(debug, NULL, &cuDie, &error);
        if (res != DW_DLV_OK) {
            if (res == DW_DLV_ERROR) {
                wasmDiagnosticReportDwarfFailure(diagnostics, wasmDiagnosticDwarfSibling);
            }
            goto cleanup_cu;
        }

        res = dwarf_tag(cuDie, &tag, &error);
        if (res != DW_DLV_OK) {
            if (res == DW_DLV_ERROR) {
                wasmDiagnosticReportDwarfFailure(diagnostics, wasmDiagnosticDwarfTag);
            }
            goto cleanup_cu;
        }

        if (tag != DW_TAG_compile_unit) {
            wasmDiagnosticReportDwarfUnexpectedTag(diagnostics, (U32)tag);
            goto cleanup_cu;
        }

        res = dwarf_srcfiles(cuDie, &files, &fileCount, &error);
        if  (res != DW_DLV_OK) {
            wasmDiagnosticReportDwarfFailure(diagnostics, wasmDiagnosticDwarfFiles);
            goto cleanup_cu;
        }

        appendSubprogramDebugLines(
            debug,
            cuDie,
            files,
            fileCount,
            &debugLines,
            diagnostics
        );

        res = dwarf_srclines(cuDie, &lines, &lineCount, &error);
        if (res != DW_DLV_OK) {
            if (res == DW_DLV_ERROR) {
                wasmDiagnosticReportDwarfFailure(diagnostics, wasmDiagnosticDwarfLines);
            }
            goto cleanup_cu;
        }

        for (; lineIndex < lineCount; lineIndex++) {
            Dwarf_Line line = lines[lineIndex];
            WasmDebugLine debugLine = {0, NULL, 0};
            char* path = NULL;

            /* Line address */
            res = dwarf_lineaddr(line, &debugLine.address, &error);
            if (res != DW_DLV_OK) {
                if (res == DW_DLV_ERROR) {
                    wasmDiagnosticReportDwarfFailure(diagnostics, wasmDiagnosticDwarfLineAddress);
                }
                goto cleanup_cu;
            }

            /* TODO: why the big jump? */
            if (debugLine.address >= 0xffffffff) {
                continue;
            }

            /* Line source / path */
            res = dwarf_linesrc(line, &path, &error);
            if (res != DW_DLV_OK) {
                if (res == DW_DLV_ERROR) {
                    wasmDiagnosticReportDwarfFailure(diagnostics, wasmDiagnosticDwarfLineSource);
                }
                goto cleanup_cu;
            }
            debugLine.path = strdup(path);
            dwarf_dealloc(debug, path, DW_DLA_STRING);
            path = NULL;
            if (debugLine.path == NULL) {
                wasmDiagnosticReportDwarfFailure(diagnostics, wasmDiagnosticDwarfAllocate);
                goto cleanup_cu;
            }

            /* Line number */
            res = dwarf_lineno(line, &debugLine.number, &error);
            if (res != DW_DLV_OK) {
                if (res == DW_DLV_ERROR) {
                    wasmDiagnosticReportDwarfFailure(diagnostics, wasmDiagnosticDwarfLineNumber);
                }
                free(debugLine.path);
                goto cleanup_cu;
            }

            if (!wasmDebugLinesAppend(&debugLines, debugLine)) {
                wasmDiagnosticReportDwarfFailure(diagnostics, wasmDiagnosticDwarfAllocate);
                free(debugLine.path);
                goto cleanup_cu;
            }
        }

cleanup_cu:
        if (lines != NULL) {
            dwarf_srclines_dealloc(debug, lines, lineCount);
        }
        if (files != NULL) {
            int fileIndex = 0;
            for (fileIndex = 0; fileIndex < fileCount; fileIndex++) {
                dwarf_dealloc(debug, files[fileIndex], DW_DLA_STRING);
            }
            dwarf_dealloc(debug, files, DW_DLA_LIST);
        }
        if (cuDie != NULL) {
            dwarf_dealloc(debug, cuDie, DW_DLA_DIE);
        }
        if (error != NULL) {
            dwarf_dealloc(debug, error, DW_DLA_ERROR);
            error = NULL;
        }
    }

    if (debug != NULL) {
        res = dwarf_object_finish(debug, &error);
        debug = NULL;
        if (res != DW_DLV_OK) {
            if (res == DW_DLV_ERROR) {
                wasmDiagnosticReportDwarfFailure(diagnostics, wasmDiagnosticDwarfFinish);
            }
        }
    }

end:
    if (error != NULL) {
        dwarf_dealloc_error(NULL, error);
    }
    if (interface != NULL) {
        free(interface);
    }

    if (debugLines.length > 1) {
        qsort(
            debugLines.debugLines,
            debugLines.length,
            sizeof(WasmDebugLine),
            compareDebugLines
        );
    }

    return debugLines;
}

#elif HAS_LIBDWARF

static
int
dwarfAccessGetSectionInfo(
    void* obj,
    Dwarf_Unsigned sectionIndex,
    Dwarf_Obj_Access_Section_a *accessSection,
    int* error
) {
    WasmDebugSections* sections = (WasmDebugSections*) obj;
    WasmDebugSection section = sections->debugSections[sectionIndex];
    UNUSED_PARAMETER(error);

    accessSection->as_addr = 0;
    accessSection->as_name = section.name.data;
    accessSection->as_size = section.buffer.length;
    accessSection->as_info = 0;
    accessSection->as_link = 0;
    accessSection->as_type = 0;
    accessSection->as_entrysize = 0;

    return DW_DLV_OK;
}

static const bool isInfo = true;

static
Dwarf_Small
dwarfAccessGetByteOrder(
    void* obj
) {
    UNUSED_PARAMETER(obj);
    return DW_END_little;
}

static
Dwarf_Small
dwarfAccessGetPointerSize(
    void* obj
) {
    UNUSED_PARAMETER(obj);
    return 4;
}

static
Dwarf_Unsigned
dwarfAccessGetFileSize(
    void* obj
) {
    UNUSED_PARAMETER(obj);
    return 0;
}

static
Dwarf_Small
dwarfAccessGetLengthSize(
    void* obj
) {
    UNUSED_PARAMETER(obj);
    return 4;
}

static
Dwarf_Unsigned
dwarfAccessGetSectionCount(
    void* obj
) {
    WasmDebugSections* sections = (WasmDebugSections*) obj;
    return sections->length;
}

static
int
dwarfAccessLoadSection(
    void* obj,
    Dwarf_Unsigned sectionIndex,
    Dwarf_Small** sectionData,
    int* error
) {
    WasmDebugSections* sections = (WasmDebugSections*) obj;
    WasmDebugSection section = sections->debugSections[sectionIndex];
    UNUSED_PARAMETER(error);

    *sectionData = section.buffer.data;

    return DW_DLV_OK;
}

static
int
dwarfAccessRelocateASection(
    void* obj,
    Dwarf_Unsigned sectionIndex,
    Dwarf_Debug debug,
    int* error
) {
    UNUSED_PARAMETER(obj);
    UNUSED_PARAMETER(sectionIndex);
    UNUSED_PARAMETER(debug);
    UNUSED_PARAMETER(error);
    return DW_DLV_NO_ENTRY;
}

static const struct Dwarf_Obj_Access_Methods_a_s dwarfAccessMethods = {
    dwarfAccessGetSectionInfo,
    dwarfAccessGetByteOrder,
    dwarfAccessGetLengthSize,
    dwarfAccessGetPointerSize,
    dwarfAccessGetFileSize,
    dwarfAccessGetSectionCount,
    dwarfAccessLoadSection,
    dwarfAccessRelocateASection
};

static
int
compareDebugLines(
    const void* a,
    const void* b
){
    WasmDebugLine* l1 = (WasmDebugLine*) a;
    WasmDebugLine* l2 = (WasmDebugLine*) b;
    if (l1->address < l2->address) {
        return -1;
    } else if (l1->address > l2->address) {
        return 1;
    } else {
        return 0;
    }
}

static
void
appendSubprogramDebugLine(
    Dwarf_Debug debug,
    Dwarf_Die die,
    char** files,
    Dwarf_Signed fileCount,
    WasmDebugLines* debugLines,
    WasmDiagnosticContext* diagnostics
) {
    int res = DW_DLV_ERROR;
    Dwarf_Error error = NULL;
    Dwarf_Addr address = 0;
    Dwarf_Bool hasDeclLine = false;
    Dwarf_Bool hasDeclFile = false;
    Dwarf_Attribute attr = NULL;
    Dwarf_Unsigned line = 0;
    Dwarf_Unsigned fileIndex = 0;

    res = dwarf_lowpc(die, &address, &error);
    if (res != DW_DLV_OK || address >= 0xffffffff) {
        goto cleanup;
    }

    res = dwarf_hasattr(die, DW_AT_decl_line, &hasDeclLine, &error);
    if (res != DW_DLV_OK || !hasDeclLine) {
        goto cleanup;
    }

    res = dwarf_hasattr(die, DW_AT_decl_file, &hasDeclFile, &error);
    if (res != DW_DLV_OK || !hasDeclFile) {
        goto cleanup;
    }

    res = dwarf_attr(die, DW_AT_decl_line, &attr, &error);
    if (res != DW_DLV_OK) {
        goto cleanup;
    }

    res = dwarf_formudata(attr, &line, &error);
    if (res != DW_DLV_OK) {
        goto cleanup;
    }
    dwarf_dealloc(debug, attr, DW_DLA_ATTR);
    attr = NULL;

    res = dwarf_attr(die, DW_AT_decl_file, &attr, &error);
    if (res != DW_DLV_OK) {
        goto cleanup;
    }

    res = dwarf_formudata(attr, &fileIndex, &error);
    if (res != DW_DLV_OK) {
        goto cleanup;
    }
    dwarf_dealloc(debug, attr, DW_DLA_ATTR);
    attr = NULL;

    if (fileIndex == 0 || fileIndex > (Dwarf_Unsigned)fileCount) {
        goto cleanup;
    }

    {
        WasmDebugLine debugLine = {0, NULL, 0};
        debugLine.address = address;
        debugLine.path = strdup(files[fileIndex - 1]);
        debugLine.number = line;

        if (debugLine.path == NULL
            || !wasmDebugLinesAppend(debugLines, debugLine)) {

            wasmDiagnosticReportDwarfFailure(diagnostics, wasmDiagnosticDwarfAllocate);
            /* TODO: bubble up error? */
            free(debugLine.path);
        }
    }

cleanup:
    if (attr != NULL) {
        dwarf_dealloc(debug, attr, DW_DLA_ATTR);
    }
    if (error != NULL) {
        wasmDiagnosticReportDwarfFailure(diagnostics, wasmDiagnosticDwarfAttribute);
        dwarf_dealloc(debug, error, DW_DLA_ERROR);
    }
}

static
void
appendSubprogramDebugLines(
    Dwarf_Debug debug,
    Dwarf_Die rootDie,
    char** files,
    Dwarf_Signed fileCount,
    WasmDebugLines* debugLines,
    WasmDiagnosticContext* diagnostics
) {
    int res = DW_DLV_ERROR;
    Dwarf_Die childDie = NULL;
    Dwarf_Error error = NULL;

    res = dwarf_child(rootDie, &childDie, &error);
    if (res != DW_DLV_OK) {
        if (res == DW_DLV_ERROR) {
            wasmDiagnosticReportDwarfFailure(diagnostics, wasmDiagnosticDwarfChild);
        }
        if (error != NULL) {
            dwarf_dealloc(debug, error, DW_DLA_ERROR);
        }
        return;
    }

    while (true) {
        Dwarf_Half childDieTag = 0;
        Dwarf_Die nextChildDie = NULL;

        res = dwarf_tag(childDie, &childDieTag, &error);
        if (res != DW_DLV_OK) {
            if (res == DW_DLV_ERROR) {
                wasmDiagnosticReportDwarfFailure(diagnostics, wasmDiagnosticDwarfTag);
            }
            if (error != NULL) {
                dwarf_dealloc(debug, error, DW_DLA_ERROR);
                error = NULL;
            }
        }

        if (childDieTag == DW_TAG_subprogram) {
            appendSubprogramDebugLine(
                debug,
                childDie,
                files,
                fileCount,
                debugLines,
                diagnostics
            );
        }

        if (childDieTag != DW_TAG_base_type
            && childDieTag != DW_TAG_lexical_block) {

            appendSubprogramDebugLines(
                debug,
                childDie,
                files,
                fileCount,
                debugLines,
                diagnostics
            );
        }

        res = dwarf_siblingof_b(debug, childDie, isInfo, &nextChildDie, &error);
        dwarf_dealloc(debug, childDie, DW_DLA_DIE);
        childDie = nextChildDie;

        if (res != DW_DLV_OK) {
            if (res == DW_DLV_ERROR) {
                wasmDiagnosticReportDwarfFailure(diagnostics, wasmDiagnosticDwarfSibling);
            }
            if (error != NULL) {
                dwarf_dealloc(debug, error, DW_DLA_ERROR);
            }
            return;
        }
    }
}

static
WasmDebugLines
wasmParseDebugInfoInternal(
    WasmDebugSections sections,
    WasmDiagnosticContext* diagnostics
) {
    WasmDebugLines debugLines = emptyWasmDebugLines;
    int res = DW_DLV_ERROR;
    Dwarf_Obj_Access_Interface_a* interface = NULL;
    Dwarf_Debug debug = NULL;
    Dwarf_Error error = NULL;

    interface = (Dwarf_Obj_Access_Interface_a*)calloc(1, sizeof(Dwarf_Obj_Access_Interface_a));
    if (!interface) {
        wasmDiagnosticReportDwarfFailure(diagnostics, wasmDiagnosticDwarfAllocate);
        goto end;
    }

    interface->ai_object = &sections;
    interface->ai_methods = &dwarfAccessMethods;

    res = dwarf_object_init_b(interface, NULL, NULL, 0, &debug, &error);
    if (res != DW_DLV_OK) {
        if (res == DW_DLV_ERROR) {
            wasmDiagnosticReportDwarfFailure(diagnostics, wasmDiagnosticDwarfInitialize);
        }
        goto end;
    }

    while (true) {
        Dwarf_Die cuDie = NULL;
        Dwarf_Half tag = 0;
        Dwarf_Signed fileCount = 0;
        char** files = NULL;
        Dwarf_Signed lineCount = 0;
        Dwarf_Line *lines = NULL;
        int lineIndex = 0;
        Dwarf_Line_Context lineContext = NULL;
        Dwarf_Unsigned version = 0;
        Dwarf_Small tableCount = 0;

        res = dwarf_next_cu_header_d(debug, isInfo, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, &error);
        if (res != DW_DLV_OK) {
            if (res == DW_DLV_ERROR) {
                wasmDiagnosticReportDwarfFailure(diagnostics, wasmDiagnosticDwarfNextUnit);
            }
            if (error != NULL) {
                dwarf_dealloc_error(debug, error);
                error = NULL;
            }
            break;
        }

        res = dwarf_siblingof_b(debug, NULL, isInfo, &cuDie, &error);
        if (res != DW_DLV_OK) {
            if (res == DW_DLV_ERROR) {
                wasmDiagnosticReportDwarfFailure(diagnostics, wasmDiagnosticDwarfSibling);
            }
            goto cleanup_cu;
        }

        res = dwarf_tag(cuDie, &tag, &error);
        if (res != DW_DLV_OK) {
            if (res == DW_DLV_ERROR) {
                wasmDiagnosticReportDwarfFailure(diagnostics, wasmDiagnosticDwarfTag);
            }
            goto cleanup_cu;
        }

        if (tag != DW_TAG_compile_unit) {
            wasmDiagnosticReportDwarfUnexpectedTag(diagnostics, (U32)tag);
            goto cleanup_cu;
        }

        res = dwarf_srcfiles(cuDie, &files, &fileCount, &error);
        if  (res != DW_DLV_OK) {
            wasmDiagnosticReportDwarfFailure(diagnostics, wasmDiagnosticDwarfFiles);
            goto cleanup_cu;
        }

        appendSubprogramDebugLines(
            debug,
            cuDie,
            files,
            fileCount,
            &debugLines,
            diagnostics
        );

        res = dwarf_srclines_b(cuDie, &version, &tableCount, &lineContext, &error);
        if (res != DW_DLV_OK) {
            if (res == DW_DLV_ERROR) {
                wasmDiagnosticReportDwarfFailure(diagnostics, wasmDiagnosticDwarfLineContext);
            }
            goto cleanup_cu;
        }

        res = dwarf_srclines_from_linecontext(lineContext, &lines, &lineCount, &error);
        if (res != DW_DLV_OK) {
            if (res == DW_DLV_ERROR) {
                wasmDiagnosticReportDwarfFailure(diagnostics, wasmDiagnosticDwarfLines);
            }
            goto cleanup_cu;
        }

        for (; lineIndex < lineCount; lineIndex++) {
            Dwarf_Line line = lines[lineIndex];
            WasmDebugLine debugLine = {0, NULL, 0};
            char* path = NULL;

            /* Line address */
            res = dwarf_lineaddr(line, &debugLine.address, &error);
            if (res != DW_DLV_OK) {
                if (res == DW_DLV_ERROR) {
                    wasmDiagnosticReportDwarfFailure(diagnostics, wasmDiagnosticDwarfLineAddress);
                }
                goto cleanup_cu;
            }

            /* TODO: why the big jump? */
            if (debugLine.address >= 0xffffffff) {
                continue;
            }

            /* Line source / path */
            res = dwarf_linesrc(line, &path, &error);
            if (res != DW_DLV_OK) {
                if (res == DW_DLV_ERROR) {
                    wasmDiagnosticReportDwarfFailure(diagnostics, wasmDiagnosticDwarfLineSource);
                }
                goto cleanup_cu;
            }
            debugLine.path = strdup(path);
            dwarf_dealloc(debug, path, DW_DLA_STRING);
            path = NULL;
            if (debugLine.path == NULL) {
                wasmDiagnosticReportDwarfFailure(diagnostics, wasmDiagnosticDwarfAllocate);
                goto cleanup_cu;
            }

            /* Line number */
            res = dwarf_lineno(line, &debugLine.number, &error);
            if (res != DW_DLV_OK) {
                if (res == DW_DLV_ERROR) {
                    wasmDiagnosticReportDwarfFailure(diagnostics, wasmDiagnosticDwarfLineNumber);
                }
                free(debugLine.path);
                goto cleanup_cu;
            }

            if (!wasmDebugLinesAppend(&debugLines, debugLine)) {
                wasmDiagnosticReportDwarfFailure(diagnostics, wasmDiagnosticDwarfAllocate);
                free(debugLine.path);
                goto cleanup_cu;
            }
        }

cleanup_cu:
        if (lineContext != NULL) {
            dwarf_srclines_dealloc_b(lineContext);
        }
        if (files != NULL) {
            int fileIndex = 0;
            for (fileIndex = 0; fileIndex < fileCount; fileIndex++) {
                dwarf_dealloc(debug, files[fileIndex], DW_DLA_STRING);
            }
            dwarf_dealloc(debug, files, DW_DLA_LIST);
        }
        if (cuDie != NULL) {
            dwarf_dealloc(debug, cuDie, DW_DLA_DIE);
        }
        if (error != NULL) {
            dwarf_dealloc_error(debug, error);
            error = NULL;
        }
    }

    if (debug != NULL) {
        res = dwarf_object_finish(debug);
        if (res != DW_DLV_OK) {
            if (res == DW_DLV_ERROR) {
                wasmDiagnosticReportDwarfFailure(diagnostics, wasmDiagnosticDwarfFinish);
            }
        }
        debug = NULL;
    }

end:
    if (error != NULL) {
        dwarf_dealloc_error(debug, error);
    }
    if (interface != NULL) {
        free(interface);
    }

    if (debugLines.length > 1) {
        qsort(
            debugLines.debugLines,
            debugLines.length,
            sizeof(WasmDebugLine),
            compareDebugLines
        );
    }

    return debugLines;
}

#else

static
WasmDebugLines
wasmParseDebugInfoInternal(
    WasmDebugSections sections,
    WasmDiagnosticContext* diagnostics
) {
    UNUSED_PARAMETER(sections);
    UNUSED_PARAMETER(diagnostics);
    return emptyWasmDebugLines;
}

#endif /* HAS_LIBDWARF */

WasmDebugLines
wasmParseDebugInfo(
    WasmDebugSections sections,
    WasmDiagnostics reporting
) {
    WasmDiagnosticContext diagnostics = emptyWasmDiagnosticContext;
    diagnostics.diagnostics = reporting;
    return wasmParseDebugInfoInternal(sections, &diagnostics);
}
