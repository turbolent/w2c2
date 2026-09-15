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
        case wasmModuleReaderInvalidSectionOrder:
            return "invalid section order";
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
    WasmValueType* valueTypes = NULL;

    if (count == 0) {
        *error = NULL;
        return NULL;
    }

    /* Allocate value type array */
    valueTypes = calloc(count, sizeof(WasmValueType));
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

    if ((size_t) parameterCount > reader->buffer.length) {
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

    if ((size_t) resultCount > reader->buffer.length) {
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

    name = calloc((size_t) length + 1, 1);
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
    WasmNames* functionNames,
    WasmModuleReaderError** error
) {
    const size_t functionNameCount = functionNames->length;
    size_t functionNameIndex = 0;
    size_t entryCount = 0;
    size_t entryIndex = 0;
    WasmFunctionNameEntry* entries = NULL;

    for (; functionNameIndex < functionNameCount; functionNameIndex++) {
        if (functionNames->names[functionNameIndex] != NULL) {
            entryCount++;
        }
    }

    if (entryCount < 2) {
        *error = NULL;
        return;
    }

    entries = calloc(entryCount, sizeof(WasmFunctionNameEntry));
    if (!entries) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderAllocationFailed
        };
        *error = &wasmModuleReaderError;
        return;
    }

    for (functionNameIndex = 0;
         functionNameIndex < functionNameCount;
         functionNameIndex++) {

        if (functionNames->names[functionNameIndex] != NULL) {
            WasmFunctionNameEntry* entry = &entries[entryIndex++];
            entry->functionIndex = assertSizeU32(functionNameIndex);
            entry->name = functionNames->names[functionNameIndex];
        }
    }

    qsort(
        entries,
        entryCount,
        sizeof(WasmFunctionNameEntry),
        wasmFunctionNameEntryCompareNames
    );

    entryIndex = 0;
    while (entryIndex < entryCount) {
        size_t duplicateEnd = entryIndex + 1;
        while (duplicateEnd < entryCount
               && strcmp(entries[entryIndex].name, entries[duplicateEnd].name) == 0) {

            duplicateEnd++;
        }

        if (duplicateEnd - entryIndex > 1) {
            size_t duplicateIndex = entryIndex + 1;
            for (; duplicateIndex < duplicateEnd; duplicateIndex++) {
                const WasmFunctionNameEntry previous = entries[duplicateIndex - 1];
                const WasmFunctionNameEntry current = entries[duplicateIndex];
                fprintf(
                    stderr,
                    "w2c2: ignoring duplicate function name %s used by functions %u and %u\n",
                    previous.name,
                    previous.functionIndex,
                    current.functionIndex
                );
            }

            for (duplicateIndex = entryIndex;
                 duplicateIndex < duplicateEnd;
                 duplicateIndex++) {

                const U32 duplicateFunctionIndex =
                    entries[duplicateIndex].functionIndex;
                free(functionNames->names[duplicateFunctionIndex]);
                functionNames->names[duplicateFunctionIndex] = NULL;
            }
        }

        entryIndex = duplicateEnd;
    }

    free(entries);
    *error = NULL;
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

        if (subsectionSize > reader->buffer.length) {
            static WasmModuleReaderError wasmModuleReaderError = {
                wasmModuleReaderInvalidSectionSize
            };
            *error = &wasmModuleReaderError;
            return;
        }

        /* Read function names */
        {
            const Buffer remainingBuffer = reader->buffer;

            reader->buffer.length = subsectionSize;

            if (subsectionID == wasmNameSubsectionIDFunctionNames) {
                const size_t functionImportCount = reader->module->functionImports.length;
                const U32 functionCount = assertSizeU32(functionImportCount) + reader->module->functions.count;
                const size_t previousFunctionNameCount =
                    reader->module->functionNames.length;
                size_t initializedFunctionNameCount = previousFunctionNameCount;

                U32 functionNameIndex = 0;

                /* Read function name count */
                if (leb128ReadU32(&reader->buffer, &functionNameCount) == 0) {
                    static WasmModuleReaderError wasmModuleReaderError = {
                        wasmModuleReaderInvalidNameSectionFunctionNameCount
                    };
                    *error = &wasmModuleReaderError;
                    return;
                }

                if ((size_t) functionNameCount > reader->buffer.length) {
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

                for (; initializedFunctionNameCount < functionCount;
                     initializedFunctionNameCount++) {

                    reader->module->functionNames.names[initializedFunctionNameCount] = NULL;
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

                    free(reader->module->functionNames.names[functionIndex]);
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
                bufferSkipUnchecked(&reader->buffer, subsectionSize);
            }

            if (!bufferAtEnd(&reader->buffer)) {
                static WasmModuleReaderError wasmModuleReaderError = {
                    wasmModuleReaderIncorrectSectionRead
                };
                *error = &wasmModuleReaderError;
                return;
            }

            reader->buffer = remainingBuffer;
            bufferSkipUnchecked(&reader->buffer, subsectionSize);
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
    U32 sectionSize,
    WasmModuleReaderError** error
) {
    U32 typeCount = 0;
    U32 typeIndex = 0;
    WasmFunctionType* functionTypes = NULL;
    UNUSED_PARAMETER(sectionSize);

    /* Read type count */
    if (leb128ReadU32(&reader->buffer, &typeCount) == 0) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidTypeSectionTypeCount
        };
        *error = &wasmModuleReaderError;
        return;
    }

    if ((size_t) typeCount > reader->buffer.length) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidTypeSectionTypeCount
        };
        *error = &wasmModuleReaderError;
        return;
    }

    /* Allocate function type array */
    if (typeCount > 0) {
        functionTypes = calloc(typeCount, sizeof(WasmFunctionType));
        if (functionTypes == NULL) {
            static WasmModuleReaderError wasmModuleReaderError = {
                wasmModuleReaderAllocationFailed
            };
            *error = &wasmModuleReaderError;
            return;
        }
    }
    reader->module->functionTypes.functionTypes = functionTypes;

    /* Read function types */
    for (; typeIndex < typeCount; typeIndex++) {
        WasmFunctionType functionType = wasmEmptyFunctionType;
        wasmReadFunctionType(reader, &functionType, error);
        if (*error != NULL) {
            goto fail;
        }
        functionTypes[typeIndex] = functionType;
        reader->module->functionTypes.count = typeIndex + 1;
    }

    *error = NULL;

    return;

