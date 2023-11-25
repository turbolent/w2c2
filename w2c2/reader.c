#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#include "reader.h"
#include "section.h"
#include "opcode.h"
#include "instruction.h"
#include "datasegment.h"
#include "table.h"
#include "elementsegment.h"
#include "debug.h"
#include "name.h"
#include "sha1.h"

static const U8 wasmMagic[] = {
    0x00, 0x61, 0x73, 0x6D,
    0x01, 0x00, 0x00, 0x00,
};

const char*
wasmModuleReaderErrorMessage(
    const WasmModuleReaderError* error
) {
    switch (error->code) {
        case wasmModuleReaderInvalidMagic:
            return "invalid magic";
        case wasmModuleReaderAllocationFailed:
            return "allocation failed";
        case wasmModuleReaderInvalidSectionID:
            return "invalid section ID";
        case wasmModuleReaderInvalidSectionSize:
            return "invalid section size";
        case wasmModuleReaderIncorrectSectionRead:
            return "invalid section read";
        case wasmModuleReaderInvalidCustomSectionName:
            return "invalid custom section name";
        case wasmModuleReaderDebugSectionAppendFailed:
            return "failed to append debug section";
        case wasmModuleReaderInvalidTypeSectionTypeCount:
            return "invalid type section type count";
        case wasmModuleReaderInvalidFunctionTypeIndicator:
            return "invalid function type indicator";
        case wasmModuleReaderInvalidFunctionTypeParameterCount:
            return "invalid function type parameter count";
        case wasmModuleReaderInvalidFunctionTypeResultCount:
            return "invalid function type result count";
        case wasmModuleReaderInvalidImportSectionImportCount:
            return "invalid import section import count";
        case wasmModuleReaderInvalidImportSectionImportModule:
            return "invalid import section import module";
        case wasmModuleReaderInvalidImportSectionImportName:
            return "invalid import section import name";
        case wasmModuleReaderInvalidImportSectionImportKind:
            return "invalid import section import kind";
        case wasmModuleReaderInvalidImportSectionFunctionTypeIndex:
            return "invalid import section index";
        case wasmModuleReaderInvalidValueType:
            return "invalid value type";
        case wasmModuleReaderInvalidFunctionSectionFunctionCount:
            return "invalid function section function count";
        case wasmModuleReaderInvalidFunctionTypeIndex:
            return "invalid function type index";
        case wasmModuleReaderInvalidCodeSectionFunctionCount:
            return "invalid code section function count";
        case wasmModuleReaderInvalidCodeSectionCodeSize:
            return "invalid code section code size";
        case wasmModuleReaderInvalidCodeSectionLocalsDeclarations:
            return "invalid code section local declarations";
        case wasmModuleReaderInvalidExportSectionExportCount:
            return "invalid export section export count";
        case wasmModuleReaderInvalidExportSectionExportName:
            return "invalid export section export name";
        case wasmModuleReaderInvalidExportSectionExportKind:
            return "invalid export section export kind";
        case wasmModuleReaderInvalidExportSectionExportIndex:
            return "invalid export section export index";
        case wasmModuleReaderInvalidGlobalSectionGlobalCount:
            return "invalid global section global count";
        case wasmModuleReaderInvalidGlobalSectionMutabilityIndicator:
            return "invalid global section mutability indicator";
        case wasmModuleReaderInvalidGlobalSectionInitExpression:
            return "invalid global section init expression";
        case wasmModuleReaderInvalidMemorySectionMemoryCount:
            return "invalid memory section memory count";
        case wasmModuleReaderInvalidLimitKind:
            return "invalid limit kind";
        case wasmModuleReaderInvalidLimitMinimum:
            return "invalid limit minimum";
        case wasmModuleReaderInvalidLimitMaximum:
            return "invalid limit maximum";
        case wasmModuleReaderInvalidDataSectionDataSegmentCount:
            return "invalid data section data segment count";
        case wasmModuleReaderInvalidDataSectionKind:
            return "invalid data section kind";
        case wasmModuleReaderInvalidDataSectionMemoryIndex:
            return "invalid data section memory index";
        case wasmModuleReaderInvalidDataSectionOffsetExpression:
            return "invalid data section offset expression";
        case wasmModuleReaderInvalidDataSectionBytes:
            return "invalid data section bytes";
        case wasmModuleReaderInvalidDataCountSectionDataCount:
            return "invalid data count section data count";
        case wasmModuleReaderInvalidTableSectionTableCount:
            return "invalid table section table count";
        case wasmModuleReaderInvalidTableSectionTableType:
            return "invalid table section table type";
        case wasmModuleReaderInvalidElementSectionElementSegmentCount:
            return "invalid element section element segment count";
        case wasmModuleReaderInvalidElementSectionTableIndex:
            return "invalid element section table index";
        case wasmModuleReaderInvalidElementSectionOffsetExpression:
            return "invalid element section offset expression";
        case wasmModuleReaderInvalidElementSectionFunctionIndexCount:
            return "invalid element section function index count";
        case wasmModuleReaderInvalidElementSectionFunctionIndex:
            return "invalid element section function index";
        case wasmModuleReaderInvalidStartSectionFunctionIndex:
            return "invalid start section function index";
        case wasmModuleReaderInvalidNameSectionFunctionNameCount:
            return "invalid name section function name count";
        case wasmModuleReaderInvalidNameSectionFunctionIndex:
            return "invalid name section function index";
        case wasmModuleReaderInvalidNameSectionFunctionName:
            return "invalid name section function name";
        default:
            return "unknown";
    }
}

static
void
wasmModuleReadMagic(
    WasmModuleReader* reader,
    WasmModuleReaderError** error
) {
    if (!bufferReadEqual(
        &reader->buffer,
        wasmMagic,
        sizeof wasmMagic
    )) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidMagic
        };
        *error = &wasmModuleReaderError;
        return;
    }
    *error = NULL;
}

static
WasmValueType
wasmModuleReadValueType(
    WasmModuleReader* reader,
    WasmModuleReaderError** error
) {
    WasmValueType valueType = 0;

    if (!wasmReadValueType(&reader->buffer, &valueType)) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidValueType
        };
        *error = &wasmModuleReaderError;
        return 0;
    }
    *error = NULL;
    return valueType;
}

