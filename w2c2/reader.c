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

static const U8 wasmMagic[] = {
    0x00, 0x61, 0x73, 0x6D,
    0x01, 0x00, 0x00, 0x00,
};

const char*
wasmModuleReaderErrorMessage(
    WasmModuleReaderError* error
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
        case wasmModuleReaderInvalidExportSectionIndex:
            return "invalid export section index";
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
        case wasmModuleReaderInvalidDataSectionMemoryIndex:
            return "invalid data section memory index";
        case wasmModuleReaderInvalidDataSectionOffsetExpression:
            return "invalid data section offset expression";
        case wasmModuleReaderInvalidDataSectionBytes:
            return "invalid data section bytes";
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
    U32 count,
    WasmModuleReaderError** error
) {
    /* Allocate value type array */
    WasmValueType* valueTypes = calloc(sizeof(WasmValueType) * count, 1);
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
            WasmValueType valueType = wasmModuleReadValueType(reader, error);
            if (*error != NULL) {
                return NULL;
            }
            valueTypes[valueTypeIndex] = valueType;
        }
    }

    *error = NULL;
    return valueTypes;
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
        return;
    }

    /* Read result types */
    resultTypes = wasmReadValueTypes(reader, resultCount, error);
    if (*error != NULL) {
        return;
    }

    *error = NULL;

    result->parameterCount = parameterCount;
    result->parameterTypes = parameterTypes;
    result->resultCount = resultCount;
    result->resultTypes = resultTypes;
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
    return strcmp(
        ((const WasmFunctionNameEntry*)a)->name,
        ((const WasmFunctionNameEntry*)b)->name
    );
}