fail:
    return;
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
    U32 sectionSize,
    WasmModuleReaderError** error
) {
    U32 importCount = 0;
    UNUSED_PARAMETER(sectionSize);

    /* Read import count */
    if (leb128ReadU32(&reader->buffer, &importCount) == 0) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidImportSectionImportCount
        };
        *error = &wasmModuleReaderError;
        return;
    }

    if ((size_t) importCount > reader->buffer.length) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidImportSectionImportCount
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
    U32 sectionSize,
    WasmModuleReaderError** error
) {
    U32 functionCount = 0;
    U32 functionIndex = 0;
    WasmFunction* functions = NULL;
    UNUSED_PARAMETER(sectionSize);

    /* Read function count */
    if (leb128ReadU32(&reader->buffer, &functionCount) == 0) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidFunctionSectionFunctionCount
        };
        *error = &wasmModuleReaderError;
        return;
    }

    if ((size_t) functionCount > reader->buffer.length) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidFunctionSectionFunctionCount
        };
        *error = &wasmModuleReaderError;
        return;
    }

    /* Allocate function array */
    if (functionCount > 0) {
        functions = calloc(functionCount, sizeof(WasmFunction));
        if (functions == NULL) {
            static WasmModuleReaderError wasmModuleReaderError = {
                wasmModuleReaderAllocationFailed
            };
            *error = &wasmModuleReaderError;
            return;
        }
    }
    reader->module->functions.functions = functions;

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
        reader->module->functions.count = functionIndex + 1;
    }

    *error = NULL;

    return;

fail:
    return;
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
    U32 sectionSize,
    WasmModuleReaderError** error
) {
    U32 memoryCount = 0;
    U32 memoryIndex = 0;
    WasmMemory* memories = NULL;
    UNUSED_PARAMETER(sectionSize);

    /* Read memory count */
    if (leb128ReadU32(&reader->buffer, &memoryCount) == 0) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidMemorySectionMemoryCount
        };
        *error = &wasmModuleReaderError;
        return;
    }

    if ((size_t) memoryCount > reader->buffer.length) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidMemorySectionMemoryCount
        };
        *error = &wasmModuleReaderError;
        return;
    }

    /* Allocate memories array */
    if (memoryCount > 0) {
        memories = calloc(memoryCount, sizeof(WasmMemory));
        if (memories == NULL) {
            static WasmModuleReaderError wasmModuleReaderError = {
                wasmModuleReaderAllocationFailed
            };
            *error = &wasmModuleReaderError;
            return;
        }
    }
    reader->module->memories.memories = memories;

    /* Read memories */
    for (; memoryIndex < memoryCount; memoryIndex++) {
        WasmMemory memory = wasmEmptyMemory;
        wasmReadMemoryType(reader, &memory.min, &memory.max, &memory.shared, error);
        if (*error != NULL) {
            goto fail;
        }
        memories[memoryIndex] = memory;
        reader->module->memories.count = memoryIndex + 1;
    }

    *error = NULL;

    return;