static
WasmValueType*
wasmReadValueTypes(
    WasmModuleReader* reader,
    const U32 count,
    WasmModuleReaderError** error
) {
    /* Allocate value type array */
    WasmValueType* valueTypes = calloc(count, sizeof(WasmValueType));
    if (valueTypes == NULL) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderAllocationFailed
        };
        *error = &wasmModuleReaderError;
        return NULL;
    }

    /* Read value types */
    {
        U32 valueTypeIndex = 0;
        for (; valueTypeIndex < count; valueTypeIndex++) {
            const WasmValueType valueType = wasmModuleReadValueType(reader, error);
            if (*error != NULL) {
                goto fail;
            }
            valueTypes[valueTypeIndex] = valueType;
        }
    }

    *error = NULL;
    return valueTypes;

fail:
    free(valueTypes);
    return NULL;
}

/* wasmFunctionTypeIndicator is the byte used to indicate a function type in the WASM binary */
const U32 wasmFunctionTypeIndicator = 0x60;

static
void
wasmReadFunctionType(
    WasmModuleReader* reader,
    WasmFunctionType* result,
    WasmModuleReaderError** error
) {
    U8 typeIndicator = 0;
    U32 parameterCount = 0;
    WasmValueType* parameterTypes = NULL;
    U32 resultCount = 0;
    WasmValueType* resultTypes = NULL;

    /* Read type indicator */
    if (
        !bufferReadByte(&reader->buffer, &typeIndicator)
        || typeIndicator != wasmFunctionTypeIndicator) {

        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidFunctionTypeIndicator
        };
        *error = &wasmModuleReaderError;
        return;
    }

    /* Read parameter count */
    if (leb128ReadU32(&reader->buffer, &parameterCount) == 0) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidFunctionTypeParameterCount
        };
        *error = &wasmModuleReaderError;
        return;
    }

    /* Read parameter types */
    parameterTypes = wasmReadValueTypes(reader, parameterCount, error);
    if (*error != NULL) {
        return;
    }

    /* Read result count */
    if (leb128ReadU32(&reader->buffer, &resultCount) == 0) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidFunctionTypeResultCount
        };
        *error = &wasmModuleReaderError;
        goto fail;
    }

    /* Read result types */
    resultTypes = wasmReadValueTypes(reader, resultCount, error);
    if (*error != NULL) {
        goto fail;
    }

    *error = NULL;

    result->parameterCount = parameterCount;
    result->parameterTypes = parameterTypes;
    result->resultCount = resultCount;
    result->resultTypes = resultTypes;

    return;

fail:
    free(parameterTypes);
}

static
bool
WARN_UNUSED_RESULT
wasmReadName(
    Buffer* buffer,
    char** result
) {
    char* name = NULL;

    U32 length = 0;
    MUST (leb128ReadU32(buffer, &length) > 0)
    MUST (length <= buffer->length)

    name = calloc(length + 1, 1);
    MUST (name != NULL)

    strncpy(
        name,
        (char*) buffer->data,
        length
    );

    name[length] = '\0';

    bufferSkipUnchecked(buffer, length);

    *result = name;

    return true;
}

typedef void (* WasmSectionReader)(
    WasmModuleReader* reader,
    U32 sectionSize,
    WasmModuleReaderError** error
);

static const char* wasmDebugSectionNamePrefix = ".debug_";
static const char* wasmNameSectionName = "name";

typedef struct WasmFunctionNameEntry {
    char* name;
    U32 functionIndex;
} WasmFunctionNameEntry;

static
int
wasmFunctionNameEntryCompareNames(
    const void* a,
    const void* b
) {
    const WasmFunctionNameEntry* entryA = a;
    const WasmFunctionNameEntry* entryB = b;
    return strcmp(entryA->name, entryB->name);
}

static
void
wasmFunctionNamesRemoveDuplicates(
    const WasmNames* functionNames,
    WasmModuleReaderError** error
) {
    const size_t functionNameCount = functionNames->length;
    U32 functionNameIndex = 0;

    WasmFunctionNameEntry* entries = calloc(functionNameCount, sizeof(WasmFunctionNameEntry));
    if (!entries) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderAllocationFailed
        };
        *error = &wasmModuleReaderError;
        return;
    }

    for (; functionNameIndex < functionNameCount; functionNameIndex++) {
        WasmFunctionNameEntry *entry = &entries[functionNameIndex];
        entry->functionIndex = functionNameIndex;
        entry->name = functionNames->names[functionNameIndex];
    }

    qsort(
        entries,
        functionNameCount,
        sizeof(WasmFunctionNameEntry),
        wasmFunctionNameEntryCompareNames
    );

    for (functionNameIndex = 1; functionNameIndex < functionNameCount; functionNameIndex++) {
        const WasmFunctionNameEntry previous = entries[functionNameIndex - 1];
        const WasmFunctionNameEntry current = entries[functionNameIndex];

        if (strcmp(previous.name, current.name) == 0) {
            fprintf(
                stderr,
                "w2c2: ignoring duplicate function name %s used by functions %u and %u\n",
                previous.name,
                previous.functionIndex,
                current.functionIndex
            );

            functionNames->names[previous.functionIndex] = NULL;
            functionNames->names[current.functionIndex] = NULL;
        }
    }
}