static
void
wasmFunctionNamesRemoveDuplicates(
    WasmNames* functionNames,
    WasmModuleReaderError** error
) {

    size_t functionNameCount = functionNames->length;
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
    U32 sectionSize,
    WasmModuleReaderError** error
) {
    U8* end = reader->buffer.data + sectionSize;

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
            const U32 functionCount = 
                reader->module->functionImports.length 
                + reader->module->functions.count;

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
    U8* start = reader->buffer.data;
    U8* end = NULL;

    /* Read name */
    if (!wasmReadName(&reader->buffer, &name)) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidCustomSectionName
        };
        *error = &wasmModuleReaderError;
        return;
    }

    end = reader->buffer.data;

    sectionSize -= end - start;

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
            return;
        }

        bufferSkip(&reader->buffer, sectionSize);

    } else if (reader->debug && strcmp(name, wasmNameSectionName) == 0) {
        wasmReadNameSection(reader, sectionSize, error);
        if (*error != NULL) {
            return;
        }
    } else {
        fprintf(stderr, "w2c2: skipping custom section '%s' (size %u)\n", name, sectionSize);
        bufferSkip(&reader->buffer, sectionSize);
    }

    *error = NULL;
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
    functionTypes = calloc(sizeof(WasmFunctionType) * typeCount, 1);
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
            free(functionTypes);
            return;
        }
        functionTypes[typeIndex] = functionType;
    }

    *error = NULL;

    reader->module->functionTypes.count = typeCount;
    reader->module->functionTypes.functionTypes = functionTypes;
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
    WasmValueType valueType = wasmModuleReadValueType(reader, error);
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
    WasmGlobalType globalType = wasmReadGlobalType(reader, error);
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
    WasmModuleReaderError** error
) {
    wasmReadLimits(reader, min, max, error);
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

    wasmReadMemoryType(reader, &import.min, &import.max, error);
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

    wasmReadLimits(reader, min, max, error);
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

    wasmReadTableType(reader, &import.min, &import.max, error);
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
        return;
    }

    /* Read name */
    if (!wasmReadName(&reader->buffer, &name)) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidImportSectionImportName
        };
        *error = &wasmModuleReaderError;
        return;
    }

    /* Read import kind */
    if (!bufferReadByte(&reader->buffer, &kindIndicator)
        || kindIndicator >= wasmImportKind_count) {

        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidImportSectionImportKind
        };
        *error = &wasmModuleReaderError;
        return;
    }

    switch (kindIndicator) {
        case wasmImportKindFunction: {
            wasmReadFunctionImport(reader, module, name, error);
            if (*error != NULL) {
                return;
            }
            break;
        }
        case wasmImportKindGlobal: {
            wasmReadGlobalImport(reader, module, name, error);
            if (*error != NULL) {
                return;
            }
            break;
        }
        case wasmImportKindMemory: {
            wasmReadMemoryImport(reader, module, name, error);
            if (*error != NULL) {
                return;
            }
            break;
        }
        case wasmImportKindTable: {
            wasmReadTableImport(reader, module, name, error);
            if (*error != NULL) {
                return;
            }
            break;
        }
        default: {
            static WasmModuleReaderError wasmModuleReaderError = {
                wasmModuleReaderInvalidImportSectionImportKind
            };
            *error = &wasmModuleReaderError;
            return;
        }
    }

    *error = NULL;
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
    functions = calloc(sizeof(WasmFunction) * functionCount, 1);
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
            return;
        }

        /* Check function type index does not exceed function type count */
        if (functionTypeIndex >= reader->module->functionTypes.count) {
            static WasmModuleReaderError wasmModuleReaderError = {
                wasmModuleReaderInvalidFunctionTypeIndex
            };
            *error = &wasmModuleReaderError;
            return;
        }

        function.functionTypeIndex = functionTypeIndex;
        functions[functionIndex] = function;
    }

    *error = NULL;

    reader->module->functions.count = functionCount;
    reader->module->functions.functions = functions;
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
            MUST (wasmGlobalInstructionRead(buffer, opcode, &instruction))
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
    memories = calloc(sizeof(WasmMemory) * memoryCount, 1);
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
        wasmReadMemoryType(reader, &memory.min, &memory.max, error);
        if (*error != NULL) {
            return;
        }
        memories[memoryIndex] = memory;
    }

    *error = NULL;

    reader->module->memories.count = memoryCount;
    reader->module->memories.memories = memories;
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
    WasmGlobalType type = wasmReadGlobalType(reader, error);
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
    globals = calloc(sizeof(WasmGlobal) * globalCount, 1);
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
            return;
        }
        globals[globalIndex] = global;
    }

    *error = NULL;

    reader->module->globals.count = globalCount;
    reader->module->globals.globals = globals;
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
        return;
    }

    /* Read export index */
    if (leb128ReadU32(&reader->buffer, &index) == 0) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidExportSectionIndex
        };
        *error = &wasmModuleReaderError;
        return;
    }

    *error = NULL;

    result->name = name;
    result->kind = kindIndicator;
    result->index = index;
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
            wasmModuleReaderInvalidTypeSectionTypeCount
        };
        *error = &wasmModuleReaderError;
        return;
    }

    /* Allocate export array */
    exports = calloc(sizeof(WasmExport) * exportCount, 1);
    if (exports == NULL) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderAllocationFailed
        };
        *error = &wasmModuleReaderError;
        return;
    }

    /* Read exports */
    {
        U32 exportIndex = 0;
        for (; exportIndex < exportCount; exportIndex++) {
            WasmExport export = wasmEmptyExport;
            wasmReadExport(reader, &export, error);
            if (*error != NULL) {
                return;
            }
            exports[exportIndex] = export;
        }
    }

    *error = NULL;

    reader->module->exports.count = exportCount;
    reader->module->exports.exports = exports;
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
        declarations = calloc(sizeof(struct WasmLocalsDeclaration) * declarationCount, 1);
        MUST (declarations != NULL)

        {
            U32 declarationIndex = 0;
            for (; declarationIndex < declarationCount; declarationIndex++) {
                WasmLocalsDeclaration declaration = {0, 0};

                MUST (leb128ReadU32(&reader->buffer, &declaration.count) > 0)
                MUST (wasmReadValueType(&reader->buffer, &declaration.type))

                declarations[declarationIndex] = declaration;
            }
        }
    }

    result->declarations = declarations;
    result->declarationCount = declarationCount;

    return true;
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

    size_t codeStart = reader->module->length - reader->buffer.length;

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

            if (!wasmReadCodeLocalsDeclarations(reader, &function->localsDeclarations)) {
                static WasmModuleReaderError wasmModuleReaderError = {
                    wasmModuleReaderInvalidCodeSectionLocalsDeclarations
                };
                *error = &wasmModuleReaderError;
                return;
            }

            function->start = reader->module->length - reader->buffer.length - codeStart;
            function->code.data = reader->buffer.data;
            codeSize -= reader->buffer.data - localsDeclarationsOffset;
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
    U32 memoryIndex = 0;
    Buffer offset;
    Buffer bytes = {NULL, 0};

    /* Read memory index */
    if (leb128ReadU32(&reader->buffer, &memoryIndex) == 0) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidDataSectionMemoryIndex
        };
        *error = &wasmModuleReaderError;
        return;
    }

    /* Read offset expression */
    offset = reader->buffer;
    if (!wasmReadConstantExpr(&reader->buffer)) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidDataSectionOffsetExpression
        };
        *error = &wasmModuleReaderError;
        return;
    }
    offset.length -= reader->buffer.length;

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
    dataSegments = calloc(sizeof(WasmDataSegment) * dataSegmentCount, 1);
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
                return;
            }
            dataSegments[dataSegmentIndex] = dataSegment;
        }
    }

    *error = NULL;

    reader->module->dataSegments.count = dataSegmentCount;
    reader->module->dataSegments.dataSegments = dataSegments;
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
    tables = calloc(sizeof(WasmTable) * tableCount, 1);
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
            wasmReadTableType(reader, &table.min, &table.max, error);
            if (*error != NULL) {
                return;
            }
            tables[tableIndex] = table;
        }
    }

    *error = NULL;

    reader->module->tables.count = tableCount;
    reader->module->tables.tables = tables;
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
    functionIndices = calloc(sizeof(U32) * functionIndexCount, 1);
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
                return;
            }
            functionIndices[functionIndexIndex] = functionIndex;
        }
    }

    *error = NULL;

    result->tableIndex = tableIndex;
    result->offset = offset;
    result->functionIndexCount = functionIndexCount;
    result->functionIndices = functionIndices;
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
    elementSegments = calloc(sizeof(WasmElementSegment) * elementSegmentCount, 1);
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
                return;
            }
            elementSegments[elementSegmentIndex] = elementSegment;
        }
    }

    *error = NULL;

    reader->module->elementSegments.count = elementSegmentCount;
    reader->module->elementSegments.elementSegments = elementSegments;
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
    /* wasmSectionIDCustom   */ wasmReadCustomSection,
    /* wasmSectionIDType     */ wasmReadTypeSection,
    /* wasmSectionIDImport   */ wasmReadImportSection,
    /* wasmSectionIDFunction */ wasmReadFunctionSection,
    /* wasmSectionIDTable    */ wasmReadTableSection,
    /* wasmSectionIDMemory   */ wasmReadMemorySection,
    /* wasmSectionIDGlobal   */ wasmReadGlobalSection,
    /* wasmSectionIDExport   */ wasmReadExportSection,
    /* wasmSectionIDStart    */ wasmReadStartSection,
    /* wasmSectionIDElement  */ wasmReadElementSection,
    /* wasmSectionIDCode     */ wasmReadCodeSection,
    /* wasmSectionIDData     */ wasmReadDataSection,
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
    U32 sectionParsersCount = sizeof(wasmSectionReaders) / sizeof(wasmSectionReaders[0]);

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
        WasmSectionReader wasmSectionReader = wasmSectionReaders[sectionID];
        if (wasmSectionReader != NULL) {
            U8* start = reader->buffer.data;
            U8* end = NULL;
            U8* expectedEnd = NULL;

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

    fprintf(stderr, "w2c2: skipping unsupported %s\n", wasmSectionIDDescription(sectionID));

    bufferSkip(&reader->buffer, sectionSize);

    *error = NULL;
}

void
wasmModuleRead(
    WasmModuleReader* reader,
    WasmModuleReaderError** error
) {
    WasmModule* module = NULL;

    size_t length = reader->buffer.length;

    wasmModuleReadMagic(reader, error);
    if (*error != NULL) {
        return;
    }

    module = calloc(sizeof(struct WasmModule), 1);
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
            return;
        }

        *error = NULL;
    }

    if (reader->debug && module->debugSections.length > 0) {
        module->debugLines = wasmParseDebugInfo(module->debugSections);
    } else {
        module->debugLines = emptyWasmDebugLines;
    }
}