fail:
    return;
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
    U32 sectionSize,
    WasmModuleReaderError** error
) {
    U32 globalCount = 0;
    U32 globalIndex = 0;
    WasmGlobal* globals = NULL;
    UNUSED_PARAMETER(sectionSize);

    /* Read global count */
    if (leb128ReadU32(&reader->buffer, &globalCount) == 0) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidGlobalSectionGlobalCount
        };
        *error = &wasmModuleReaderError;
        return;
    }

    if ((size_t) globalCount > reader->buffer.length) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidGlobalSectionGlobalCount
        };
        *error = &wasmModuleReaderError;
        return;
    }

    /* Allocate globals array */
    if (globalCount > 0) {
        globals = calloc(globalCount, sizeof(WasmGlobal));
        if (globals == NULL) {
            static WasmModuleReaderError wasmModuleReaderError = {
                wasmModuleReaderAllocationFailed
            };
            *error = &wasmModuleReaderError;
            return;
        }
    }
    reader->module->globals.globals = globals;

    /* Read globals */
    for (; globalIndex < globalCount; globalIndex++) {
        WasmGlobal global = wasmEmptyGlobal;
        wasmReadGlobal(reader, &global, error);
        if (*error != NULL) {
            goto fail;
        }
        globals[globalIndex] = global;
        reader->module->globals.count = globalIndex + 1;
    }

    *error = NULL;

    return;

fail:
    return;
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
    U32 sectionSize,
    WasmModuleReaderError** error
) {
    U32 exportCount = 0;
    WasmExport* exports = NULL;
    UNUSED_PARAMETER(sectionSize);

    /* Read export count */
    if (leb128ReadU32(&reader->buffer, &exportCount) == 0) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidExportSectionExportCount
        };
        *error = &wasmModuleReaderError;
        return;
    }

    if ((size_t) exportCount > reader->buffer.length) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidExportSectionExportCount
        };
        *error = &wasmModuleReaderError;
        return;
    }

    /* Allocate export array */
    if (exportCount > 0) {
        exports = calloc(exportCount, sizeof(WasmExport));
        if (exports == NULL) {
            static WasmModuleReaderError wasmModuleReaderError = {
                wasmModuleReaderAllocationFailed
            };
            *error = &wasmModuleReaderError;
            return;
        }
    }
    reader->module->exports.exports = exports;

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
            reader->module->exports.count = exportIndex + 1;

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

    return;

fail:
    return;
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
    MUST ((size_t) declarationCount <= reader->buffer.length)

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
    U32 sectionSize,
    WasmModuleReaderError** error
) {
    U32 functionCount = 0;
    U32 functionIndex = 0;

    const U8* codeStart = reader->buffer.data;
    UNUSED_PARAMETER(sectionSize);

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
            const Buffer remainingBuffer = reader->buffer;
            const U8* localsDeclarationsOffset = reader->buffer.data;

            SHA1(localsDeclarationsOffset, codeSize, function->hash);

            reader->buffer.length = codeSize;
            if (!wasmReadCodeLocalsDeclarations(reader, &function->localsDeclarations)) {
                static WasmModuleReaderError wasmModuleReaderError = {
                    wasmModuleReaderInvalidCodeSectionLocalsDeclarations
                };
                *error = &wasmModuleReaderError;
                return;
            }

            function->start = (size_t)(reader->buffer.data - codeStart);
            function->code = reader->buffer;

            reader->buffer = remainingBuffer;

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

    if (length > 0) {
        bytes = calloc(length, 1);
        MUST (bytes != NULL)

        memcpy(
            bytes,
            (U8*) buffer->data,
            length
        );
    }

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
    U32 kind = 0;
    bool readMemoryIndex = false;
    bool readOffsetExpression = false;
    bool passive = false;
    U32 memoryIndex = 0;
    Buffer offset = emptyBuffer;
    Buffer bytes = emptyBuffer;

    if (!leb128ReadU32(&reader->buffer, &kind)) {
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
            passive = false;
            break;
        }
        case 0x1:
            readMemoryIndex = false;
            readOffsetExpression = false;
            passive = true;
            break;
        case 0x2:
            readMemoryIndex = true;
            readOffsetExpression = true;
            passive = false;
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
    result->passive = passive;
}