static
void
wasmReadNameSection(
    WasmModuleReader* reader,
    const U32 sectionSize,
    WasmModuleReaderError** error
) {
    const U8* end = reader->buffer.data + sectionSize;

    while (reader->buffer.data < end) {
        U8 subsectionID = 0;
        U32 subsectionSize = 0;
        U32 functionNameCount = 0;

        /* Read subsection ID */
        if (!bufferReadByte(&reader->buffer, &subsectionID)) {
            static WasmModuleReaderError wasmModuleReaderError = {
                wasmModuleReaderInvalidGlobalSectionMutabilityIndicator
            };
            *error = &wasmModuleReaderError;
            return;
        }

        /* Read subsection size */
        if (leb128ReadU32(&reader->buffer, &subsectionSize) == 0) {
            static WasmModuleReaderError wasmModuleReaderError = {
                wasmModuleReaderInvalidSectionSize
            };
            *error = &wasmModuleReaderError;
            return;
        }

        /* Read function names */
        if (subsectionID == wasmNameSubsectionIDFunctionNames) {
            const size_t functionImportCount = reader->module->functionImports.length;
            const U32 functionCount = assertSizeU32(functionImportCount) + reader->module->functions.count;

            U32 functionNameIndex = 0;

            /* Read function name count */
            if (leb128ReadU32(&reader->buffer, &functionNameCount) == 0) {
                static WasmModuleReaderError wasmModuleReaderError = {
                    wasmModuleReaderInvalidNameSectionFunctionNameCount
                };
                *error = &wasmModuleReaderError;
                return;
            }

            /* Allocate name entries for *all* functions */
            if (!wasmNamesEnsureCapacity(
                &reader->module->functionNames,
                /* NOTE: allocate name entries for *all* functions,
                 * not just for functions with names (functionNameCount)
                 */
                functionCount
            )) {
                static WasmModuleReaderError wasmModuleReaderError = {
                    wasmModuleReaderAllocationFailed
                };
                *error = &wasmModuleReaderError;
                return;
            }
            reader->module->functionNames.length = functionCount;

            /* Read function names */
            for (; functionNameIndex < functionNameCount; functionNameIndex++) {
                U32 functionIndex = 0;
                char* functionName = NULL;

                /* Read function index */
                if (leb128ReadU32(&reader->buffer, &functionIndex) == 0) {
                    static WasmModuleReaderError wasmModuleReaderError = {
                        wasmModuleReaderInvalidNameSectionFunctionIndex
                    };
                    *error = &wasmModuleReaderError;
                    return;
                }

                if (functionIndex >= functionCount) {
                    static WasmModuleReaderError wasmModuleReaderError = {
                        wasmModuleReaderInvalidNameSectionFunctionIndex
                    };
                    *error = &wasmModuleReaderError;
                    return;
                }

                /* Read function name */
                if (!wasmReadName(&reader->buffer, &functionName)) {
                    static WasmModuleReaderError wasmModuleReaderError = {
                        wasmModuleReaderInvalidNameSectionFunctionName
                    };
                    *error = &wasmModuleReaderError;
                    return;
                }

                reader->module->functionNames.names[functionIndex] = functionName;
            }

            /* Remove duplicates */
            wasmFunctionNamesRemoveDuplicates(&reader->module->functionNames, error);
            if (*error != NULL) {
                return;
            }
        } else {
            fprintf(
                stderr,
                "w2c2: skipping unsupported %s (size %d)\n",
                wasmNameSubsectionIDDescription(subsectionID),
                subsectionSize
            );
            bufferSkip(&reader->buffer, subsectionSize);
        }
    }
}

static
void
wasmReadCustomSection(
    WasmModuleReader* reader,
    U32 sectionSize,
    WasmModuleReaderError** error
) {
    char* name = NULL;
    const U8* start = reader->buffer.data;
    const U8* end = NULL;

    /* Read name */
    if (!wasmReadName(&reader->buffer, &name)) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidCustomSectionName
        };
        *error = &wasmModuleReaderError;
        return;
    }

    end = reader->buffer.data;

    sectionSize -= (U32) (end - start);

    if (strncmp(name, wasmDebugSectionNamePrefix, strlen(wasmDebugSectionNamePrefix)) == 0) {
        WasmDebugSection section;
        section.name = name;
        section.buffer.data = reader->buffer.data;
        section.buffer.length = sectionSize;

        if (!wasmDebugSectionsAppend(&reader->module->debugSections, section)) {
            static WasmModuleReaderError wasmModuleReaderError = {
                wasmModuleReaderDebugSectionAppendFailed
            };
            *error = &wasmModuleReaderError;
            goto fail;
        }

        bufferSkip(&reader->buffer, sectionSize);

    } else if (reader->debug && strcmp(name, wasmNameSectionName) == 0) {
        wasmReadNameSection(reader, sectionSize, error);
        if (*error != NULL) {
            goto fail;
        }
        free(name);
    } else {
        fprintf(stderr, "w2c2: skipping custom section '%s' (size %u)\n", name, sectionSize);
        bufferSkip(&reader->buffer, sectionSize);
        free(name);
    }

    *error = NULL;
    return;

fail:
    free(name);
}

static
void
wasmReadTypeSection(
    WasmModuleReader* reader,
    U32 UNUSED(sectionSize),
    WasmModuleReaderError** error
) {
    U32 typeCount = 0;
    U32 typeIndex = 0;
    WasmFunctionType* functionTypes = NULL;

    /* Read type count */
    if (leb128ReadU32(&reader->buffer, &typeCount) == 0) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidTypeSectionTypeCount
        };
        *error = &wasmModuleReaderError;
        return;
    }

    /* Allocate function type array */
    functionTypes = calloc(typeCount, sizeof(WasmFunctionType));
    if (functionTypes == NULL) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderAllocationFailed
        };
        *error = &wasmModuleReaderError;
        return;
    }

    /* Read function types */
    for (; typeIndex < typeCount; typeIndex++) {
        WasmFunctionType functionType = wasmEmptyFunctionType;
        wasmReadFunctionType(reader, &functionType, error);
        if (*error != NULL) {
            goto fail;
        }
        functionTypes[typeIndex] = functionType;
    }

    *error = NULL;

    reader->module->functionTypes.count = typeCount;
    reader->module->functionTypes.functionTypes = functionTypes;

    return;

fail:
    free(functionTypes);
}

static
WasmGlobalType
wasmReadGlobalType(
    WasmModuleReader* reader,
    WasmModuleReaderError** error
) {
    WasmGlobalType result = {0, false};

    U8 mutabilityIndicator = 0;

    /* Read value type */
    const WasmValueType valueType = wasmModuleReadValueType(reader, error);
    if (*error != NULL) {
        return result;
    }

    /* Read mutability */
    if (!bufferReadByte(&reader->buffer, &mutabilityIndicator)
        || mutabilityIndicator > 1) {

        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidGlobalSectionMutabilityIndicator
        };
        *error = &wasmModuleReaderError;
        return result;
    }

    *error = NULL;

    result.valueType = valueType;
    result.mutable = mutabilityIndicator == 0x1;

    return result;
}

static
void
wasmReadFunctionImport(
    WasmModuleReader* reader,
    char* module,
    char* name,
    WasmModuleReaderError** error
) {
    WasmFunctionImport import = wasmEmptyFunctionImport;

    /* Read function type index */
    U32 functionTypeIndex = 0;
    if (leb128ReadU32(&reader->buffer, &functionTypeIndex) == 0) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidImportSectionFunctionTypeIndex
        };
        *error = &wasmModuleReaderError;
        return;
    }

    import.module = module;
    import.name = name;
    import.functionTypeIndex = functionTypeIndex;

    if (!wasmFunctionImportsAppend(&reader->module->functionImports, import)) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderAllocationFailed
        };
        *error = &wasmModuleReaderError;
        return;
    }

    *error = NULL;
}

