#include <string.h>
#include "debug.h"
#include "buffer.h"
#include "str.h"

#if HAS_LIBDWARF

#include <stdio.h>
#include <libdwarf/libdwarf.h>
#include <libdwarf/dwarf.h>

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
    accessSection->name = section.name;
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
    return DW_ENDIAN_LITTLE;
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
    return sections->count;
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
    Dwarf_Die die,
    char** files,
    WasmDebugLines* debugLines
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
        return;
    }

    res = dwarf_hasattr(die, DW_AT_decl_line, &hasDeclLine, &error);
    if (res != DW_DLV_OK || !hasDeclLine) {
        return;
    }

    res = dwarf_hasattr(die, DW_AT_decl_file, &hasDeclFile, &error);
    if (res != DW_DLV_OK || !hasDeclFile) {
        return;
    }

    res = dwarf_attr(die, DW_AT_decl_line, &attr, &error);
    if (res != DW_DLV_OK) {
        return;
    }

    res = dwarf_formudata(attr, &line, &error);
    if (res != DW_DLV_OK) {
        return;
    }

    res = dwarf_attr(die, DW_AT_decl_file, &attr, &error);
    if (res != DW_DLV_OK) {
        return;
    }

    res = dwarf_formudata(attr, &fileIndex, &error);
    if (res != DW_DLV_OK) {
        return;
    }

    {
        WasmDebugLine debugLine = {0, NULL, 0};
        debugLine.address = address;
        debugLine.path = strdup(files[fileIndex - 1]);
        debugLine.number = line;

        if (!wasmDebugLinesPush(debugLines, debugLine)) {
            /* TODO: bubble up error? */
        }
    }
}

static
void
appendSubprogramDebugLines(
    Dwarf_Debug debug,
    Dwarf_Die rootDie,
    char** files,
    WasmDebugLines* debugLines
) {
    int res = DW_DLV_ERROR;
    Dwarf_Die childDie = NULL;
    Dwarf_Error error = NULL;

    res = dwarf_child(rootDie, &childDie, &error);
    switch (res) {
        case DW_DLV_ERROR: {
            fprintf(stderr, "w2c2: failed to get child DIE\n");
            return;
        }
        case DW_DLV_NO_ENTRY:
            return;
    }

    while (true) {
        Dwarf_Half childDieTag = 0;
        Dwarf_Die nextChildDie = NULL;

        res = dwarf_tag(childDie, &childDieTag, &error);
        if (res != DW_DLV_OK) {
            fprintf(stderr, "w2c2: failed to get DIE tag\n");
        }

        if (childDieTag == DW_TAG_subprogram) {
            appendSubprogramDebugLine(childDie, files, debugLines);
        }

        if (childDieTag != DW_TAG_base_type
            && childDieTag != DW_TAG_lexical_block) {

            appendSubprogramDebugLines(debug, childDie, files, debugLines);
        }

        res = dwarf_siblingof(debug, childDie, &nextChildDie, &error);
        dwarf_dealloc(debug, childDie, DW_DLA_DIE);
        childDie = nextChildDie;

        switch (res) {
            case DW_DLV_ERROR: {
                fprintf(stderr, "w2c2: failed to get child sibling DIE\n");
                return;
            }
            case DW_DLV_NO_ENTRY:
                return;
        }
    }
}

WasmDebugLines
wasmParseDebugInfo(
    WasmDebugSections sections
) {
    WasmDebugLines debugLines = emptyWasmDebugLines;
    int res = DW_DLV_ERROR;
    Dwarf_Obj_Access_Interface* interface = NULL;
    Dwarf_Debug debug;
    Dwarf_Error error = NULL;

    interface = (Dwarf_Obj_Access_Interface *)calloc(1, sizeof(Dwarf_Obj_Access_Interface*));
    if (!interface) {
        fprintf(stderr, "w2c2: failed to allocate DWARF interface\n");
        goto end;
    }

    interface->object = &sections;
    interface->methods = &dwarfAccessMethods;

    res = dwarf_object_init(interface, NULL, NULL, &debug, &error);
    if (res != DW_DLV_OK) {
        fprintf(stderr, "w2c2: failed to init DWARF reader\n");
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
            break;
        }

        res = dwarf_siblingof(debug, NULL, &cuDie, &error);
        if (res != DW_DLV_OK) {
            goto free_die;
        }

        res = dwarf_tag(cuDie, &tag, &error);
        if (res != DW_DLV_OK) {
            fprintf(stderr, "w2c2: failed to get DIE tag\n");
            goto free_die;
        }

        if (tag != DW_TAG_compile_unit) {
            fprintf(stderr, "w2c2: unexpected non-compile unit DIE tag: %d\n", tag);
            goto free_die;
        }

        res = dwarf_srcfiles(cuDie, &files, &fileCount, &error);
        if  (res != DW_DLV_OK) {
            fprintf(stderr, "w2c2: failed to get CU DIE files\n");
            goto free_die;
        }

        appendSubprogramDebugLines(debug, cuDie, files, &debugLines);

        res = dwarf_srclines(cuDie, &lines, &lineCount, &error);
        if (res != DW_DLV_OK) {
            fprintf(stderr, "w2c2: failed to get lines\n");
            goto free_files;
        }

        for (; lineIndex < lineCount; lineIndex++) {
            Dwarf_Line line = lines[lineIndex];
            WasmDebugLine debugLine = {0, NULL, 0};
            char* path = NULL;

            /* Line address */
            res = dwarf_lineaddr(line, &debugLine.address, &error);
            if (res != DW_DLV_OK) {
                fprintf(stderr, "w2c2: failed to get line address\n");
                goto loop_end;
            }

            /* TODO: why the big jump? */
            if (debugLine.address >= 0xffffffff) {
                continue;
            }

            /* Line source / path */
            res = dwarf_linesrc(line, &path, &error);
            if (res != DW_DLV_OK) {
                fprintf(stderr, "w2c2: failed to get line source\n");
                goto loop_end;
            }
            debugLine.path = strdup(path);
            dwarf_dealloc(debug, path, DW_DLA_STRING);

            /* Line number */
            res = dwarf_lineno(line, &debugLine.number, &error);
            if (res != DW_DLV_OK) {
                fprintf(stderr, "w2c2: failed to get line number\n");
                goto loop_end;
            }

            if (!wasmDebugLinesPush(&debugLines, debugLine)) {
                goto loop_end;
            }
        }

free_die:
        dwarf_dealloc(debug, cuDie, DW_DLA_DIE);

free_files:
        {
            int fileIndex = 0;
            for (fileIndex = 0; fileIndex < fileCount; fileIndex++) {
                dwarf_dealloc(debug, files[fileIndex], DW_DLA_STRING);
            }
        }
        dwarf_dealloc(debug, files, DW_DLA_LIST);

loop_end:
        dwarf_srclines_dealloc(debug, lines, lineCount);
    }

    res = dwarf_object_finish(debug, &error);
    if (res != DW_DLV_OK) {
        fprintf(stderr, "w2c2: failed to finish DWARF reader\n");
    }

end:
    if (interface != NULL) {
        free(interface);
    }

    qsort(
        debugLines.debugLines,
        debugLines.length,
        sizeof(WasmDebugLine),
        compareDebugLines
    );

    return debugLines;
}

#else

WasmDebugLines
wasmParseDebugInfo(
    WasmDebugSections sections
) {
    return emptyWasmDebugLines;
}

#endif /* HAS_LIBDWARF */