static
void
wasmReadDataSection(
    WasmModuleReader* reader,
    U32 sectionSize,
    WasmModuleReaderError** error
) {
    U32 dataSegmentCount = 0;
    WasmDataSegment* dataSegments = NULL;
    UNUSED_PARAMETER(sectionSize);

    /* Read data count */
    if (leb128ReadU32(&reader->buffer, &dataSegmentCount) == 0) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidDataSectionDataSegmentCount
        };
        *error = &wasmModuleReaderError;
        return;
    }

    if ((size_t) dataSegmentCount > reader->buffer.length) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidDataSectionDataSegmentCount
        };
        *error = &wasmModuleReaderError;
        return;
    }

    /* Allocate data segment array */
    if (dataSegmentCount > 0) {
        dataSegments = calloc(dataSegmentCount, sizeof(WasmDataSegment));
        if (dataSegments == NULL) {
            static WasmModuleReaderError wasmModuleReaderError = {
                wasmModuleReaderAllocationFailed
            };
            *error = &wasmModuleReaderError;
            return;
        }
    }
    reader->module->dataSegments.dataSegments = dataSegments;

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
            reader->module->dataSegments.count = dataSegmentIndex + 1;
        }
    }

    *error = NULL;

    return;

fail:
    return;
}

static
void
wasmReadDataCountSection(
    WasmModuleReader* reader,
    U32 sectionSize,
    WasmModuleReaderError** error
) {
    U32 dataCount = 0;
    UNUSED_PARAMETER(sectionSize);

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
    U32 sectionSize,
    WasmModuleReaderError** error
) {
    U32 tableCount = 0;
    WasmTable* tables = NULL;
    UNUSED_PARAMETER(sectionSize);

    /* Read table count */
    if (leb128ReadU32(&reader->buffer, &tableCount) == 0) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidTableSectionTableCount
        };
        *error = &wasmModuleReaderError;
        return;
    }

    if ((size_t) tableCount > reader->buffer.length) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidTableSectionTableCount
        };
        *error = &wasmModuleReaderError;
        return;
    }

    /* Allocate table segment array */
    if (tableCount > 0) {
        tables = calloc(tableCount, sizeof(WasmTable));
        if (tables == NULL) {
            static WasmModuleReaderError wasmModuleReaderError = {
                wasmModuleReaderAllocationFailed
            };
            *error = &wasmModuleReaderError;
            return;
        }
    }
    reader->module->tables.tables = tables;

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
            reader->module->tables.count = tableIndex + 1;
        }
    }

    *error = NULL;

    return;

fail:
    return;
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
    U32* functionIndices = NULL;

    /* Read table index */
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

    if ((size_t) functionIndexCount > reader->buffer.length) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidElementSectionFunctionIndexCount
        };
        *error = &wasmModuleReaderError;
        return;
    }

    /* Allocate element segment array */
    if (functionIndexCount > 0) {
        functionIndices = calloc(functionIndexCount, sizeof(U32));
        if (functionIndices == NULL) {
            static WasmModuleReaderError wasmModuleReaderError = {
                wasmModuleReaderAllocationFailed
            };
            *error = &wasmModuleReaderError;
            return;
        }
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
    U32 sectionSize,
    WasmModuleReaderError** error
) {
    U32 elementSegmentCount = 0;
    WasmElementSegment* elementSegments = NULL;
    UNUSED_PARAMETER(sectionSize);

    /* Read element count */
    if (leb128ReadU32(&reader->buffer, &elementSegmentCount) == 0) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidElementSectionElementSegmentCount
        };
        *error = &wasmModuleReaderError;
        return;
    }

    if ((size_t) elementSegmentCount > reader->buffer.length) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidElementSectionElementSegmentCount
        };
        *error = &wasmModuleReaderError;
        return;
    }

    /* Allocate element segment array */
    if (elementSegmentCount > 0) {
        elementSegments = calloc(elementSegmentCount, sizeof(WasmElementSegment));
        if (elementSegments == NULL) {
            static WasmModuleReaderError wasmModuleReaderError = {
                wasmModuleReaderAllocationFailed
            };
            *error = &wasmModuleReaderError;
            return;
        }
    }
    reader->module->elementSegments.elementSegments = elementSegments;

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
            reader->module->elementSegments.count = elementSegmentIndex + 1;
        }
    }

    *error = NULL;

    return;