static
void
wasmReadGlobalImport(
    WasmModuleReader* reader,
    char* module,
    char* name,
    WasmModuleReaderError** error
) {
    WasmGlobalImport import = wasmEmptyGlobalImport;

    /* Read global type */
    const WasmGlobalType globalType = wasmReadGlobalType(reader, error);
    if (*error != NULL) {
        return;
    }

    import.module = module;
    import.name = name;
    import.globalType = globalType;

    if (!wasmGlobalImportsAppend(&reader->module->globalImports, import)) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderAllocationFailed
        };
        *error = &wasmModuleReaderError;
        return;
    }

    *error = NULL;
}

static
void
wasmReadLimits(
    WasmModuleReader* reader,
    U32* min,
    U32* max,
    bool *shared,
    WasmModuleReaderError** error
) {
    U8 kindIndicator = 0;

    /* Read limit kind */
    if (!bufferReadByte(&reader->buffer, &kindIndicator)) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidLimitKind
        };
        *error = &wasmModuleReaderError;
        return;
    }

    /* Read min */
    if (leb128ReadU32(&reader->buffer, min) == 0) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidLimitMinimum
        };
        *error = &wasmModuleReaderError;
        return;
    }

    switch (kindIndicator) {
        case 0x0: {
            *max = 0;
            *shared = false;
            break;
        }
        case 0x1: {
            /* Read max */
            if (leb128ReadU32(&reader->buffer, max) == 0) {
                static WasmModuleReaderError wasmModuleReaderError = {
                    wasmModuleReaderInvalidLimitMaximum
                };
                *error = &wasmModuleReaderError;
                return;
            }
            *shared = false;
            break;
        }
        case 0x3: {
            /* Read max */
            if (leb128ReadU32(&reader->buffer, max) == 0) {
                static WasmModuleReaderError wasmModuleReaderError = {
                    wasmModuleReaderInvalidLimitMaximum
                };
                *error = &wasmModuleReaderError;
                return;
            }
            *shared = true;
            break;
        }
        default: {
            static WasmModuleReaderError wasmModuleReaderError = {
                wasmModuleReaderInvalidLimitKind
            };
            *error = &wasmModuleReaderError;
            return;
        }
    }

    *error = NULL;
}

static
void
wasmReadMemoryType(
    WasmModuleReader* reader,
    U32* min,
    U32* max,
    bool* shared,
    WasmModuleReaderError** error
) {
    wasmReadLimits(reader, min, max, shared, error);
    if (*error != NULL) {
        return;
    }
    if (*max == 0) {
        *max = UINT32_MAX / WASM_PAGE_SIZE;
    }
}

static
void
wasmReadMemoryImport(
    WasmModuleReader* reader,
    char* module,
    char* name,
    WasmModuleReaderError** error
) {
    WasmMemoryImport import = wasmEmptyMemoryImport;

    import.module = module;
    import.name = name;

    wasmReadMemoryType(reader, &import.min, &import.max, &import.shared, error);
    if (*error != NULL) {
        return;
    }

    if (!wasmMemoryImportsAppend(&reader->module->memoryImports, import)) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderAllocationFailed
        };
        *error = &wasmModuleReaderError;
        return;
    }

    *error = NULL;
}

static
void
wasmReadTableType(
    WasmModuleReader* reader,
    U32* min,
    U32* max,
    bool* shared,
    WasmModuleReaderError** error
) {
    U8 tableType = 0;

    /* Read table type */
    if (
        !bufferReadByte(&reader->buffer, &tableType)
        || tableType != wasmTableTypeFuncRef
        ) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidTableSectionTableType
        };
        *error = &wasmModuleReaderError;
        return;
    }

    wasmReadLimits(reader, min, max, shared, error);
    if (*error != NULL) {
        return;
    }
    if (*max == 0) {
        *max = UINT32_MAX;
    }

    *error = NULL;
}

static
void
wasmReadTableImport(
    WasmModuleReader* reader,
    char* module,
    char* name,
    WasmModuleReaderError** error
) {
    WasmTableImport import = wasmEmptyTableImport;

    import.module = module;
    import.name = name;

    wasmReadTableType(reader, &import.min, &import.max, &import.shared, error);
    if (*error != NULL) {
        return;
    }

    if (!wasmTableImportsAppend(&reader->module->tableImports, import)) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderAllocationFailed
        };
        *error = &wasmModuleReaderError;
        return;
    }

    *error = NULL;
}

static
void
wasmReadImport(
    WasmModuleReader* reader,
    WasmModuleReaderError** error
) {
    char* module = NULL;
    char* name = NULL;
    U8 kindIndicator = 0;

    /* Read module */
    if (!wasmReadName(&reader->buffer, &module)) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidImportSectionImportModule
        };
        *error = &wasmModuleReaderError;
        goto fail;
    }

    /* Read name */
    if (!wasmReadName(&reader->buffer, &name)) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidImportSectionImportName
        };
        *error = &wasmModuleReaderError;
        goto fail;
    }

    /* Read import kind */
    if (!bufferReadByte(&reader->buffer, &kindIndicator)
        || kindIndicator >= wasmImportKind_count) {

        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidImportSectionImportKind
        };
        *error = &wasmModuleReaderError;
        goto fail;
    }

    switch (kindIndicator) {
        case wasmImportKindFunction: {
            wasmReadFunctionImport(reader, module, name, error);
            if (*error != NULL) {
                goto fail;
            }
            break;
        }
        case wasmImportKindGlobal: {
            wasmReadGlobalImport(reader, module, name, error);
            if (*error != NULL) {
                goto fail;
            }
            break;
        }
        case wasmImportKindMemory: {
            wasmReadMemoryImport(reader, module, name, error);
            if (*error != NULL) {
                goto fail;
            }
            break;
        }
        case wasmImportKindTable: {
            wasmReadTableImport(reader, module, name, error);
            if (*error != NULL) {
                goto fail;
            }
            break;
        }
        default: {
            static WasmModuleReaderError wasmModuleReaderError = {
                wasmModuleReaderInvalidImportSectionImportKind
            };
            *error = &wasmModuleReaderError;
            goto fail;
        }
    }

    *error = NULL;
    return;

fail:
    free(module);
    free(name);
}

static
void
wasmReadImportSection(
    WasmModuleReader* reader,
    U32 UNUSED(sectionSize),
    WasmModuleReaderError** error
) {
    U32 importCount = 0;

    /* Read import count */
    if (leb128ReadU32(&reader->buffer, &importCount) == 0) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidTypeSectionTypeCount
        };
        *error = &wasmModuleReaderError;
        return;
    }

    /* Read imports */
    {
        U32 importIndex = 0;
        for (; importIndex < importCount; importIndex++) {
            wasmReadImport(reader, error);
            if (*error != NULL) {
                return;
            }
        }
    }

    *error = NULL;
}

static
void
wasmReadFunctionSection(
    WasmModuleReader* reader,
    U32 UNUSED(sectionSize),
    WasmModuleReaderError** error
) {
    U32 functionCount = 0;
    U32 functionIndex = 0;
    WasmFunction* functions = NULL;

    /* Read function count */
    if (leb128ReadU32(&reader->buffer, &functionCount) == 0) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidFunctionSectionFunctionCount
        };
        *error = &wasmModuleReaderError;
        return;
    }

    /* Allocate function array */
    functions = calloc(functionCount, sizeof(WasmFunction));
    if (functions == NULL) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderAllocationFailed
        };
        *error = &wasmModuleReaderError;
        return;
    }

    /* Read function type indices */
    for (; functionIndex < functionCount; functionIndex++) {
        WasmFunction function = wasmEmptyFunction;

        /* Read function type index */
        U32 functionTypeIndex = 0;
        if (leb128ReadU32(&reader->buffer, &functionTypeIndex) == 0) {
            static WasmModuleReaderError wasmModuleReaderError = {
                wasmModuleReaderInvalidFunctionTypeIndex
            };
            *error = &wasmModuleReaderError;
            goto fail;
        }

        /* Check function type index does not exceed function type count */
        if (functionTypeIndex >= reader->module->functionTypes.count) {
            static WasmModuleReaderError wasmModuleReaderError = {
                wasmModuleReaderInvalidFunctionTypeIndex
            };
            *error = &wasmModuleReaderError;
            goto fail;
        }

        function.functionTypeIndex = functionTypeIndex;
        functions[functionIndex] = function;
    }

    *error = NULL;

    reader->module->functions.count = functionCount;
    reader->module->functions.functions = functions;

    return;

fail:
    free(functions);
}

static
bool
WARN_UNUSED_RESULT
wasmReadConstantExpr(
    Buffer* buffer
) {
    WasmOpcode opcode;
    MUST (wasmOpcodeRead(buffer, &opcode))
    switch (opcode) {
        case wasmOpcodeI32Const:
        case wasmOpcodeI64Const:
        case wasmOpcodeF32Const:
        case wasmOpcodeF64Const: {
            WasmConstInstruction instruction;
            MUST (wasmConstInstructionRead(buffer, opcode, &instruction))
            break;
        }
        case wasmOpcodeGlobalGet: {
            WasmGlobalInstruction instruction;
            MUST (wasmGlobalInstructionRead(buffer, &instruction))
            break;
        }
        case wasmOpcodeEnd:
            return true;
        default:
            return false;
    }

    /* Read end opcode */
    MUST (wasmOpcodeRead(buffer, &opcode))
    MUST (opcode == wasmOpcodeEnd)

    return true;
}

static
void
wasmReadMemorySection(
    WasmModuleReader* reader,
    U32 UNUSED(sectionSize),
    WasmModuleReaderError** error
) {
    U32 memoryCount = 0;
    U32 memoryIndex = 0;
    WasmMemory* memories = NULL;

    /* Read memory count */
    if (leb128ReadU32(&reader->buffer, &memoryCount) == 0) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidMemorySectionMemoryCount
        };
        *error = &wasmModuleReaderError;
        return;
    }

    /* Allocate memories array */
    memories = calloc(memoryCount, sizeof(WasmMemory));
    if (memories == NULL) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderAllocationFailed
        };
        *error = &wasmModuleReaderError;
        return;
    }

    /* Read memories */
    for (; memoryIndex < memoryCount; memoryIndex++) {
        WasmMemory memory = wasmEmptyMemory;
        wasmReadMemoryType(reader, &memory.min, &memory.max, &memory.shared, error);
        if (*error != NULL) {
            goto fail;
        }
        memories[memoryIndex] = memory;
    }

    *error = NULL;

    reader->module->memories.count = memoryCount;
    reader->module->memories.memories = memories;

    return;

fail:
    free(memories);
}

static
void
wasmReadGlobal(
    WasmModuleReader* reader,
    WasmGlobal* result,
    WasmModuleReaderError** error
) {
    Buffer init;

    /* Read global type */
    const WasmGlobalType type = wasmReadGlobalType(reader, error);
    if (*error != NULL) {
        return;
    }

    /* Read init expression */
    init = reader->buffer;
    if (!wasmReadConstantExpr(&reader->buffer)) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidGlobalSectionInitExpression
        };
        *error = &wasmModuleReaderError;
        return;
    }
    init.length -= reader->buffer.length;

    *error = NULL;

    result->type = type;
    result->init = init;
}

static
void
wasmReadGlobalSection(
    WasmModuleReader* reader,
    U32 UNUSED(sectionSize),
    WasmModuleReaderError** error
) {
    U32 globalCount = 0;
    U32 globalIndex = 0;
    WasmGlobal* globals = NULL;

    /* Read global count */
    if (leb128ReadU32(&reader->buffer, &globalCount) == 0) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidGlobalSectionGlobalCount
        };
        *error = &wasmModuleReaderError;
        return;
    }

    /* Allocate globals array */
    globals = calloc(globalCount, sizeof(WasmGlobal));
    if (globals == NULL) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderAllocationFailed
        };
        *error = &wasmModuleReaderError;
        return;
    }

    /* Read globals */
    for (; globalIndex < globalCount; globalIndex++) {
        WasmGlobal global = wasmEmptyGlobal;
        wasmReadGlobal(reader, &global, error);
        if (*error != NULL) {
            goto fail;
        }
        globals[globalIndex] = global;
    }

    *error = NULL;

    reader->module->globals.count = globalCount;
    reader->module->globals.globals = globals;

    return;

fail:
    free(globals);
}