fail:
    return;
}

static
void
wasmReadStartSection(
    WasmModuleReader* reader,
    U32 sectionSize,
    WasmModuleReaderError** error
) {
    U32 functionIndex = 0;
    UNUSED_PARAMETER(sectionSize);

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

static const U8 wasmSectionOrders[] = {
    /* wasmSectionIDCustom    */ 0,
    /* wasmSectionIDType      */ 1,
    /* wasmSectionIDImport    */ 2,
    /* wasmSectionIDFunction  */ 3,
    /* wasmSectionIDTable     */ 4,
    /* wasmSectionIDMemory    */ 5,
    /* wasmSectionIDGlobal    */ 6,
    /* wasmSectionIDExport    */ 7,
    /* wasmSectionIDStart     */ 8,
    /* wasmSectionIDElement   */ 9,
    /* wasmSectionIDCode      */ 11,
    /* wasmSectionIDData      */ 12,
    /* wasmSectionIDDataCount */ 10
};

static
void
wasmModuleReadSection(
    WasmModuleReader* reader,
    U8* lastSectionOrder,
    WasmModuleReaderError** error
) {
    U8 rawSectionID = 0;
    WasmSectionID sectionID = 0;
    U32 sectionSize = 0;
    const size_t sectionParsersCount =
        sizeof(wasmSectionReaders) / sizeof(wasmSectionReaders[0]);
    const size_t sectionOrdersCount =
        sizeof(wasmSectionOrders) / sizeof(wasmSectionOrders[0]);

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

    if (sectionSize > reader->buffer.length) {
        static WasmModuleReaderError wasmModuleReaderError = {
            wasmModuleReaderInvalidSectionSize
        };
        *error = &wasmModuleReaderError;
        return;
    }

    if (rawSectionID != wasmSectionIDCustom
        && (size_t)rawSectionID < sectionOrdersCount) {

        const U8 sectionOrder = wasmSectionOrders[rawSectionID];
        if (sectionOrder <= *lastSectionOrder) {
            static WasmModuleReaderError wasmModuleReaderError = {
                wasmModuleReaderInvalidSectionOrder
            };
            *error = &wasmModuleReaderError;
            return;
        }
        *lastSectionOrder = sectionOrder;
    }

    if ((size_t)rawSectionID < sectionParsersCount) {
        const WasmSectionReader wasmSectionReader =
            wasmSectionReaders[rawSectionID];
        if (wasmSectionReader != NULL) {
            const Buffer remainingBuffer = reader->buffer;

            reader->buffer.length = sectionSize;
            wasmSectionReader(reader, sectionSize, error);
            if (*error != NULL) {
                return;
            }

            /* Check section was read completely */
            if (!bufferAtEnd(&reader->buffer)) {
                static WasmModuleReaderError wasmModuleReaderError = {
                    wasmModuleReaderIncorrectSectionRead
                };
                *error = &wasmModuleReaderError;
                return;
            }

            reader->buffer = remainingBuffer;
            bufferSkipUnchecked(&reader->buffer, sectionSize);

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

    bufferSkipUnchecked(&reader->buffer, sectionSize);

    *error = NULL;
}

void
wasmModuleRead(
    WasmModuleReader* reader,
    WasmModuleReaderError** error
) {
    WasmModuleReader moduleReader = *reader;
    WasmModule* module = NULL;
    U8 lastSectionOrder = 0;

    const size_t length = moduleReader.buffer.length;
    moduleReader.module = NULL;

    wasmModuleReadMagic(&moduleReader, error);
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
    moduleReader.module = module;

    while (true) {
        if (bufferAtEnd(&moduleReader.buffer)) {
            break;
        }

        wasmModuleReadSection(&moduleReader, &lastSectionOrder, error);
        if (*error != NULL) {
            goto fail;
        }

        *error = NULL;
    }

    if (moduleReader.debug && module->debugSections.length > 0) {
        module->debugLines = wasmParseDebugInfo(module->debugSections);
    } else {
        module->debugLines = emptyWasmDebugLines;
    }

    wasmModuleFree(reader->module);
    reader->module = module;

    return;

fail:
    wasmModuleFree(module);
}