static
void
wasmReadExport(
    WasmModuleReader* reader,
    WasmExport* result,
    WasmModuleReaderError** error
) {
    char* name = NULL;
    U8 kindIndicator = 0;
    U32 index = 0;

    /* Read name */
    if (!wasmReadName(&reader->buffer, &name)) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidExportSectionExportName
        };
        *error = &wasmModuleReaderError;
        return;
    }

    /* Read export kind */
    if (!bufferReadByte(&reader->buffer, &kindIndicator)
        || kindIndicator >= wasmExportKind_count) {

        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidExportSectionExportKind
        };
        *error = &wasmModuleReaderError;
        goto fail;
    }

    /* Read export index */
    if (leb128ReadU32(&reader->buffer, &index) == 0) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidExportSectionExportIndex
        };
        *error = &wasmModuleReaderError;
        goto fail;
    }

    *error = NULL;

    result->name = name;
    result->kind = kindIndicator;
    result->index = index;

    return;

fail:
    free(name);
}

static
void
wasmReadExportSection(
    WasmModuleReader* reader,
    U32 UNUSED(sectionSize),
    WasmModuleReaderError** error
) {
    U32 exportCount = 0;
    WasmExport* exports = NULL;

    /* Read export count */
    if (leb128ReadU32(&reader->buffer, &exportCount) == 0) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidExportSectionExportCount
        };
        *error = &wasmModuleReaderError;
        return;
    }

    /* Allocate export array */
    exports = calloc(exportCount, sizeof(WasmExport));
    if (exports == NULL) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderAllocationFailed
        };
        *error = &wasmModuleReaderError;
        return;
    }

    /* Read exports */
    {
        const size_t functionImportCount = reader->module->functionImports.length;
        WasmFunctions functions = reader->module->functions;
        const U32 functionCount = assertSizeU32(functionImportCount) + functions.count;

        U32 exportIndex = 0;
        for (; exportIndex < exportCount; exportIndex++) {
            WasmExport export = wasmEmptyExport;
            wasmReadExport(reader, &export, error);
            if (*error != NULL) {
                goto fail;
            }
            exports[exportIndex] = export;

            if (export.kind == wasmExportKindFunction) {
                if (export.index >= functionCount) {
                    static WasmModuleReaderError wasmModuleReaderError = {
                        wasmModuleReaderInvalidExportSectionExportIndex
                    };
                    *error = &wasmModuleReaderError;
                    goto fail;
                }

                if (export.index >= functionImportCount) {
                    size_t functionIndex = export.index - functionImportCount;
                    functions.functions[functionIndex].exportName = export.name;
                }
            }
        }
    }

    *error = NULL;

    reader->module->exports.count = exportCount;
    reader->module->exports.exports = exports;

    return;

fail:
    free(exports);
}

static
bool
WARN_UNUSED_RESULT
wasmReadCodeLocalsDeclarations(
    WasmModuleReader* reader,
    WasmLocalsDeclarations* result
) {
    WasmLocalsDeclaration* declarations = NULL;
    U32 declarationCount = 0;

    MUST (leb128ReadU32(&reader->buffer, &declarationCount) > 0)

    if (declarationCount > 0) {
        declarations = calloc(declarationCount, sizeof(WasmLocalsDeclaration));
        MUST (declarations != NULL)

        {
            U32 declarationIndex = 0;
            for (; declarationIndex < declarationCount; declarationIndex++) {
                WasmLocalsDeclaration declaration = {0, 0};

                if (leb128ReadU32(&reader->buffer, &declaration.count) <= 0) {
                    goto fail;
                }

                if (!wasmReadValueType(&reader->buffer, &declaration.type)) {
                    goto fail;
                }

                declarations[declarationIndex] = declaration;
            }
        }
    }

    result->declarations = declarations;
    result->declarationCount = declarationCount;

    return true;

fail:
    free(declarations);
    return false;
}

static
void
wasmReadCodeSection(
    WasmModuleReader* reader,
    U32 UNUSED(sectionSize),
    WasmModuleReaderError** error
) {
    U32 functionCount = 0;
    U32 functionIndex = 0;

    const size_t codeStart = reader->module->length - reader->buffer.length;

    /* Read function count */
    if (leb128ReadU32(&reader->buffer, &functionCount) == 0) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidCodeSectionFunctionCount
        };
        *error = &wasmModuleReaderError;
        return;
    }

    /* Check function count matches */
    if (functionCount != reader->module->functions.count) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidCodeSectionFunctionCount
        };
        *error = &wasmModuleReaderError;
        return;
    }

    /* Read function codes */
    for (; functionIndex < functionCount; functionIndex++) {
        WasmFunction* function = &reader->module->functions.functions[functionIndex];

        /* Read code size */
        U32 codeSize = 0;
        if (leb128ReadU32(&reader->buffer, &codeSize) == 0) {
            static WasmModuleReaderError wasmModuleReaderError = {
                wasmModuleReaderInvalidCodeSectionCodeSize
            };
            *error = &wasmModuleReaderError;
            return;
        }

        /* Check code size */
        if (codeSize > reader->buffer.length) {
            static WasmModuleReaderError wasmModuleReaderError = {
                wasmModuleReaderInvalidCodeSectionCodeSize
            };
            *error = &wasmModuleReaderError;
            return;
        }

        /* Read local declarations */
        {
            const U8* localsDeclarationsOffset = reader->buffer.data;

            SHA1(localsDeclarationsOffset, codeSize, function->hash);

            if (!wasmReadCodeLocalsDeclarations(reader, &function->localsDeclarations)) {
                static WasmModuleReaderError wasmModuleReaderError = {
                    wasmModuleReaderInvalidCodeSectionLocalsDeclarations
                };
                *error = &wasmModuleReaderError;
                return;
            }

            function->start = reader->module->length - reader->buffer.length - codeStart;
            function->code.data = reader->buffer.data;
            codeSize -= (U32) (reader->buffer.data - localsDeclarationsOffset);
            function->code.length = codeSize;

            /* Skip unchecked, as buffer length was already checked above */
            bufferSkipUnchecked(&reader->buffer, codeSize);
        }
    }

    *error = NULL;
}

static
bool
WARN_UNUSED_RESULT
wasmReadBytes(
    Buffer* buffer,
    Buffer* result
) {
    U8* bytes = NULL;

    U32 length = 0;
    MUST (leb128ReadU32(buffer, &length) > 0)
    MUST (length <= buffer->length)

    bytes = calloc(length, 1);
    MUST (bytes != NULL)

    memcpy(
        bytes,
        (U8*) buffer->data,
        length
    );

    bufferSkipUnchecked(buffer, length);

    result->data = bytes;
    result->length = length;

    return true;
}

static
void
wasmReadDataSegment(
    WasmModuleReader* reader,
    WasmDataSegment* result,
    WasmModuleReaderError** error
) {
    U8 kind = 0;
    bool readMemoryIndex = false;
    bool readOffsetExpression = false;
    U32 memoryIndex = 0;
    Buffer offset = {NULL, 0};
    Buffer bytes = {NULL, 0};

    if (!bufferReadByte(&reader->buffer, &kind)) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidDataSectionKind
        };
        *error = &wasmModuleReaderError;
        return;
    }

    switch (kind) {
        case 0x0: {
            readMemoryIndex = false;
            readOffsetExpression = true;
            break;
        }
        case 0x1:
            readMemoryIndex = false;
            readOffsetExpression = false;
            break;
        case 0x2:
            readMemoryIndex = true;
            readOffsetExpression = true;
            break;
        default: {
            static WasmModuleReaderError wasmModuleReaderError = {
                wasmModuleReaderInvalidDataSectionKind
            };
            *error = &wasmModuleReaderError;
            return;
        }
    }

    /* Read memory index */
    if (readMemoryIndex) {
        if (leb128ReadU32(&reader->buffer, &memoryIndex) == 0) {
            static WasmModuleReaderError wasmModuleReaderError = {
                wasmModuleReaderInvalidDataSectionMemoryIndex
            };
            *error = &wasmModuleReaderError;
            return;
        }
    }

    /* Read offset expression */
    if (readOffsetExpression) {
        offset = reader->buffer;
        if (!wasmReadConstantExpr(&reader->buffer)) {
            static WasmModuleReaderError wasmModuleReaderError = {
                wasmModuleReaderInvalidDataSectionOffsetExpression
            };
            *error = &wasmModuleReaderError;
            return;
        }
        offset.length -= reader->buffer.length;
    }

    /* Read bytes */
    if (!wasmReadBytes(&reader->buffer, &bytes)) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidDataSectionBytes
        };
        *error = &wasmModuleReaderError;
        return;
    }

    *error = NULL;

    result->memoryIndex = memoryIndex;
    result->offset = offset;
    result->bytes = bytes;
}

static
void
wasmReadDataSection(
    WasmModuleReader* reader,
    U32 UNUSED(sectionSize),
    WasmModuleReaderError** error
) {
    U32 dataSegmentCount = 0;
    WasmDataSegment* dataSegments = NULL;

    /* Read data count */
    if (leb128ReadU32(&reader->buffer, &dataSegmentCount) == 0) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidDataSectionDataSegmentCount
        };
        *error = &wasmModuleReaderError;
        return;
    }

    /* Allocate data segment array */
    dataSegments = calloc(dataSegmentCount, sizeof(WasmDataSegment));
    if (dataSegments == NULL) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderAllocationFailed
        };
        *error = &wasmModuleReaderError;
        return;
    }

    /* Read data segments */
    {
        U32 dataSegmentIndex = 0;
        for (; dataSegmentIndex < dataSegmentCount; dataSegmentIndex++) {
            WasmDataSegment dataSegment = wasmEmptyDataSegment;
            wasmReadDataSegment(reader, &dataSegment, error);
            if (*error != NULL) {
                goto fail;
            }
            dataSegments[dataSegmentIndex] = dataSegment;
        }
    }

    *error = NULL;

    reader->module->dataSegments.count = dataSegmentCount;
    reader->module->dataSegments.dataSegments = dataSegments;

    return;

fail:
    free(dataSegments);
}

static
void
wasmReadDataCountSection(
    WasmModuleReader* reader,
    U32 UNUSED(sectionSize),
    WasmModuleReaderError** error
) {
    U32 dataCount = 0;

    /* Read export count */
    if (leb128ReadU32(&reader->buffer, &dataCount) == 0) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidDataCountSectionDataCount
        };
        *error = &wasmModuleReaderError;
        return;
    }

    *error = NULL;
}

static
void
wasmReadTableSection(
    WasmModuleReader* reader,
    U32 UNUSED(sectionSize),
    WasmModuleReaderError** error
) {
    U32 tableCount = 0;
    WasmTable* tables = NULL;

    /* Read table count */
    if (leb128ReadU32(&reader->buffer, &tableCount) == 0) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidTableSectionTableCount
        };
        *error = &wasmModuleReaderError;
        return;
    }

    /* Allocate table segment array */
    tables = calloc(tableCount, sizeof(WasmTable));
    if (tables == NULL) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderAllocationFailed
        };
        *error = &wasmModuleReaderError;
        return;
    }

    /* Read tables */
    {
        U32 tableIndex = 0;
        for (; tableIndex < tableCount; tableIndex++) {
            WasmTable table = wasmEmptyTable;
            wasmReadTableType(reader, &table.min, &table.max, &table.shared, error);
            if (*error != NULL) {
                goto fail;
            }
            tables[tableIndex] = table;
        }
    }

    *error = NULL;

    reader->module->tables.count = tableCount;
    reader->module->tables.tables = tables;

    return;

fail:
    free(tables);
}

static
void
wasmReadElementSegment(
    WasmModuleReader* reader,
    WasmElementSegment* result,
    WasmModuleReaderError** error
) {
    U32 tableIndex;
    Buffer offset;
    U32 functionIndexCount;
    U32* functionIndices;

    /* Read element count */
    if (leb128ReadU32(&reader->buffer, &tableIndex) == 0) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidElementSectionTableIndex
        };
        *error = &wasmModuleReaderError;
        return;
    }

    /* Read offset expression */
    offset = reader->buffer;
    if (!wasmReadConstantExpr(&reader->buffer)) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidElementSectionOffsetExpression
        };
        *error = &wasmModuleReaderError;
        return;
    }
    offset.length -= reader->buffer.length;

    /* Read function index count */
    if (leb128ReadU32(&reader->buffer, &functionIndexCount) == 0) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidElementSectionFunctionIndexCount
        };
        *error = &wasmModuleReaderError;
        return;
    }

    /* Allocate element segment array */
    functionIndices = calloc(functionIndexCount, sizeof(U32));
    if (functionIndices == NULL) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderAllocationFailed
        };
        *error = &wasmModuleReaderError;
        return;
    }

    /* Read element segments */
    {
        U32 functionIndexIndex = 0;
        for (; functionIndexIndex < functionIndexCount; functionIndexIndex++) {
            U32 functionIndex;
            if (leb128ReadU32(&reader->buffer, &functionIndex) == 0) {
                static WasmModuleReaderError wasmModuleReaderError = {
                    wasmModuleReaderInvalidElementSectionFunctionIndex
                };
                *error = &wasmModuleReaderError;
                goto fail;
            }
            functionIndices[functionIndexIndex] = functionIndex;
        }
    }

    *error = NULL;

    result->tableIndex = tableIndex;
    result->offset = offset;
    result->functionIndexCount = functionIndexCount;
    result->functionIndices = functionIndices;

    return;

fail:
    free(functionIndices);
}

static
void
wasmReadElementSection(
    WasmModuleReader* reader,
    U32 UNUSED(sectionSize),
    WasmModuleReaderError** error
) {
    U32 elementSegmentCount = 0;
    WasmElementSegment* elementSegments = NULL;

    /* Read element count */
    if (leb128ReadU32(&reader->buffer, &elementSegmentCount) == 0) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidElementSectionElementSegmentCount
        };
        *error = &wasmModuleReaderError;
        return;
    }

    /* Allocate element segment array */
    elementSegments = calloc(elementSegmentCount, sizeof(WasmElementSegment));
    if (elementSegments == NULL) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderAllocationFailed
        };
        *error = &wasmModuleReaderError;
        return;
    }

    /* Read element segments */
    {
        U32 elementSegmentIndex = 0;
        for (; elementSegmentIndex < elementSegmentCount; elementSegmentIndex++) {
            WasmElementSegment elementSegment = wasmEmptyElementSegment;
            wasmReadElementSegment(reader, &elementSegment, error);
            if (*error != NULL) {
                goto fail;
            }
            elementSegments[elementSegmentIndex] = elementSegment;
        }
    }

    *error = NULL;

    reader->module->elementSegments.count = elementSegmentCount;
    reader->module->elementSegments.elementSegments = elementSegments;

    return;

fail:
    free(elementSegments);
}

static
void
wasmReadStartSection(
    WasmModuleReader* reader,
    U32 UNUSED(sectionSize),
    WasmModuleReaderError** error
) {
    U32 functionIndex = 0;

    /* Read export count */
    if (leb128ReadU32(&reader->buffer, &functionIndex) == 0) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidStartSectionFunctionIndex
        };
        *error = &wasmModuleReaderError;
        return;
    }

    *error = NULL;

    reader->module->startFunctionIndex = functionIndex;
    reader->module->hasStartFunction = true;
}

static WasmSectionReader wasmSectionReaders[] = {
    /* wasmSectionIDCustom    */ wasmReadCustomSection,
    /* wasmSectionIDType      */ wasmReadTypeSection,
    /* wasmSectionIDImport    */ wasmReadImportSection,
    /* wasmSectionIDFunction  */ wasmReadFunctionSection,
    /* wasmSectionIDTable     */ wasmReadTableSection,
    /* wasmSectionIDMemory    */ wasmReadMemorySection,
    /* wasmSectionIDGlobal    */ wasmReadGlobalSection,
    /* wasmSectionIDExport    */ wasmReadExportSection,
    /* wasmSectionIDStart     */ wasmReadStartSection,
    /* wasmSectionIDElement   */ wasmReadElementSection,
    /* wasmSectionIDCode      */ wasmReadCodeSection,
    /* wasmSectionIDData      */ wasmReadDataSection,
    /* wasmSectionIDDataCount */ wasmReadDataCountSection
};

static
void
wasmModuleReadSection(
    WasmModuleReader* reader,
    WasmModuleReaderError** error
) {
    U8 rawSectionID = 0;
    WasmSectionID sectionID = 0;
    U32 sectionSize = 0;
    const U32 sectionParsersCount = sizeof(wasmSectionReaders) / sizeof(wasmSectionReaders[0]);

    /* Read section ID */
    if (!bufferReadByte(&reader->buffer, &rawSectionID)) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidSectionID
        };
        *error = &wasmModuleReaderError;
        return;
    }

    sectionID = (WasmSectionID) rawSectionID;

    /* Read section size */
    if (leb128ReadU32(&reader->buffer, &sectionSize) == 0) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidSectionSize
        };
        *error = &wasmModuleReaderError;
        return;
    }

    if (sectionID < sectionParsersCount) {
        const WasmSectionReader wasmSectionReader = wasmSectionReaders[sectionID];
        if (wasmSectionReader != NULL) {
            const U8* start = reader->buffer.data;
            const U8* end = NULL;
            const U8* expectedEnd = NULL;

            wasmSectionReader(reader, sectionSize, error);
            if (*error != NULL) {
                return;
            }

            /* Check section was read completely */
            end = reader->buffer.data;
            expectedEnd = start + sectionSize;

            if (end != expectedEnd) {
                static WasmModuleReaderError wasmModuleReaderError = {
                    wasmModuleReaderIncorrectSectionRead
                };
                *error = &wasmModuleReaderError;
                return;
            }

            *error = NULL;

            return;
        }
    }

    fprintf(
        stderr,
        "w2c2: skipping unsupported %s (%d)\n",
        wasmSectionIDDescription(sectionID),
        sectionID
    );

    bufferSkip(&reader->buffer, sectionSize);

    *error = NULL;
}

void
wasmModuleRead(
    WasmModuleReader* reader,
    WasmModuleReaderError** error
) {
    WasmModule* module = NULL;

    const size_t length = reader->buffer.length;

    wasmModuleReadMagic(reader, error);
    if (*error != NULL) {
        return;
    }

    module = calloc(1, sizeof(WasmModule));
    if (module == NULL) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderAllocationFailed
        };
        *error = &wasmModuleReaderError;
        return;
    }
    module->length = length;
    reader->module = module;

    while (true) {
        if (bufferAtEnd(&reader->buffer)) {
            break;
        }

        wasmModuleReadSection(reader, error);
        if (*error != NULL) {
            goto fail;
        }

        *error = NULL;
    }

    if (reader->debug && module->debugSections.length > 0) {
        module->debugLines = wasmParseDebugInfo(module->debugSections);
    } else {
        module->debugLines = emptyWasmDebugLines;
    }

    return;

fail:
    free(module);
}
