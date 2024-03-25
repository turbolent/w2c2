#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#if HAS_PTHREAD
  #include <pthread.h>
#endif /* HAS_PTHREAD */
#include <errno.h>
#include <limits.h>
#include "compat.h"
#include "w2c2_base.h"

#ifndef PATH_MAX
#define PATH_MAX 1024
#endif

#include "c.h"
#include "stringbuilder.h"
#include "instruction.h"
#include "typestack.h"
#include "labelstack.h"

static const char localNamePrefix = 'l';
static const char globalNamePrefix = 'g';
static const char memoryNamePrefix = 'm';
static const char dataSegmentNamePrefix = 'd';
static const char tableNamePrefix = 't';
static const char stackNamePrefix = 's';
static const char labelNamePrefix = 'L';

static const char* const valueTypeNames[wasmValueType_count] = {
    "U32", "U64", "F32", "F64"
};

static const char* const signedTypeNames[2] = {
    "I32", "I64"
};

static const char* const shiftMaskStrings[2] = {
    "31", "63"
};

static const char valueTypeStackNames[wasmValueType_count] = {
    'i', 'j', 'f', 'd'
};

static const char* const indentation = "  ";

static
W2C2_INLINE
void
wasmCWriteFileLocalName(
    FILE* file,
    const U32 localIndex
) {
    fprintf(file, "%c%u", localNamePrefix, localIndex);
}

static
W2C2_INLINE
void
wasmCWriteFileEscaped(
    FILE* file,
    const char* name
) {
    static const char escapeChar = 'X';
    const char* p = name;
    for (; *p != '\0'; p++) {
        const char c = *p;
        if (c == '_') {
            /*
             * Double underscore is reserved for concatenating module name and import name,
             * so produce triple underscore instead.
             */
            const bool wasUnderscore = p != name && *(p-1) == '_';
            if (wasUnderscore) {
                fputs("__", file);
            } else {
                fputc(c, file);
            }
        } else if (c != escapeChar && isalnum(c)) {
            fputc(c, file);
        } else {
            fprintf(file, "%c%02X", escapeChar, c);
        }
    }
}

static const char* wasmImportNameSeparator = "__";

static
W2C2_INLINE
bool
WARN_UNUSED_RESULT
wasmCWriteStringEscaped(
    StringBuilder* builder,
    const char* name
) {
    static const char escapeChar = 'X';
    const char* p = name;
    for (; *p != '\0'; p++) {
        const char c = *p;
        if (c == '_') {
            /*
             * Double underscore is reserved for concatenating module name and import name,
             * so produce triple underscore instead.
             */
            const bool wasUnderscore = p != name && *(p-1) == '_';
            if (wasUnderscore) {
                MUST (stringBuilderAppend(builder, "__"))
            } else {
                MUST (stringBuilderAppendChar(builder, c))
            }
        } else if (c != escapeChar && isalnum(c)) {
            MUST (stringBuilderAppendChar(builder, c))
        } else {
            MUST (stringBuilderAppendChar(builder, escapeChar))
            MUST (stringBuilderAppendCharHex(builder, c))
        }
    }
    return true;
}

static
W2C2_INLINE
void
wasmCWriteFileGlobalNonImportName(
    FILE* file,
    const U32 globalIndex
) {
    fputc(globalNamePrefix, file);
    fprintf(file, "%u", globalIndex);
}

static
W2C2_INLINE
void
wasmCWriteFileImportName(
    FILE* file,
    const char* module,
    const char* name
) {
    wasmCWriteFileEscaped(file, module);
    fputs(wasmImportNameSeparator, file);
    wasmCWriteFileEscaped(file, name);
}


static
W2C2_INLINE
void
wasmCWriteFileGlobalUse(
    FILE* file,
    const WasmModule* module,
    const U32 globalIndex,
    const bool reference
) {
    if (globalIndex < module->globalImports.length) {
        const WasmGlobalImport import = module->globalImports.imports[globalIndex];
        if (!reference) {
            fputs("(*", file);
        }
        fputs("i->", file);
        wasmCWriteFileImportName(file, import.module, import.name);
        if (!reference) {
            fputc(')', file);
        }
    } else {
        if (reference) {
            fputc('&', file);
        }
        fputs("i->", file);
        wasmCWriteFileGlobalNonImportName(file, globalIndex);
    }
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteStringGlobalUse(
    StringBuilder* builder,
    const WasmModule* module,
    const U32 globalIndex,
    const bool reference
) {
    if (globalIndex < module->globalImports.length) {
        const WasmGlobalImport import = module->globalImports.imports[globalIndex];
        if (!reference) {
            MUST (stringBuilderAppend(builder, "(*"))
        }
        MUST (stringBuilderAppend(builder, "i->"))
        MUST (wasmCWriteStringEscaped(builder, import.module))
        MUST (stringBuilderAppend(builder, wasmImportNameSeparator))
        MUST (wasmCWriteStringEscaped(builder, import.name))
        if (!reference) {
            MUST (stringBuilderAppendChar(builder, ')'))
        }
    } else {
        if (reference) {
            MUST (stringBuilderAppendChar(builder, '&'))
        }
        MUST (stringBuilderAppend(builder, "i->"))
        MUST (stringBuilderAppendChar(builder, globalNamePrefix))
        MUST (stringBuilderAppendU32(builder, globalIndex))
    }
    return true;
}

static
W2C2_INLINE
void
wasmCWriteFileMemoryNonImportName(
    FILE* file,
    const U32 memoryIndex
) {
    fputc(memoryNamePrefix, file);
    fprintf(file, "%u", memoryIndex);
}

static
W2C2_INLINE
void
wasmCWriteFileMemoryUse(
    FILE* file,
    const WasmModule* module,
    const U32 memoryIndex,
    const char *variableName,
    const bool reference
) {
    if (variableName == NULL) {
        variableName = "i";
    }

    if (!reference) {
        fputs("(*", file);
    }
    fprintf(file, "%s->", variableName);
    if (memoryIndex < module->memoryImports.length) {
        const WasmMemoryImport import = module->memoryImports.imports[memoryIndex];
        wasmCWriteFileImportName(file, import.module, import.name);
    } else {
        wasmCWriteFileMemoryNonImportName(file, memoryIndex);
    }
    if (!reference) {
        fputc(')', file);
    }
}

static
W2C2_INLINE
bool
WARN_UNUSED_RESULT
wasmCWriteStringMemoryUse(
    StringBuilder* builder,
    const WasmModule* module,
    const U32 memoryIndex,
    const bool reference
) {
    if (!reference) {
        MUST (stringBuilderAppend(builder, "(*"))
    }
    MUST (stringBuilderAppend(builder, "i->"))
    if (memoryIndex < module->memoryImports.length) {
        const WasmMemoryImport import = module->memoryImports.imports[memoryIndex];
        MUST (wasmCWriteStringEscaped(builder, import.module))
        MUST (stringBuilderAppend(builder, wasmImportNameSeparator))
        MUST (wasmCWriteStringEscaped(builder, import.name))
    } else {
        MUST (stringBuilderAppendChar(builder, memoryNamePrefix))
        MUST (stringBuilderAppendU32(builder, memoryIndex))
    }
    if (!reference) {
        MUST (stringBuilderAppendChar(builder, ')'))
    }
    return true;
}

static
void
wasmCWriteFileTableNonImportName(
    FILE* file,
    const U32 tableIndex
) {
    fputc(tableNamePrefix, file);
    fprintf(file, "%u", tableIndex);
}

static
W2C2_INLINE
void
wasmCWriteFileTableUse(
    FILE* file,
    const WasmModule* module,
    const U32 tableIndex,
    const bool reference
) {
    if (tableIndex < module->tableImports.length) {
        const WasmTableImport import = module->tableImports.imports[tableIndex];
        if (!reference) {
            fputs("(*", file);
        }
        fputs("i->", file);
        wasmCWriteFileImportName(file, import.module, import.name);
        if (!reference) {
            fputc(')', file);
        }
    } else {
        if (reference) {
            fputc('&', file);
        }
        fputs("i->", file);
        wasmCWriteFileTableNonImportName(file, tableIndex);
    }
}

static
W2C2_INLINE
bool
WARN_UNUSED_RESULT
wasmCWriteStringTableUse(
    StringBuilder* builder,
    const WasmModule* module,
    const U32 tableIndex,
    const bool reference
) {
    if (tableIndex < module->tableImports.length) {
        const WasmTableImport import = module->tableImports.imports[tableIndex];
        if (!reference) {
            MUST (stringBuilderAppend(builder, "(*"))
        }
        MUST (stringBuilderAppend(builder, "i->"))
        MUST (wasmCWriteStringEscaped(builder, import.module))
        MUST (stringBuilderAppend(builder, wasmImportNameSeparator))
        MUST (wasmCWriteStringEscaped(builder, import.name))
        if (!reference) {
            MUST (stringBuilderAppendChar(builder, ')'))
        }
    } else {
        if (reference) {
            MUST (stringBuilderAppendChar(builder, '&'))
        }
        MUST (stringBuilderAppend(builder, "i->"))
        MUST (stringBuilderAppendChar(builder, tableNamePrefix))
        MUST (stringBuilderAppendU32(builder, tableIndex))
    }
    return true;
}

/* TODO: add support for multiple modules */
static
W2C2_INLINE
void
wasmCWriteFileDataSegmentName(
    FILE* file,
    const U32 dataSegmentIndex
) {
    fputc(dataSegmentNamePrefix, file);
    fprintf(file, "%u", dataSegmentIndex);
}

/* TODO: add support for multiple modules */
static
W2C2_INLINE
bool
wasmCWriteStringDataSegmentName(
    StringBuilder* builder,
    const U32 dataSegmentIndex
) {
    MUST (stringBuilderAppendChar(builder, dataSegmentNamePrefix))
    MUST (stringBuilderAppendU32(builder, dataSegmentIndex))
    return true;
}

static
W2C2_INLINE
void
wasmCWriteFileFunctionNonImportName(
    FILE* file,
    const U32 functionIndex
) {
    fprintf(file, "f%u", functionIndex);
}

static
W2C2_INLINE
void
wasmCWriteFileFunctionUse(
    FILE* file,
    const WasmModule* module,
    const char* moduleName,
    const U32 functionIndex,
    const bool reference,
    const bool prefix
) {
    if (reference) {
        fputc('&', file);
    }
    if (prefix) {
        fputs(moduleName, file);
        fputc('_', file);
    }
    if (functionIndex < module->functionImports.length) {
        const WasmFunctionImport import = module->functionImports.imports[functionIndex];
        wasmCWriteFileImportName(file, import.module, import.name);
    } else {
        wasmCWriteFileFunctionNonImportName(file, functionIndex);
    }
}

static
W2C2_INLINE
bool
WARN_UNUSED_RESULT
wasmCWriteStringFunctionUse(
    StringBuilder* builder,
    const WasmModule* module,
    const char* moduleName,
    const U32 functionIndex,
    const bool reference,
    const bool prefix
) {
    if (reference) {
        MUST (stringBuilderAppendChar(builder, '&'))
    }
    if (prefix) {
        MUST (stringBuilderAppend(builder, moduleName))
        MUST (stringBuilderAppendChar(builder, '_'))
    }
    if (functionIndex < module->functionImports.length) {
        const WasmFunctionImport import = module->functionImports.imports[functionIndex];
        MUST (wasmCWriteStringEscaped(builder, import.module))
        MUST (stringBuilderAppend(builder, wasmImportNameSeparator))
        MUST (wasmCWriteStringEscaped(builder, import.name))
    } else {
        MUST (stringBuilderAppendChar(builder, 'f'))
        MUST (stringBuilderAppendU32(builder, functionIndex))
    }
    return true;
}

static
W2C2_INLINE
void
wasmCWriteFileStackName(
    FILE* file,
    const U32 stackIndex,
    const WasmValueType valueType
) {
    fprintf(
        file,
        "%c%c%u",
        stackNamePrefix,
        valueTypeStackNames[valueType],
        stackIndex
    );
}

static
W2C2_INLINE
bool
WARN_UNUSED_RESULT
wasmCWriteStringStackName(
    StringBuilder* builder,
    const U32 stackIndex,
    const WasmValueType localType
) {
    MUST (stringBuilderAppendChar(builder, stackNamePrefix))
    MUST (stringBuilderAppendChar(builder, valueTypeStackNames[localType]))
    MUST (stringBuilderAppendU32(builder, stackIndex))
    return true;
}

static
W2C2_INLINE
bool
WARN_UNUSED_RESULT
wasmCWriteStringLocalName(
    StringBuilder* builder,
    const U32 localIndex
) {
    MUST (stringBuilderAppendChar(builder, localNamePrefix))
    MUST (stringBuilderAppendU32(builder, localIndex))
    return true;
}

static
W2C2_INLINE
bool
WARN_UNUSED_RESULT
wasmCWriteStringLabelName(
    StringBuilder* builder,
    const U32 labelIndex
) {
    MUST (stringBuilderAppendChar(builder, labelNamePrefix))
    MUST (stringBuilderAppendU32(builder, labelIndex))
    return true;
}

static
W2C2_INLINE
const char*
wasmCGetReturnType(
    const WasmFunctionType functionType
) {
    switch (functionType.resultCount) {
        case 0:
            return "void";
        case 1: {
            const WasmValueType resultType = functionType.resultTypes[0];
            return valueTypeNames[resultType];
        }
        default:
            /* TODO: add support for multiple result values */
            fprintf(stderr, "w2c2: unsupported function with multiple result values\n");
            abort();
    }
}

static
void
wasmCWriteFileLocalsDeclarations(
    FILE* file,
    const WasmModule* module,
    const WasmFunction function,
    const bool pretty
) {
    const WasmFunctionType functionType = module->functionTypes.functionTypes[function.functionTypeIndex];
    const U32 parameterCount = functionType.parameterCount;
    const U32 localsDeclarationCount = function.localsDeclarations.declarationCount;

    U32 localIndex = 0;
    U32 localsDeclarationIndex = 0;
    for (; localsDeclarationIndex < localsDeclarationCount; localsDeclarationIndex++) {
        const WasmLocalsDeclaration localsDeclaration =
            function.localsDeclarations.declarations[localsDeclarationIndex];

        const U32 endIndex = localIndex + localsDeclaration.count;
        for (; localIndex < endIndex; localIndex++) {
            if (pretty) {
                fputs(indentation, file);
            }
            fputs(valueTypeNames[localsDeclaration.type], file);
            fputc(' ', file);
            wasmCWriteFileLocalName(file, parameterCount + localIndex);
            fputs(pretty ? " = 0;\n" : "=0;\n", file);
        }
    }
}

typedef struct WasmCFunctionWriter {
    StringBuilder* builder;
    WasmTypeStack* typeStack;
    WasmTypeStack* stackDeclarations;
    WasmLabelStack* labelStack;
    const WasmModule* module;
    const char* moduleName;
    WasmFunction function;
    Buffer* code;
    U32 indent;
    bool ignore;
    bool pretty;
    bool debug;
    bool multipleModules;
    WasmDebugLines* debugLines;
} WasmCFunctionWriter;

static
W2C2_INLINE
bool
WARN_UNUSED_RESULT
wasmCWriteIndent(
    const WasmCFunctionWriter* writer
) {
    if (writer->pretty) {
        StringBuilder* builder = writer->builder;
        const U32 indent = writer->indent;
        U32 index = 0;
        for (; index <= indent; index++) {
            MUST (stringBuilderAppend(builder, indentation))
        }
    }
    return true;
}

static
W2C2_INLINE
bool
WARN_UNUSED_RESULT
wasmCWrite(
    const WasmCFunctionWriter* writer,
    const char* string
) {
    return stringBuilderAppend(writer->builder, string);
}


static
W2C2_INLINE
bool
WARN_UNUSED_RESULT
wasmCWriteChar(
    const WasmCFunctionWriter* writer,
    const char c
) {
    return stringBuilderAppendChar(writer->builder, c);
}

static
W2C2_INLINE
bool
WARN_UNUSED_RESULT
wasmCWriteAssign(
    const WasmCFunctionWriter* writer
) {
    if (writer->pretty) {
        return wasmCWrite(writer, " = ");
    } else {
        return wasmCWriteChar(writer, '=');
    }
}

static
W2C2_INLINE
bool
WARN_UNUSED_RESULT
wasmCWriteComma(
    const WasmCFunctionWriter* writer
) {
    if (writer->pretty) {
        return wasmCWrite(writer, ", ");
    } else {
        return wasmCWriteChar(writer, ',');
    }
}

static
W2C2_INLINE
bool
WARN_UNUSED_RESULT
wasmCWritePlus(
    const WasmCFunctionWriter* writer
) {
    if (writer->pretty) {
        return wasmCWrite(writer, " + ");
    } else {
        return wasmCWriteChar(writer, '+');
    }
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteFunctionCode(
    WasmCFunctionWriter* writer,
    WasmOpcode* opcode
);

static
bool
WARN_UNUSED_RESULT
wasmCWriteCallExpr(
    const WasmCFunctionWriter* writer
) {
    WasmCallInstruction instruction;
    if (!wasmCallInstructionRead(writer->code, &instruction)) {
        fprintf(stderr, "w2c2: invalid call instruction encoding\n");
        return false;
    }

    if (!writer->ignore) {
        WasmFunctionType functionType;
        MUST (wasmModuleGetFunctionType(writer->module, instruction.funcIndex, &functionType))
        {
            const U32 parameterCount = functionType.parameterCount;
            const U32 resultCount = functionType.resultCount;

            MUST (wasmCWriteIndent(writer))

            if (resultCount > 0) {
                /* TODO: add support for multiple result values */
                const WasmValueType resultType = functionType.resultTypes[0];

                U32 resultStackIndex = assertSizeU32(writer->typeStack->length);
                if (parameterCount > 0) {
                    resultStackIndex -= parameterCount;
                }

                MUST (wasmTypeStackSet(writer->stackDeclarations, resultStackIndex, resultType))
                MUST (wasmCWriteStringStackName(writer->builder, resultStackIndex, resultType))
                MUST (wasmCWriteAssign(writer))
            }

            MUST (wasmCWriteStringFunctionUse(
                writer->builder,
                writer->module,
                writer->moduleName,
                instruction.funcIndex,
                false,
                writer->multipleModules
            ))

            MUST (wasmCWrite(writer, "(i"))
            {
                U32 parameterIndex = 0;
                for (; parameterIndex < parameterCount; parameterIndex++) {
                    const WasmValueType parameterType = functionType.parameterTypes[parameterIndex];
                    const U32 paramStackIndex = wasmTypeStackGetTopIndex(
                        writer->typeStack,
                        parameterCount - parameterIndex - 1
                    );
                    MUST (wasmCWriteComma(writer))
                    MUST (wasmCWriteStringStackName(writer->builder, paramStackIndex, parameterType))
                }
            }
            MUST (wasmCWrite(writer, ");\n"))

            wasmTypeStackDrop(writer->typeStack, parameterCount);
            {
                U32 resultIndex = 0;
                for (; resultIndex < resultCount; resultIndex++) {
                    const WasmValueType resultType = functionType.resultTypes[resultIndex];
                    MUST (wasmTypeStackAppend(writer->typeStack, resultType))
                }
            }
        }
    }

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteParameters(
    const WasmCFunctionWriter* writer,
    const WasmFunctionType functionType
) {
    MUST (wasmCWriteChar(writer, '('))
    MUST (wasmCWrite(writer, writer->moduleName))
    MUST (wasmCWrite(writer, "Instance*"))
    {
        U32 parameterIndex = 0;
        for (; parameterIndex < functionType.parameterCount; parameterIndex++) {
            const WasmValueType parameterType = functionType.parameterTypes[parameterIndex];
            MUST (wasmCWriteComma(writer))
            MUST (wasmCWrite(writer, valueTypeNames[parameterType]))
        }
    }
    MUST (wasmCWriteChar(writer, ')'))

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteCallIndirectExpr(
    const WasmCFunctionWriter* writer
) {
    WasmCallIndirectInstruction instruction;
    if (!wasmCallIndirectInstructionRead(writer->code, &instruction)) {
        fprintf(stderr, "w2c2: invalid call_indirect instruction encoding\n");
        return false;
    }

    if (!writer->ignore) {
        const WasmFunctionType functionType = writer->module->functionTypes.functionTypes[instruction.functionTypeIndex];

        const U32 parameterCount = functionType.parameterCount;
        const U32 resultCount = functionType.resultCount;

        MUST (wasmCWriteIndent(writer))

        if (resultCount > 0) {
            /* TODO: add support for multiple result values */
            const WasmValueType resultType = functionType.resultTypes[0];

            U32 resultStackIndex = assertSizeU32(writer->typeStack->length - 1);
            if (parameterCount > 0) {
                resultStackIndex -= parameterCount;
            }

            MUST (wasmTypeStackSet(writer->stackDeclarations, resultStackIndex, resultType))
            MUST (wasmCWriteStringStackName(writer->builder, resultStackIndex, resultType))
            MUST (wasmCWriteAssign(writer))
        }

        MUST (wasmCWrite(writer, "TF("))
        MUST (wasmCWriteStringTableUse(writer->builder, writer->module, instruction.tableIndex, false))
        MUST (wasmCWriteComma(writer))

        {
            const U32 stackIndex0 = wasmTypeStackGetTopIndex(writer->typeStack, 0);
            MUST (wasmCWriteStringStackName(
                writer->builder,
                stackIndex0,
                writer->typeStack->valueTypes[stackIndex0]
            ))
        }

        MUST (wasmCWriteComma(writer))
        MUST (wasmCWrite(writer, wasmCGetReturnType(functionType)))
        MUST (wasmCWrite(writer, " (*)"))

        MUST (wasmCWriteParameters(writer, functionType))

        MUST (wasmCWrite(writer, ")(i"))

        {
            U32 parameterIndex = 0;
            for (; parameterIndex < parameterCount; parameterIndex++) {
                const WasmValueType parameterType = functionType.parameterTypes[parameterIndex];
                const U32 paramStackIndex = wasmTypeStackGetTopIndex(
                    writer->typeStack,
                    parameterCount - parameterIndex
                );
                MUST (wasmCWriteComma(writer))
                MUST (wasmCWriteStringStackName(writer->builder, paramStackIndex, parameterType))
            }
        }
        MUST (wasmCWrite(writer, ");\n"))

        wasmTypeStackDrop(writer->typeStack, parameterCount + 1);
        {
            U32 resultIndex = 0;
            for (; resultIndex < resultCount; resultIndex++) {
                const WasmValueType resultType = functionType.resultTypes[resultIndex];
                MUST (wasmTypeStackAppend(writer->typeStack, resultType))
            }
        }
    }

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteLocalGetExpr(
    const WasmCFunctionWriter* writer
) {
    WasmLocalInstruction instruction;
    if (!wasmLocalInstructionRead(writer->code, &instruction)) {
        fprintf(stderr, "w2c2: invalid local.get instruction encoding\n");
        return false;
    }

    if (!writer->ignore) {
        WasmValueType localType = 0;
        const bool gotType = wasmModuleFunctionGetLocalType(
            writer->module,
            writer->function,
            instruction.localIndex,
            &localType
        );
        if (!gotType) {
            fprintf(
                stderr,
                "w2c2: invalid local.get instruction: invalid local index: %u\n",
                instruction.localIndex
            );
            return false;
        }
        MUST (wasmTypeStackAppend(writer->typeStack, localType))
        {
            const U32 stackIndex0 = wasmTypeStackGetTopIndex(writer->typeStack, 0);
            MUST (wasmTypeStackSet(writer->stackDeclarations, stackIndex0, localType))

            MUST (wasmCWriteIndent(writer))
            MUST (wasmCWriteStringStackName(writer->builder, stackIndex0, localType))
            MUST (wasmCWriteAssign(writer))
            MUST (wasmCWriteStringLocalName(writer->builder, instruction.localIndex))
            MUST (wasmCWrite(writer, ";\n"))
        }
    }

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteLocalAssignmentExpr(
    const WasmCFunctionWriter* writer,
    const WasmOpcode opcode
) {
    WasmLocalInstruction instruction;
    if (!wasmLocalInstructionRead(writer->code, &instruction)) {
        fprintf(
            stderr,
            "w2c2: invalid %s instruction encoding\n",
            wasmOpcodeDescription(opcode)
        );
        return false;
    }

    if (!writer->ignore) {
        WasmValueType localType = 0;
        const bool gotType = wasmModuleFunctionGetLocalType(
            writer->module,
            writer->function,
            instruction.localIndex,
            &localType
        );
        if (!gotType) {
            fprintf(
                stderr,
                "w2c2: invalid %s instruction: invalid local index: %u\n",
                wasmOpcodeDescription(opcode),
                instruction.localIndex
            );
            return false;
        }
        {
            const U32 stackIndex0 = wasmTypeStackGetTopIndex(writer->typeStack, 0);
            MUST (wasmTypeStackSet(writer->stackDeclarations, stackIndex0, localType))

            MUST (wasmCWriteIndent(writer))
            MUST (wasmCWriteStringLocalName(writer->builder, instruction.localIndex))
            MUST (wasmCWriteAssign(writer))
            MUST (wasmCWriteStringStackName(writer->builder, stackIndex0, localType))
            MUST (wasmCWrite(writer, ";\n"))
        }
        if (opcode == wasmOpcodeLocalSet) {
            wasmTypeStackDrop(writer->typeStack, 1);
        }
    }

    return true;
}


static
bool
WARN_UNUSED_RESULT
wasmCWriteGlobalGetExpr(
    const WasmCFunctionWriter* writer
) {
    static const WasmOpcode opcode = wasmOpcodeGlobalGet;

    WasmGlobalInstruction instruction;
    if (!wasmGlobalInstructionRead(writer->code, &instruction)) {
        fprintf(
            stderr,
            "w2c2: invalid %s instruction encoding\n",
            wasmOpcodeDescription(opcode)
        );
        return false;
    }

    if (!writer->ignore) {
        WasmValueType globalType = 0;
        const bool gotType = wasmModuleGetGlobalType(
            writer->module,
            instruction.globalIndex,
            &globalType
        );
        if (!gotType) {
            fprintf(
                stderr,
                "w2c2: invalid %s instruction: invalid global index: %u\n",
                wasmOpcodeDescription(opcode),
                instruction.globalIndex
            );
            return false;
        }
        MUST (wasmTypeStackAppend(writer->typeStack, globalType))
        {
            const U32 stackIndex0 = wasmTypeStackGetTopIndex(writer->typeStack, 0);
            MUST (wasmTypeStackSet(writer->stackDeclarations, stackIndex0, globalType))

            MUST (wasmCWriteIndent(writer))
            MUST (wasmCWriteStringStackName(writer->builder, stackIndex0, globalType))
            MUST (wasmCWriteAssign(writer))
            MUST (wasmCWriteStringGlobalUse(writer->builder, writer->module, instruction.globalIndex, false))
            MUST (wasmCWrite(writer, ";\n"))
        }
    }

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteGlobalSetExpr(
    const WasmCFunctionWriter* writer
) {
    static const WasmOpcode opcode = wasmOpcodeGlobalSet;

    WasmGlobalInstruction instruction;
    if (!wasmGlobalInstructionRead(writer->code, &instruction)) {
        fprintf(
            stderr,
            "w2c2: invalid %s instruction encoding\n",
            wasmOpcodeDescription(opcode)
        );
        return false;
    }

    if (!writer->ignore) {
        WasmValueType globalType = 0;
        const bool gotType = wasmModuleGetGlobalType(
            writer->module,
            instruction.globalIndex,
            &globalType
        );
        if (!gotType) {
            fprintf(
                stderr,
                "w2c2: invalid %s instruction: invalid global index: %u\n",
                wasmOpcodeDescription(opcode),
                instruction.globalIndex
            );
            return false;
        }
        {
            const U32 stackIndex0 = wasmTypeStackGetTopIndex(writer->typeStack, 0);
            MUST (wasmTypeStackSet(writer->stackDeclarations, stackIndex0, globalType))

            MUST (wasmCWriteIndent(writer))
            MUST (wasmCWriteStringGlobalUse(writer->builder, writer->module, instruction.globalIndex, false))
            MUST (wasmCWriteAssign(writer))
            MUST (wasmCWriteStringStackName(writer->builder, stackIndex0, globalType))
            MUST (wasmCWrite(writer, ";\n"))
        }
        wasmTypeStackDrop(writer->typeStack, 1);
    }

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteLiteral(
    StringBuilder* builder,
    const WasmValueType valueType,
    const WasmValue value
) {
    switch (valueType) {
        case wasmValueTypeI32: {
            MUST (stringBuilderAppendI32(builder, value.i32))
            MUST (stringBuilderAppendChar(builder, 'U'))
            break;
        }
        case wasmValueTypeI64: {
            MUST (stringBuilderAppendI64(builder, value.i64))
            MUST (stringBuilderAppend(builder, "ULL"))
            break;
        }
        case wasmValueTypeF32: {
            const U32 bits = (U32) value.i32;
            if ((bits & 0x7f800000U) == 0x7f800000U) {
                const bool isNegative = (bits & 0x80000000U) != 0;
                const U32 significand = bits & 0x7fffffU;
                if (significand == 0) {
                    if (isNegative) {
                        MUST (stringBuilderAppendChar(builder, '-'))
                    }
                    MUST (stringBuilderAppend(builder, "INFINITY"))
                } else {
                    MUST (stringBuilderAppend(builder, "f32_reinterpret_i32(0x"))
                    MUST (stringBuilderAppendU32Hex(builder, bits))
                    MUST (stringBuilderAppendChar(builder, ')'))
                }
            } else if (bits == 0x80000000U) {
                MUST (stringBuilderAppend(builder, "-0.f"))
            } else {
                MUST (stringBuilderAppendF32(builder, value.f32))
            }
            break;
        }
        case wasmValueTypeF64: {
            const U64 bits = (U64) value.i64;
            if ((bits & 0x7ff0000000000000ULL) == 0x7ff0000000000000ULL) {
                const bool isNegative = (bits & 0x8000000000000000ULL) != 0;
                const U64 significand = bits & 0x7fffffULL;
                if (significand == 0) {
                    if (isNegative) {
                        MUST (stringBuilderAppendChar(builder, '-'))
                    }
                    MUST (stringBuilderAppend(builder, "INFINITY"))
                } else {
                    MUST (stringBuilderAppend(builder, "f64_reinterpret_i64(0x"))
                    MUST (stringBuilderAppendU64Hex(builder, bits))
                    MUST (stringBuilderAppendChar(builder, ')'))
                }
            } else if (bits == 0x8000000000000000ULL) {
                MUST (stringBuilderAppend(builder, "-0.f"))
            } else {
                MUST (stringBuilderAppendF64(builder, value.f64))
            }
            break;
        }
        default:
            fprintf(stderr, "w2c2: unsupported const type %s\n", wasmValueTypeDescription(valueType));
            return false;
    }

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteConstExpr(
    const WasmCFunctionWriter* writer,
    const WasmOpcode opcode
) {
    WasmConstInstruction instruction;
    if (!wasmConstInstructionRead(writer->code, opcode, &instruction)) {
        fprintf(
            stderr,
            "w2c2: invalid %s instruction encoding\n",
            wasmOpcodeDescription(opcode)
        );
        return false;
    }

    if (!writer->ignore) {
        const WasmValueType resultType = wasmOpcodeResultType(opcode);
        MUST (wasmTypeStackAppend(writer->typeStack, resultType))
        {
            const U32 stackIndex0 = wasmTypeStackGetTopIndex(writer->typeStack, 0);
            MUST (wasmTypeStackSet(writer->stackDeclarations, stackIndex0, resultType))
            MUST (wasmCWriteIndent(writer))
            MUST (wasmCWriteStringStackName(writer->builder, stackIndex0, resultType))
            MUST (wasmCWriteAssign(writer))
            MUST (wasmCWriteLiteral(writer->builder, resultType, instruction.value))
            MUST (wasmCWrite(writer, ";\n"))
        }
    }

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteLoad(
    const WasmCFunctionWriter* writer,
    const WasmMemoryArgumentInstruction instruction,
    const char* functionName,
    WasmValueType resultType
) {
    const U32 stackIndex0 = wasmTypeStackGetTopIndex(writer->typeStack, 0);
    MUST (wasmTypeStackSet(writer->stackDeclarations, stackIndex0, resultType))
    MUST (wasmCWriteIndent(writer))
    MUST (wasmCWriteStringStackName(writer->builder, stackIndex0, resultType))
    MUST (wasmCWriteAssign(writer))
    MUST (wasmCWrite(writer, functionName))
    MUST (wasmCWriteChar(writer, '('))
    MUST (wasmCWriteStringMemoryUse(writer->builder, writer->module, 0, true))
    MUST (wasmCWriteComma(writer))
    MUST (wasmCWrite(writer, "(U64)"))
    MUST (wasmCWriteStringStackName(
        writer->builder,
        stackIndex0,
        writer->typeStack->valueTypes[stackIndex0]
    ))
    if (instruction.offset != 0) {
        MUST (wasmCWritePlus(writer))
        MUST (stringBuilderAppendU32(writer->builder, instruction.offset))
        MUST (wasmCWriteChar(writer, 'U'))
    }
    MUST (wasmCWrite(writer, ");\n"))

    wasmTypeStackDrop(writer->typeStack, 1);

    MUST (wasmTypeStackAppend(writer->typeStack, resultType))

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteLoadExpr(
    const WasmCFunctionWriter* writer,
    const WasmOpcode opcode
) {
    WasmMemoryArgumentInstruction instruction;

    if (!wasmMemoryArgumentInstructionRead(writer->code, &instruction)) {
        fprintf(
            stderr,
            "w2c2: invalid %s instruction encoding\n",
            wasmOpcodeDescription(opcode)
        );
        return false;
    }

    if (!writer->ignore) {
        WasmValueType resultType = 0;
        char* functionName = NULL;
        switch (opcode) {
            case wasmOpcodeI32Load: {
                resultType = wasmValueTypeI32;
                functionName = "i32_load";
                break;
            }
            case wasmOpcodeI64Load: {
                resultType = wasmValueTypeI64;
                functionName = "i64_load";
                break;
            }
            case wasmOpcodeF32Load: {
                resultType = wasmValueTypeF32;
                functionName = "f32_load";
                break;
            }
            case wasmOpcodeF64Load: {
                resultType = wasmValueTypeF64;
                functionName = "f64_load";
                break;
            }
            case wasmOpcodeI32Load8S: {
                resultType = wasmValueTypeI32;
                functionName = "i32_load8_s";
                break;
            }
            case wasmOpcodeI64Load8S: {
                resultType = wasmValueTypeI64;
                functionName = "i64_load8_s";
                break;
            }
            case wasmOpcodeI32Load8U: {
                resultType = wasmValueTypeI32;
                functionName = "i32_load8_u";
                break;
            }
            case wasmOpcodeI64Load8U: {
                resultType = wasmValueTypeI64;
                functionName = "i64_load8_u";
                break;
            }
            case wasmOpcodeI32Load16S: {
                resultType = wasmValueTypeI32;
                functionName = "i32_load16_s";
                break;
            }
            case wasmOpcodeI64Load16S: {
                resultType = wasmValueTypeI64;
                functionName = "i64_load16_s";
                break;
            }
            case wasmOpcodeI32Load16U: {
                resultType = wasmValueTypeI32;
                functionName = "i32_load16_u";
                break;
            }
            case wasmOpcodeI64Load16U: {
                resultType = wasmValueTypeI64;
                functionName = "i64_load16_u";
                break;
            }
            case wasmOpcodeI64Load32S: {
                resultType = wasmValueTypeI64;
                functionName = "i64_load32_s";
                break;
            }
            case wasmOpcodeI64Load32U: {
                resultType = wasmValueTypeI64;
                functionName = "i64_load32_u";
                break;
            }
            default: {
                fprintf(
                    stderr,
                    "w2c2: unsupported load instruction opcode: %s\n",
                    wasmOpcodeDescription(opcode)
                );
                return false;
            }
        }

        MUST (wasmCWriteLoad(
            writer,
            instruction,
            functionName,
            resultType
        ))
    }

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteStore(
    const WasmCFunctionWriter* writer,
    const WasmMemoryArgumentInstruction instruction,
    const char* functionName
) {
    const U32 stackIndex0 = wasmTypeStackGetTopIndex(writer->typeStack, 0);
    const U32 stackIndex1 = wasmTypeStackGetTopIndex(writer->typeStack, 1);

    MUST (wasmCWriteIndent(writer))
    MUST (wasmCWrite(writer, functionName))
    MUST (wasmCWriteChar(writer, '('))
    MUST (wasmCWriteStringMemoryUse(writer->builder, writer->module, 0, true))
    MUST (wasmCWriteComma(writer))
    MUST (wasmCWrite(writer, "(U64)"))
    MUST (wasmCWriteStringStackName(
        writer->builder,
        stackIndex1,
        writer->typeStack->valueTypes[stackIndex1]
    ))
    if (instruction.offset != 0) {
        MUST (wasmCWritePlus(writer))
        MUST (stringBuilderAppendU32(writer->builder, instruction.offset))
        MUST (wasmCWriteChar(writer, 'U'))
    }
    MUST (wasmCWriteComma(writer))
    MUST (wasmCWriteStringStackName(
        writer->builder,
        stackIndex0,
        writer->typeStack->valueTypes[stackIndex0]
    ))
    MUST (wasmCWrite(writer, ");\n"))

    wasmTypeStackDrop(writer->typeStack, 2);

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteStoreExpr(
    const WasmCFunctionWriter* writer,
    const WasmOpcode opcode
) {
    WasmMemoryArgumentInstruction instruction;
    if (!wasmMemoryArgumentInstructionRead(writer->code, &instruction)) {
        fprintf(
            stderr,
            "w2c2: invalid %s instruction encoding\n",
            wasmOpcodeDescription(opcode)
        );
        return false;
    }

    if (!writer->ignore) {
        char* functionName = NULL;
        switch (opcode) {
            case wasmOpcodeI32Store: {
                functionName = "i32_store";
                break;
            }
            case wasmOpcodeI64Store: {
                functionName = "i64_store";
                break;
            }
            case wasmOpcodeF32Store: {
                functionName = "f32_store";
                break;
            }
            case wasmOpcodeF64Store: {
                functionName = "f64_store";
                break;
            }
            case wasmOpcodeI32Store8: {
                functionName = "i32_store8";
                break;
            }
            case wasmOpcodeI64Store8: {
                functionName = "i64_store8";
                break;
            }
            case wasmOpcodeI32Store16: {
                functionName = "i32_store16";
                break;
            }
            case wasmOpcodeI64Store16: {
                functionName = "i64_store16";
                break;
            }
            case wasmOpcodeI64Store32: {
                functionName = "i64_store32";
                break;
            }
            default: {
                fprintf(
                    stderr,
                    "w2c2: unsupported store instruction opcode: %s\n",
                    wasmOpcodeDescription(opcode)
                );
                return false;
            }
        }

        MUST (wasmCWriteStore(writer, instruction, functionName))
    }

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteMemorySizeExpr(
    const WasmCFunctionWriter* writer
) {
    WasmMemoryInstruction instruction;
    if (!wasmMemoryInstructionRead(writer->code, &instruction)) {
        fprintf(stderr, "w2c2: invalid memory.size instruction encoding\n");
        return false;
    }

    {
        static const U32 expectedMemoryIndex = 0;
        if (instruction.memoryIndex != expectedMemoryIndex) {
            fprintf(
                stderr,
                "w2c2: invalid memory.size instruction: expected memory index %u, got %u\n",
                expectedMemoryIndex,
                instruction.memoryIndex
            );
            return false;
        }
    }

    if (!writer->ignore) {
        static const WasmValueType resultType = wasmValueTypeI32;

        MUST (wasmTypeStackAppend(writer->typeStack, resultType))
        {
            const U32 stackIndex0 = wasmTypeStackGetTopIndex(writer->typeStack, 0);
            MUST (wasmTypeStackSet(writer->stackDeclarations, stackIndex0, resultType))

            MUST (wasmCWriteIndent(writer))
            MUST (wasmCWriteStringStackName(
                writer->builder,
                stackIndex0,
                resultType
            ))
            MUST (wasmCWriteAssign(writer))
            MUST (wasmCWriteStringMemoryUse(
                writer->builder,
                writer->module,
                instruction.memoryIndex,
                false
            ))
            MUST (wasmCWrite(writer, ".pages;\n"))
        }
    }

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteMemoryGrowExpr(
    const WasmCFunctionWriter* writer
) {
    WasmMemoryInstruction instruction;
    if (!wasmMemoryInstructionRead(writer->code, &instruction)) {
        fprintf(stderr, "w2c2: invalid memory.grow instruction encoding\n");
        return false;
    }

    {
        static const U32 expectedMemoryIndex = 0;
        if (instruction.memoryIndex != expectedMemoryIndex) {
            fprintf(
                stderr,
                "w2c2: invalid memory.grow instruction: expected memory index %u, got %u\n",
                expectedMemoryIndex,
                instruction.memoryIndex
            );
            return false;
        }
    }

    if (!writer->ignore) {
        static const WasmValueType resultType = wasmValueTypeI32;

        {
            const U32 stackIndex0 = wasmTypeStackGetTopIndex(writer->typeStack, 0);
            MUST (wasmTypeStackSet(writer->stackDeclarations, stackIndex0, resultType))

            MUST (wasmCWriteIndent(writer))
            MUST (wasmCWriteStringStackName(writer->builder, stackIndex0, resultType))
            MUST (wasmCWriteAssign(writer))
            MUST (wasmCWrite(writer, "wasmMemoryGrow("))
            MUST (wasmCWriteStringMemoryUse(
                writer->builder,
                writer->module,
                instruction.memoryIndex,
                true
            ))
            MUST (wasmCWriteComma(writer))
            MUST (wasmCWriteStringStackName(
                writer->builder,
                stackIndex0,
                writer->typeStack->valueTypes[stackIndex0]
            ))
            MUST (wasmCWrite(writer, ");\n"))
        }
    }

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteMemoryInitExpr(
    const WasmCFunctionWriter* writer
) {
    WasmMemoryInitInstruction instruction;
    if (!wasmMemoryInitInstructionRead(writer->code, &instruction)) {
        fprintf(stderr, "w2c2: invalid memory.init instruction encoding\n");
        return false;
    }

    if (!writer->ignore) {
        const U32 stackIndex0 = wasmTypeStackGetTopIndex(writer->typeStack, 0);
        const U32 stackIndex1 = wasmTypeStackGetTopIndex(writer->typeStack, 1);
        const U32 stackIndex2 = wasmTypeStackGetTopIndex(writer->typeStack, 2);

        MUST (wasmCWriteIndent(writer))
        MUST (wasmCWrite(writer, "LOAD_DATA("))
        MUST (wasmCWriteStringMemoryUse(
            writer->builder,
            writer->module,
            instruction.memoryIndex,
            false
        ))
        MUST (wasmCWriteComma(writer))
        MUST (wasmCWriteStringStackName(
            writer->builder,
            stackIndex2,
            writer->typeStack->valueTypes[stackIndex2]
        ))
        MUST (wasmCWriteComma(writer))
        /* TODO: add support for multiple modules */
        MUST (wasmCWriteStringDataSegmentName(writer->builder, instruction.dataSegmentIndex))
        MUST (wasmCWriteChar(writer, '+'))
        MUST (wasmCWriteStringStackName(
            writer->builder,
            stackIndex1,
            writer->typeStack->valueTypes[stackIndex1]
        ))
        MUST (wasmCWriteComma(writer))
        MUST (wasmCWriteStringStackName(
            writer->builder,
            stackIndex0,
            writer->typeStack->valueTypes[stackIndex0]
        ))
        MUST (wasmCWrite(writer, ");\n"))

        wasmTypeStackDrop(writer->typeStack, 3);
    }

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteMemoryCopyExpr(
    const WasmCFunctionWriter* writer
) {
    WasmMemoryCopyInstruction instruction;
    if (!wasmMemoryCopyInstructionRead(writer->code, &instruction)) {
        fprintf(stderr, "w2c2: invalid memory.copy instruction encoding\n");
        return false;
    }

    /* Validate */
    {
        static const U32 expectedMemoryIndex = 0;
        if (instruction.memoryIndex1 != expectedMemoryIndex) {
            fprintf(
                stderr,
                "w2c2: invalid memory.copy instruction: expected memory index 1 to be %u, got %u\n",
                expectedMemoryIndex,
                instruction.memoryIndex1
            );
            return false;
        }

        if (instruction.memoryIndex2 != expectedMemoryIndex) {
            fprintf(
                stderr,
                "w2c2: invalid memory.copy instruction: expected memory index 2 to be %u, got %u\n",
                expectedMemoryIndex,
                instruction.memoryIndex2
            );
            return false;
        }
    }

    if (!writer->ignore) {
        const U32 stackIndex0 = wasmTypeStackGetTopIndex(writer->typeStack, 0);
        const U32 stackIndex1 = wasmTypeStackGetTopIndex(writer->typeStack, 1);
        const U32 stackIndex2 = wasmTypeStackGetTopIndex(writer->typeStack, 2);

        MUST (wasmCWriteIndent(writer))
        MUST (wasmCWrite(writer, "wasmMemoryCopy("))
        MUST (wasmCWriteStringMemoryUse(
            writer->builder,
            writer->module,
            instruction.memoryIndex1,
            true
        ))
        MUST (wasmCWriteComma(writer))
        MUST (wasmCWriteStringMemoryUse(
            writer->builder,
            writer->module,
            instruction.memoryIndex2,
            true
        ))
        MUST (wasmCWriteComma(writer))
        MUST (wasmCWriteStringStackName(
            writer->builder,
            stackIndex2,
            writer->typeStack->valueTypes[stackIndex2]
        ))
        MUST (wasmCWriteComma(writer))
        MUST (wasmCWriteStringStackName(
            writer->builder,
            stackIndex1,
            writer->typeStack->valueTypes[stackIndex1]
        ))
        MUST (wasmCWriteComma(writer))
        MUST (wasmCWriteStringStackName(
            writer->builder,
            stackIndex0,
            writer->typeStack->valueTypes[stackIndex0]
        ))
        MUST (wasmCWrite(writer, ");\n"))

        wasmTypeStackDrop(writer->typeStack, 3);
    }

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteMemoryFillExpr(
    const WasmCFunctionWriter* writer,
    const WasmMiscOpcode miscOpcode
) {
    WasmMemoryInstruction instruction;
    if (!wasmMemoryInstructionRead(writer->code, &instruction)) {
        fprintf(stderr, "w2c2: invalid memory.fill instruction encoding\n");
        return false;
    }

    {
        static const U32 expectedMemoryIndex = 0;
        if (instruction.memoryIndex != expectedMemoryIndex) {
            fprintf(
                stderr,
                "w2c2: invalid memory.fill instruction: expected memory index %u, got %u\n",
                expectedMemoryIndex,
                instruction.memoryIndex
            );
            return false;
        }
    }

    if (!writer->ignore) {
        const U32 stackIndex0 = wasmTypeStackGetTopIndex(writer->typeStack, 0);
        const U32 stackIndex1 = wasmTypeStackGetTopIndex(writer->typeStack, 1);
        const U32 stackIndex2 = wasmTypeStackGetTopIndex(writer->typeStack, 2);

        MUST (wasmCWriteIndent(writer))
        MUST (wasmCWrite(writer, "wasmMemoryFill("))
        MUST (wasmCWriteStringMemoryUse(
            writer->builder,
            writer->module,
            instruction.memoryIndex,
            true
        ))
        MUST (wasmCWriteComma(writer))
        MUST (wasmCWriteStringStackName(
            writer->builder,
            stackIndex2,
            writer->typeStack->valueTypes[stackIndex2]
        ))
        MUST (wasmCWriteComma(writer))
        MUST (wasmCWriteStringStackName(
            writer->builder,
            stackIndex1,
            writer->typeStack->valueTypes[stackIndex1]
        ))
        MUST (wasmCWriteComma(writer))
        MUST (wasmCWriteStringStackName(
            writer->builder,
            stackIndex0,
            writer->typeStack->valueTypes[stackIndex0]
        ))
        MUST (wasmCWrite(writer, ");\n"))

        wasmTypeStackDrop(writer->typeStack, 3);
    }

    return true;
}


static
bool
WARN_UNUSED_RESULT
wasmCWriteUnaryExpr(
    const WasmCFunctionWriter* writer,
    const WasmValueType resultType,
    const char* operator
) {
    const U32 stackIndex0 = wasmTypeStackGetTopIndex(writer->typeStack, 0);

    MUST (wasmTypeStackSet(writer->stackDeclarations, stackIndex0, resultType))

    MUST (wasmCWriteIndent(writer))
    MUST (wasmCWriteStringStackName(writer->builder, stackIndex0, resultType))
    MUST (wasmCWriteAssign(writer))
    MUST (wasmCWrite(writer, operator))
    MUST (wasmCWriteChar(writer, '('))
    MUST (wasmCWriteStringStackName(
        writer->builder,
        stackIndex0,
        writer->typeStack->valueTypes[stackIndex0]
    ))
    MUST (wasmCWrite(writer, ");\n"))

    wasmTypeStackDrop(writer->typeStack, 1);
    MUST (wasmTypeStackAppend(writer->typeStack, resultType))

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteInfixBinaryExpr(
    const WasmCFunctionWriter* writer,
    const WasmValueType resultType,
    const char* operator,
    const bool assignmentAllowed
) {
    const U32 stackIndex1 = wasmTypeStackGetTopIndex(writer->typeStack, 1);
    const U32 stackIndex0 = wasmTypeStackGetTopIndex(writer->typeStack, 0);

    MUST (wasmTypeStackSet(writer->stackDeclarations, stackIndex1, resultType))

    MUST (wasmCWriteIndent(writer))
    MUST (wasmCWriteStringStackName(writer->builder, stackIndex1, resultType))

    if (assignmentAllowed) {
        if (writer->pretty) {
            MUST (wasmCWriteChar(writer, ' '))
        }
        MUST (wasmCWrite(writer, operator))
        MUST (wasmCWriteChar(writer, '='))
        if (writer->pretty) {
            MUST (wasmCWriteChar(writer, ' '))
        }
    } else {
        MUST (wasmCWriteAssign(writer))
        MUST (wasmCWriteStringStackName(
            writer->builder,
            stackIndex1,
            writer->typeStack->valueTypes[stackIndex1]
        ))
        MUST (wasmCWriteChar(writer, ' '))
        MUST (wasmCWrite(writer, operator))
        MUST (wasmCWriteChar(writer, ' '))
    }
    MUST (wasmCWriteStringStackName(
        writer->builder,
        stackIndex0,
        writer->typeStack->valueTypes[stackIndex0]
    ))
    MUST (wasmCWrite(writer, ";\n"))

    wasmTypeStackDrop(writer->typeStack, 2);

    MUST (wasmTypeStackAppend(writer->typeStack, resultType))

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteSignedInfixBinaryExpr(
    const WasmCFunctionWriter* writer,
    const WasmOpcode opcode,
    const char* operator
) {
    const WasmValueType resultType = wasmOpcodeResultType(opcode);
    const WasmValueType parameter1Type = wasmOpcodeParameter1Type(opcode);

    const U32 stackIndex1 = wasmTypeStackGetTopIndex(writer->typeStack, 1);
    const U32 stackIndex0 = wasmTypeStackGetTopIndex(writer->typeStack, 0);

    MUST (wasmTypeStackSet(writer->stackDeclarations, stackIndex1, resultType))

    MUST (wasmCWriteIndent(writer))
    MUST (wasmCWriteStringStackName(writer->builder, stackIndex1, resultType))
    if (writer->pretty) {
        MUST (wasmCWrite(writer, " = ("))
    } else {
        MUST (wasmCWrite(writer, "=("))
    }
    MUST (wasmCWrite(writer, valueTypeNames[parameter1Type]))
    MUST (wasmCWrite(writer, ")(("))
    MUST (wasmCWrite(writer, signedTypeNames[parameter1Type]))
    MUST (wasmCWriteChar(writer, ')'))
    MUST (wasmCWriteStringStackName(
        writer->builder,
        stackIndex1,
        writer->typeStack->valueTypes[stackIndex1]
    ))
    if (writer->pretty) {
        MUST (wasmCWriteChar(writer, ' '))
    }
    MUST (wasmCWrite(writer, operator))
    if (writer->pretty) {
        MUST (wasmCWrite(writer, " ("))
    } else {
        MUST (wasmCWriteChar(writer, '('))
    }
    MUST (wasmCWrite(writer, signedTypeNames[parameter1Type]))
    MUST (wasmCWriteChar(writer, ')'))
    MUST (wasmCWriteStringStackName(
        writer->builder,
        stackIndex0,
        writer->typeStack->valueTypes[stackIndex0]
    ))
    MUST (wasmCWrite(writer, ");\n"))

    wasmTypeStackDrop(writer->typeStack, 2);
    MUST (wasmTypeStackAppend(writer->typeStack, resultType))

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWritePrefixBinaryExpr(
    const WasmCFunctionWriter* writer,
    const WasmValueType resultType,
    const char* operator
) {
    const U32 stackIndex1 = wasmTypeStackGetTopIndex(writer->typeStack, 1);
    const U32 stackIndex0 = wasmTypeStackGetTopIndex(writer->typeStack, 0);

    MUST (wasmTypeStackSet(writer->stackDeclarations, stackIndex1, resultType))

    MUST (wasmCWriteIndent(writer))
    MUST (wasmCWriteStringStackName(writer->builder, stackIndex1, resultType))
    MUST (wasmCWriteAssign(writer))
    MUST (wasmCWrite(writer, operator))
    MUST (wasmCWriteChar(writer, '('))
    MUST (wasmCWriteStringStackName(
        writer->builder,
        stackIndex1,
        writer->typeStack->valueTypes[stackIndex1]
    ))
    MUST (wasmCWriteComma(writer))
    MUST (wasmCWriteStringStackName(
        writer->builder,
        stackIndex0,
        writer->typeStack->valueTypes[stackIndex0]
    ))
    MUST (wasmCWrite(writer, ");\n"))

    wasmTypeStackDrop(writer->typeStack, 2);
    MUST (wasmTypeStackAppend(writer->typeStack, resultType))

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteSignedShiftRightExpr(
    const WasmCFunctionWriter* writer,
    const WasmOpcode opcode
) {
    const WasmValueType resultType = wasmOpcodeResultType(opcode);

    const U32 stackIndex1 = wasmTypeStackGetTopIndex(writer->typeStack, 1);
    const U32 stackIndex0 = wasmTypeStackGetTopIndex(writer->typeStack, 0);

    MUST (wasmTypeStackSet(
        writer->stackDeclarations,
        stackIndex1,
        writer->typeStack->valueTypes[stackIndex1]
    ))

    MUST (wasmCWriteIndent(writer))
    MUST (wasmCWriteStringStackName(
        writer->builder,
        stackIndex1,
        writer->typeStack->valueTypes[stackIndex1]
    ))
    if (writer->pretty) {
        MUST (wasmCWrite(writer, " = ("))
    } else {
        MUST (wasmCWrite(writer, "=("))
    }
    MUST (wasmCWrite(writer, valueTypeNames[resultType]))
    MUST (wasmCWrite(writer, ")(("))
    MUST (wasmCWrite(writer, signedTypeNames[resultType]))
    MUST (wasmCWriteChar(writer, ')'))
    MUST (wasmCWriteStringStackName(
        writer->builder,
        stackIndex1,
        writer->typeStack->valueTypes[stackIndex1]
    ))
    if (writer->pretty) {
        MUST (wasmCWrite(writer, " >> ("))
    } else {
        MUST (wasmCWrite(writer, ">>("))
    }
    MUST (wasmCWriteStringStackName(
        writer->builder,
        stackIndex0,
        writer->typeStack->valueTypes[stackIndex0]
    ))
    if (writer->pretty) {
        MUST (wasmCWrite(writer, " & "))
    } else {
        MUST (wasmCWriteChar(writer, '&'))
    }
    MUST (wasmCWrite(writer, shiftMaskStrings[resultType]))
    MUST (wasmCWrite(writer, "));\n"))

    wasmTypeStackDrop(writer->typeStack, 1);

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteUnsignedShiftRightExpr(
    const WasmCFunctionWriter* writer,
    const WasmOpcode opcode
) {
    const WasmValueType resultType = wasmOpcodeResultType(opcode);

    const U32 stackIndex1 = wasmTypeStackGetTopIndex(writer->typeStack, 1);
    const U32 stackIndex0 = wasmTypeStackGetTopIndex(writer->typeStack, 0);

    MUST (wasmTypeStackSet(
        writer->stackDeclarations,
        stackIndex1,
        writer->typeStack->valueTypes[stackIndex1]
    ))

    MUST (wasmCWriteIndent(writer))
    MUST (wasmCWriteStringStackName(
        writer->builder,
        stackIndex1,
        writer->typeStack->valueTypes[stackIndex1]
    ))
    if (writer->pretty) {
        MUST (wasmCWrite(writer, " >>= ("))
    } else {
        MUST (wasmCWrite(writer, ">>=("))
    }
    MUST (wasmCWriteStringStackName(
        writer->builder,
        stackIndex0,
        writer->typeStack->valueTypes[stackIndex0]
    ))
    if (writer->pretty) {
        MUST (wasmCWrite(writer, " & "))
    } else {
        MUST (wasmCWriteChar(writer, '&'))
    }
    MUST (wasmCWrite(writer, shiftMaskStrings[resultType]))
    MUST (wasmCWrite(writer, ");\n"))

    wasmTypeStackDrop(writer->typeStack, 1);

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteShiftLeftExpr(
    const WasmCFunctionWriter* writer,
    const WasmOpcode opcode
) {
    const WasmValueType resultType = wasmOpcodeResultType(opcode);

    const U32 stackIndex1 = wasmTypeStackGetTopIndex(writer->typeStack, 1);
    const U32 stackIndex0 = wasmTypeStackGetTopIndex(writer->typeStack, 0);

    MUST (wasmTypeStackSet(
        writer->stackDeclarations,
        stackIndex1,
        writer->typeStack->valueTypes[stackIndex1]
    ))

    MUST (wasmCWriteIndent(writer))
    MUST (wasmCWriteStringStackName(
        writer->builder,
        stackIndex1,
        writer->typeStack->valueTypes[stackIndex1]
    ))
    if (writer->pretty) {
        MUST (wasmCWrite(writer, " <<= ("))
    } else {
        MUST (wasmCWrite(writer, "<<=("))
    }
    MUST (wasmCWriteStringStackName(
        writer->builder,
        stackIndex0,
        writer->typeStack->valueTypes[stackIndex0]
    ))
    if (writer->pretty) {
        MUST (wasmCWrite(writer, " & "))
    } else {
        MUST (wasmCWriteChar(writer, '&'))
    }
    MUST (wasmCWrite(writer, shiftMaskStrings[resultType]))
    MUST (wasmCWrite(writer, ");\n"))

    wasmTypeStackDrop(writer->typeStack, 1);

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteLabel(
    const WasmCFunctionWriter* writer,
    const U32 labelIndex
) {
    MUST (wasmCWriteIndent(writer))
    MUST (wasmCWriteStringLabelName(writer->builder, labelIndex))
    MUST (wasmCWrite(writer, ":;\n"))

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteIfExpr(
    WasmCFunctionWriter* writer,
    WasmOpcode* opcode
) {
    const bool ignore = writer->ignore;

    size_t typeStackLengthBeforeBranches = 0;
    WasmLabel label = wasmEmptyLabel;

    WasmValueType blockValueType = 0;
    WasmValueType* blockType = &blockValueType;
    if (!wasmReadBlockType(writer->code, &blockType)) {
        fprintf(
            stderr,
            "w2c2: invalid %s instruction: expected block type\n",
            wasmOpcodeDescription(*opcode)
        );
        return false;
    }

    if (!ignore) {
        MUST (wasmCWriteIndent(writer))
        if (writer->pretty) {
            MUST (wasmCWrite(writer, "if ("))
        } else {
            MUST (wasmCWrite(writer, "if("))
        }
        {
            const U32 stackIndex0 = wasmTypeStackGetTopIndex(writer->typeStack, 0);
            MUST (wasmCWriteStringStackName(
                writer->builder,
                stackIndex0,
                writer->typeStack->valueTypes[stackIndex0]
            ))
        }
        if (writer->pretty) {
            MUST (wasmCWrite(writer, ") {\n"))
        } else {
            MUST (wasmCWrite(writer, "){\n"))
        }

        wasmTypeStackDrop(writer->typeStack, 1);

        typeStackLengthBeforeBranches = writer->typeStack->length;

        MUST (wasmLabelStackPush(
            writer->labelStack,
            typeStackLengthBeforeBranches,
            blockType,
            &label
        ))

        writer->indent++;
    }

    MUST (wasmCWriteFunctionCode(writer, opcode))

    if (!ignore) {
        writer->ignore = false;

        writer->indent--;

        MUST (wasmCWriteIndent(writer))
        MUST (wasmCWriteChar(writer, '}'))
    }

    if (*opcode == wasmOpcodeElse) {
        if (!ignore) {
            writer->typeStack->length = typeStackLengthBeforeBranches;

            if (writer->pretty) {
                MUST (wasmCWrite(writer, " else {\n"))
            } else {
                MUST (wasmCWrite(writer, "else{\n"))
            }

            writer->indent++;
        }

        MUST (wasmCWriteFunctionCode(writer, opcode))

        if (!ignore) {
            writer->ignore = false;

            writer->indent--;

            MUST (wasmCWriteIndent(writer))
            MUST (wasmCWriteChar(writer, '}'))
        }
    }

    if (!ignore) {
        MUST (wasmCWrite(writer, "\n"))

        MUST (wasmCWriteLabel(writer, label.index))

        writer->typeStack->length = typeStackLengthBeforeBranches;

        wasmLabelStackPop(writer->labelStack);

        if (blockType != NULL) {
            MUST (wasmTypeStackAppend(writer->typeStack, blockValueType))
        }
    }

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteBlockExpr(
    WasmCFunctionWriter* writer,
    WasmOpcode* opcode
) {
    const bool ignore = writer->ignore;

    size_t typeStackLengthBeforeBranches = 0;
    WasmLabel label = wasmEmptyLabel;

    WasmValueType blockValueType = 0;
    WasmValueType* blockType = &blockValueType;
    if (!wasmReadBlockType(writer->code, &blockType)) {
        fprintf(
            stderr,
            "w2c2: invalid %s instruction: expected block type\n",
            wasmOpcodeDescription(*opcode)
        );
        return false;
    }

    if (!ignore) {
        typeStackLengthBeforeBranches = writer->typeStack->length;

        MUST (wasmLabelStackPush(
            writer->labelStack,
            typeStackLengthBeforeBranches,
            blockType,
            &label
        ))

        if (writer->pretty) {
            MUST (wasmCWriteIndent(writer))
            MUST (wasmCWrite(writer, "{\n"))
            writer->indent++;
        }
    }

    MUST (wasmCWriteFunctionCode(writer, opcode))

    if (!ignore) {
        writer->ignore = false;

        if (writer->pretty) {
            writer->indent--;

            MUST (wasmCWriteIndent(writer))
            MUST (wasmCWrite(writer, "}\n"))
        }

        MUST (wasmCWriteLabel(writer, label.index))

        writer->typeStack->length = typeStackLengthBeforeBranches;

        wasmLabelStackPop(writer->labelStack);

        if (blockType != NULL) {
            MUST (wasmTypeStackAppend(writer->typeStack, blockValueType))
        }
    }

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteLoopExpr(
    WasmCFunctionWriter* writer,
    WasmOpcode* opcode
) {
    const bool ignore = writer->ignore;

    size_t typeStackLengthBeforeBranches = 0;
    WasmLabel label = wasmEmptyLabel;

    WasmValueType blockValueType = 0;
    WasmValueType* blockType = &blockValueType;
    if (!wasmReadBlockType(writer->code, &blockType)) {
        fprintf(
            stderr,
            "w2c2: invalid %s instruction: expected block type\n",
            wasmOpcodeDescription(*opcode)
       );
        return false;
    }

    if (!ignore) {
        typeStackLengthBeforeBranches = writer->typeStack->length;

        MUST (wasmLabelStackPush(
            writer->labelStack,
            typeStackLengthBeforeBranches,
            /* NOTE: ignoring block type (result type) */
            NULL,
            &label
        ))

        MUST (wasmCWriteLabel(writer, label.index))

        MUST (wasmCWriteIndent(writer))
        MUST (wasmCWrite(writer, "{\n"))

        writer->indent++;
    }

    MUST (wasmCWriteFunctionCode(writer, opcode))

    if (!ignore) {
        writer->ignore = false;

        writer->indent--;

        MUST (wasmCWriteIndent(writer))
        MUST (wasmCWrite(writer, "}\n"))

        writer->typeStack->length = typeStackLengthBeforeBranches;

        wasmLabelStackPop(writer->labelStack);

        if (blockType != NULL) {
            MUST (wasmTypeStackAppend(writer->typeStack, blockValueType))
        }
    }

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteGoto(
    const WasmCFunctionWriter* writer,
    const U32 labelStackIndex
) {
    const WasmLabel label = writer->labelStack->labels.labels[labelStackIndex];

    MUST (wasmCWriteIndent(writer))

    if (label.type != NULL) {
        const WasmValueType resultType = *label.type;

        const U32 stackIndex0 = wasmTypeStackGetTopIndex(writer->typeStack, 0);
        const U32 destinationStackIndex = assertSizeU32(label.typeStackLength);

        if (destinationStackIndex != stackIndex0) {

            MUST (wasmTypeStackSet(writer->stackDeclarations, destinationStackIndex, resultType))

            MUST (wasmCWriteStringStackName(writer->builder, destinationStackIndex, resultType))
            MUST (wasmCWriteAssign(writer))
            MUST (wasmCWriteStringStackName(
                writer->builder,
                stackIndex0,
                writer->typeStack->valueTypes[stackIndex0]
            ))
            if (writer->pretty) {
                MUST (wasmCWrite(writer, "; "))
            } else {
                MUST (wasmCWriteChar(writer, ';'))
            }
        }
    }

    MUST (wasmCWrite(writer, "goto "))
    MUST (wasmCWriteStringLabelName(writer->builder, label.index))
    MUST (wasmCWrite(writer, ";\n"))
    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteSelectExpr(
    const WasmCFunctionWriter* writer
) {
    const U32 stackIndex0 = wasmTypeStackGetTopIndex(writer->typeStack, 0);
    const U32 stackIndex1 = wasmTypeStackGetTopIndex(writer->typeStack, 1);
    const U32 stackIndex2 = wasmTypeStackGetTopIndex(writer->typeStack, 2);

    /* same as 2 */
    const WasmValueType resultType = writer->typeStack->valueTypes[stackIndex1];

    MUST (wasmTypeStackSet(writer->stackDeclarations, stackIndex2, resultType))

    MUST (wasmCWriteIndent(writer))
    MUST (wasmCWriteStringStackName(
        writer->builder,
        stackIndex2,
        resultType
    ))
    MUST (wasmCWriteAssign(writer))
    MUST (wasmCWriteStringStackName(
        writer->builder,
        stackIndex0,
        writer->typeStack->valueTypes[stackIndex0]
    ))
    if (writer->pretty) {
        MUST (wasmCWrite(writer, " ? "))
    } else {
        MUST (wasmCWriteChar(writer, '?'))
    }
    MUST (wasmCWriteStringStackName(
        writer->builder,
        stackIndex2,
        writer->typeStack->valueTypes[stackIndex2]
    ))
    if (writer->pretty) {
        MUST (wasmCWrite(writer, " : "))
    } else {
        MUST (wasmCWriteChar(writer, ':'))
    }
    MUST (wasmCWriteStringStackName(
        writer->builder,
        stackIndex1,
        writer->typeStack->valueTypes[stackIndex1]
    ))
    MUST (wasmCWrite(writer, ";\n"))

    wasmTypeStackDrop(writer->typeStack, 3);

    MUST (wasmTypeStackAppend(writer->typeStack, resultType))

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteBranchExpr(
    const WasmCFunctionWriter* writer
) {
    WasmBranchInstruction instruction;
    if (!wasmBranchInstructionRead(writer->code, &instruction)) {
        fprintf(stderr, "w2c2: invalid br instruction encoding\n");
        return false;
    }

    if (!writer->ignore) {
        const U32 labelIndex = wasmLabelStackGetTopIndex(writer->labelStack, instruction.labelIndex);
        MUST (wasmCWriteGoto(writer, labelIndex))
    }

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteBranchIfExpr(
    WasmCFunctionWriter* writer
) {
    WasmBranchInstruction instruction;
    if (!wasmBranchInstructionRead(writer->code, &instruction)) {
        fprintf(stderr, "w2c2: invalid br.if instruction encoding\n");
        return false;
    }

    if (!writer->ignore) {

        const U32 stackIndex0 = wasmTypeStackGetTopIndex(writer->typeStack, 0);
        MUST (wasmCWriteIndent(writer))
        if (writer->pretty) {
            MUST (wasmCWrite(writer, "if ("))
        } else {
            MUST (wasmCWrite(writer, "if("))
        }
        MUST (wasmCWriteStringStackName(
            writer->builder,
            stackIndex0,
            writer->typeStack->valueTypes[stackIndex0]
        ))
        if (writer->pretty) {
            MUST (wasmCWrite(writer, ") {\n"))
        } else {
            MUST (wasmCWrite(writer, "){\n"))
        }

        writer->indent++;

        wasmTypeStackDrop(writer->typeStack, 1);

        {
            const U32 labelIndex = wasmLabelStackGetTopIndex(writer->labelStack, instruction.labelIndex);
            MUST (wasmCWriteGoto(writer, labelIndex))
        }

        writer->indent--;
        MUST (wasmCWriteIndent(writer))
        MUST (wasmCWrite(writer, "}\n"))
    }

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteBranchTableExpr(
    WasmCFunctionWriter* writer
) {
    WasmBranchTableInstruction instruction;
    if (!wasmBranchTableInstructionRead(writer->code, &instruction)) {
        fprintf(stderr, "w2c2: invalid br_table instruction encoding\n");
        return false;
    }

    if (!writer->ignore) {
        const U32 stackIndex0 = wasmTypeStackGetTopIndex(writer->typeStack, 0);

        MUST (wasmCWriteIndent(writer))
        if (writer->pretty) {
            MUST (wasmCWrite(writer, "switch ("))
        } else {
            MUST (wasmCWrite(writer, "switch("))
        }
        MUST (wasmCWriteStringStackName(
            writer->builder,
            stackIndex0,
            writer->typeStack->valueTypes[stackIndex0]
        ))
        if (writer->pretty) {
            MUST (wasmCWrite(writer, ") {\n"))
        } else {
            MUST (wasmCWrite(writer, "){\n"))
        }

        wasmTypeStackDrop(writer->typeStack, 1);

        {
            U32 index = 0;
            for (; index < instruction.labelIndexCount; index++) {
                MUST (wasmCWriteIndent(writer))
                MUST (wasmCWrite(writer, "case "))
                MUST (stringBuilderAppendU32(writer->builder, index))
                MUST (wasmCWrite(writer, ":\n"))
                writer->indent++;
                {
                    const U32 labelIndex = wasmLabelStackGetTopIndex(
                        writer->labelStack,
                        instruction.labelIndices[index]
                    );
                    MUST (wasmCWriteGoto(writer, labelIndex))
                }
                writer->indent--;
            }
        }

        MUST (wasmCWriteIndent(writer))
        MUST (wasmCWrite(writer, "default:\n"))
        writer->indent++;
        {
            const U32 labelIndex = wasmLabelStackGetTopIndex(
                writer->labelStack,
                instruction.defaultLabelIndex
            );
            MUST (wasmCWriteGoto(writer, labelIndex))
        }
        writer->indent--;

        MUST (wasmCWriteIndent(writer))
        MUST (wasmCWrite(writer, "}\n"))
    }

    wasmBranchTableInstructionFree(instruction);

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteDebugLine(
    StringBuilder* builder,
    const WasmDebugLine* debugLine

) {
    MUST (stringBuilderAppend(builder, "#line "))
    MUST (stringBuilderAppendU64(builder, debugLine->number))
    MUST (stringBuilderAppend(builder, " \""))
    MUST (stringBuilderAppend(builder, debugLine->path))
    MUST (stringBuilderAppend(builder, "\"\n"))
    return true;
}


static
WasmDebugLine*
wasmCGetDebugLine(
    WasmDebugLines* debugLines,
    const size_t absoluteAddress
) {
    WasmDebugLine* debugLine = NULL;
    if (debugLines->length == 0) {
        return NULL;
    }

    debugLine = debugLines->debugLines;

    if (debugLines->length > 1) {
        const WasmDebugLine* nextDebugLine = debugLine + 1;
        if (absoluteAddress >= nextDebugLine->address) {
            debugLines->length--;
            debugLines->debugLines++;
            debugLine = debugLines->debugLines;
        }
    }

    if (absoluteAddress < debugLine->address) {
       return NULL;
    }

    return debugLine;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteMemoryAtomicNotifyExpr(
    const WasmCFunctionWriter* writer
) {
    static const WasmThreadsOpcode opcode = wasmThreadsOpcodeMemoryAtomicNotify;

    WasmMemoryArgumentInstruction instruction;

    if (!wasmMemoryArgument32InstructionRead(writer->code, &instruction)) {
        fprintf(
            stderr,
            "w2c2: invalid %s instruction encoding\n",
            wasmThreadsOpcodeDescription(opcode)
        );
        return false;
    }

    if (!writer->ignore) {
        const U32 stackIndex0 = wasmTypeStackGetTopIndex(writer->typeStack, 0);
        const U32 stackIndex1 = wasmTypeStackGetTopIndex(writer->typeStack, 1);

        static const WasmValueType resultType = wasmValueTypeI32;

        MUST (wasmTypeStackSet(writer->stackDeclarations, stackIndex1, resultType))

        MUST (wasmCWriteIndent(writer))
        MUST (wasmCWriteStringStackName(writer->builder, stackIndex1, resultType))
        MUST (wasmCWriteAssign(writer))
        MUST (wasmCWrite(writer, "wasmMemoryAtomicNotify("))
        MUST (wasmCWriteStringMemoryUse(
                writer->builder,
                writer->module,
                0,
                true
        ))
        MUST (wasmCWriteComma(writer))
        MUST (wasmCWriteStringStackName(
                writer->builder,
                stackIndex1,
                writer->typeStack->valueTypes[stackIndex1]
        ))
        MUST (wasmCWriteComma(writer))
        MUST (wasmCWriteStringStackName(
                writer->builder,
                stackIndex0,
                writer->typeStack->valueTypes[stackIndex0]
        ))
        MUST (wasmCWrite(writer, ");\n"))

        wasmTypeStackDrop(writer->typeStack, 2);

        MUST (wasmTypeStackAppend(writer->typeStack, resultType))
    }

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteMemoryAtomicWaitExpr(
    const WasmCFunctionWriter* writer,
    const bool isWait64
) {
    if (!writer->ignore) {
        const U32 stackIndex0 = wasmTypeStackGetTopIndex(writer->typeStack, 0);
        const U32 stackIndex1 = wasmTypeStackGetTopIndex(writer->typeStack, 1);
        const U32 stackIndex2 = wasmTypeStackGetTopIndex(writer->typeStack, 2);

        static const WasmValueType resultType = wasmValueTypeI32;

        MUST (wasmTypeStackSet(writer->stackDeclarations, stackIndex2, resultType))

        MUST (wasmCWriteIndent(writer))
        MUST (wasmCWriteStringStackName(writer->builder, stackIndex2, resultType))
        MUST (wasmCWriteAssign(writer))
        MUST (wasmCWrite(writer, "wasmMemoryAtomicWait("))
        MUST (wasmCWriteStringMemoryUse(
                writer->builder,
                writer->module,
                0,
                true
        ))
        MUST (wasmCWriteComma(writer))
        MUST (wasmCWriteStringStackName(
                writer->builder,
                stackIndex2,
                writer->typeStack->valueTypes[stackIndex2]
        ))
        MUST (wasmCWriteComma(writer))
        MUST (wasmCWriteStringStackName(
                writer->builder,
                stackIndex1,
                writer->typeStack->valueTypes[stackIndex1]
        ))
        MUST (wasmCWriteComma(writer))
        MUST (wasmCWriteStringStackName(
                writer->builder,
                stackIndex0,
                writer->typeStack->valueTypes[stackIndex0]
        ))
        MUST (wasmCWriteComma(writer))
        MUST (wasmCWrite(writer, isWait64 ? "true" : "false"))
        MUST (wasmCWrite(writer, ");\n"))

        wasmTypeStackDrop(writer->typeStack, 3);

        MUST (wasmTypeStackAppend(writer->typeStack, resultType))
    }

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteMemoryAtomicWait32Expr(
    const WasmCFunctionWriter* writer
) {
    static const WasmThreadsOpcode opcode = wasmThreadsOpcodeMemoryAtomicWait32;

    WasmMemoryArgumentInstruction instruction;

    if (!wasmMemoryArgument32InstructionRead(writer->code, &instruction)) {
        fprintf(
            stderr,
            "w2c2: invalid %s instruction encoding\n",
            wasmThreadsOpcodeDescription(opcode)
        );
        return false;
    }

    MUST (wasmCWriteMemoryAtomicWaitExpr(writer, false))

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteMemoryAtomicWait64Expr(
    const WasmCFunctionWriter* writer
) {
    static const WasmThreadsOpcode opcode = wasmThreadsOpcodeMemoryAtomicWait64;

    WasmMemoryArgumentInstruction instruction;

    if (!wasmMemoryArgument64InstructionRead(writer->code, &instruction)) {
        fprintf(
            stderr,
            "w2c2: invalid %s instruction encoding\n",
            wasmThreadsOpcodeDescription(opcode)
        );
        return false;
    }

    MUST (wasmCWriteMemoryAtomicWaitExpr(writer, true))

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteAtomicFenceExpr(
    const WasmCFunctionWriter* writer
) {
    static const WasmThreadsOpcode opcode = wasmThreadsOpcodeAtomicFence;

    U8 immediate = 0;
    MUST (bufferReadByte(writer->code, &immediate) > 0)
    if (immediate != 0x0) {
        fprintf(
            stderr,
            "w2c2: invalid %s instruction encoding\n",
            wasmThreadsOpcodeDescription(opcode)
        );
        return false;
    }

    if (!writer->ignore) {
        MUST (wasmCWriteIndent(writer))
        MUST (wasmCWrite(writer, "atomic_fence();\n"))
    }

    return true;
}

bool
WARN_UNUSED_RESULT
wasmCWriteAtomicLoadExpr(
    const WasmCFunctionWriter* writer,
    const WasmThreadsOpcode opcode
) {
    WasmMemoryArgumentInstruction instruction;

    if (!wasmMemoryArgumentInstructionRead(writer->code, &instruction)) {
        fprintf(
            stderr,
            "w2c2: invalid %s instruction encoding\n",
            wasmThreadsOpcodeDescription(opcode)
        );
        return false;
    }

    if (!writer->ignore) {
        U32 expectedAlign = 0;
        WasmValueType resultType = 0;
        char* functionName = NULL;
        switch (opcode) {
            case wasmThreadsOpcodeI32AtomicLoad: {
                expectedAlign = WASM_MEMARG32_ALIGN;
                resultType = wasmValueTypeI32;
                functionName = "i32_atomic_load";
                break;
            }
            case wasmThreadsOpcodeI64AtomicLoad: {
                expectedAlign = WASM_MEMARG64_ALIGN;
                resultType = wasmValueTypeI64;
                functionName = "i64_atomic_load";
                break;
            }
            case wasmThreadsOpcodeI32AtomicLoad8U: {
                expectedAlign = WASM_MEMARG8_ALIGN;
                resultType = wasmValueTypeI32;
                functionName = "i32_atomic_load8_u";
                break;
            }
            case wasmThreadsOpcodeI32AtomicLoad16U: {
                expectedAlign = WASM_MEMARG16_ALIGN;
                resultType = wasmValueTypeI32;
                functionName = "i32_atomic_load16_u";
                break;
            }
            case wasmThreadsOpcodeI64AtomicLoad8U: {
                expectedAlign = WASM_MEMARG8_ALIGN;
                resultType = wasmValueTypeI64;
                functionName = "i64_atomic_load8_u";
                break;
            }
            case wasmThreadsOpcodeI64AtomicLoad16U: {
                expectedAlign = WASM_MEMARG16_ALIGN;
                resultType = wasmValueTypeI64;
                functionName = "i64_atomic_load16_u";
                break;
            }
            case wasmThreadsOpcodeI64AtomicLoad32U: {
                expectedAlign = WASM_MEMARG32_ALIGN;
                resultType = wasmValueTypeI64;
                functionName = "i64_atomic_load32_u";
                break;
            }
            default: {
                fprintf(
                    stderr,
                    "w2c2: unsupported atomic load instruction opcode: %s\n",
                    wasmThreadsOpcodeDescription(opcode)
                );
                return false;
            }
        }

        if (instruction.align != expectedAlign) {
            fprintf(
                stderr,
                "w2c2: invalid %s instruction encoding: expected align %d, got %d\n",
                wasmThreadsOpcodeDescription(opcode),
                expectedAlign,
                instruction.align
            );
            return false;
        }

        MUST (wasmCWriteLoad(
            writer,
            instruction,
            functionName,
            resultType
        ))
    }

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteAtomicStoreExpr(
    const WasmCFunctionWriter* writer,
    const WasmThreadsOpcode opcode
) {
    WasmMemoryArgumentInstruction instruction;
    if (!wasmMemoryArgumentInstructionRead(writer->code, &instruction)) {
        fprintf(
            stderr,
            "w2c2: invalid %s instruction encoding\n",
            wasmThreadsOpcodeDescription(opcode)
        );
        return false;
    }

    if (!writer->ignore) {
        U32 expectedAlign = 0;
        char* functionName = NULL;
        switch (opcode) {
            case wasmThreadsOpcodeI32AtomicStore: {
                expectedAlign = WASM_MEMARG32_ALIGN;
                functionName = "i32_atomic_store";
                break;
            }
            case wasmThreadsOpcodeI64AtomicStore: {
                expectedAlign = WASM_MEMARG64_ALIGN;
                functionName = "i64_atomic_store";
                break;
            }
            case wasmThreadsOpcodeI32AtomicStore8: {
                expectedAlign = WASM_MEMARG8_ALIGN;
                functionName = "i32_atomic_store8";
                break;
            }
            case wasmThreadsOpcodeI64AtomicStore8: {
                expectedAlign = WASM_MEMARG8_ALIGN;
                functionName = "i64_atomic_store8";
                break;
            }
            case wasmThreadsOpcodeI32AtomicStore16: {
                expectedAlign = WASM_MEMARG16_ALIGN;
                functionName = "i32_atomic_store16";
                break;
            }
            case wasmThreadsOpcodeI64AtomicStore16: {
                expectedAlign = WASM_MEMARG16_ALIGN;
                functionName = "i64_atomic_store16";
                break;
            }
            case wasmThreadsOpcodeI64AtomicStore32: {
                expectedAlign = WASM_MEMARG32_ALIGN;
                functionName = "i64_atomic_store32";
                break;
            }
            default: {
                fprintf(
                    stderr,
                    "w2c2: unsupported atomic store instruction opcode: %s\n",
                    wasmThreadsOpcodeDescription(opcode)
                );
                return false;
            }
        }

        if (instruction.align != expectedAlign) {
            fprintf(
                stderr,
                "w2c2: invalid %s instruction encoding: expected align %d, got %d\n",
                wasmThreadsOpcodeDescription(opcode),
                expectedAlign,
                instruction.align
            );
            return false;
        }

        MUST (wasmCWriteStore(writer, instruction, functionName))
    }

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteAtomicRMWExpr(
    const WasmCFunctionWriter* writer,
    const WasmThreadsOpcode opcode
) {
    WasmMemoryArgumentInstruction instruction;
    if (!wasmMemoryArgumentInstructionRead(writer->code, &instruction)) {
        fprintf(
            stderr,
            "w2c2: invalid %s instruction encoding\n",
            wasmThreadsOpcodeDescription(opcode)
        );
        return false;
    }

    if (!writer->ignore) {
        U32 expectedAlign = 0;
        WasmValueType resultType = 0;
        char *functionName = NULL;
        switch (opcode) {
            /* Add */
            case wasmThreadsOpcodeI32AtomicRMWAdd: {
                expectedAlign = WASM_MEMARG32_ALIGN;
                resultType = wasmValueTypeI32;
                functionName = "i32_atomic_rmw_add";
                break;
            }
            case wasmThreadsOpcodeI64AtomicRMWAdd: {
                expectedAlign = WASM_MEMARG64_ALIGN;
                resultType = wasmValueTypeI64;
                functionName = "i64_atomic_rmw_add";
                break;
            }
            case wasmThreadsOpcodeI32AtomicRMW8AddU: {
                expectedAlign = WASM_MEMARG8_ALIGN;
                resultType = wasmValueTypeI32;
                functionName = "i32_atomic_rmw8_add_u";
                break;
            }
            case wasmThreadsOpcodeI32AtomicRMW16AddU: {
                expectedAlign = WASM_MEMARG16_ALIGN;
                resultType = wasmValueTypeI32;
                functionName = "i32_atomic_rmw16_add_u";
                break;
            }
            case wasmThreadsOpcodeI64AtomicRMW8AddU: {
                expectedAlign = WASM_MEMARG8_ALIGN;
                resultType = wasmValueTypeI64;
                functionName = "i64_atomic_rmw8_add_u";
                break;
            }
            case wasmThreadsOpcodeI64AtomicRMW16AddU: {
                expectedAlign = WASM_MEMARG16_ALIGN;
                resultType = wasmValueTypeI64;
                functionName = "i64_atomic_rmw16_add_u";
                break;
            }
            case wasmThreadsOpcodeI64AtomicRMW32AddU: {
                expectedAlign = WASM_MEMARG32_ALIGN;
                resultType = wasmValueTypeI64;
                functionName = "i64_atomic_rmw32_add_u";
                break;
            }
            /* Sub */
            case wasmThreadsOpcodeI32AtomicRMWSub: {
                expectedAlign = WASM_MEMARG32_ALIGN;
                resultType = wasmValueTypeI32;
                functionName = "i32_atomic_rmw_sub";
                break;
            }
            case wasmThreadsOpcodeI64AtomicRMWSub: {
                expectedAlign = WASM_MEMARG64_ALIGN;
                resultType = wasmValueTypeI64;
                functionName = "i64_atomic_rmw_sub";
                break;
            }
            case wasmThreadsOpcodeI32AtomicRMW8SubU: {
                expectedAlign = WASM_MEMARG8_ALIGN;
                resultType = wasmValueTypeI32;
                functionName = "i32_atomic_rmw8_sub_u";
                break;
            }
            case wasmThreadsOpcodeI32AtomicRMW16SubU: {
                expectedAlign = WASM_MEMARG16_ALIGN;
                resultType = wasmValueTypeI32;
                functionName = "i32_atomic_rmw16_sub_u";
                break;
            }
            case wasmThreadsOpcodeI64AtomicRMW8SubU: {
                expectedAlign = WASM_MEMARG8_ALIGN;
                resultType = wasmValueTypeI64;
                functionName = "i64_atomic_rmw8_sub_u";
                break;
            }
            case wasmThreadsOpcodeI64AtomicRMW16SubU: {
                expectedAlign = WASM_MEMARG16_ALIGN;
                resultType = wasmValueTypeI64;
                functionName = "i64_atomic_rmw16_sub_u";
                break;
            }
            case wasmThreadsOpcodeI64AtomicRMW32SubU: {
                expectedAlign = WASM_MEMARG32_ALIGN;
                resultType = wasmValueTypeI64;
                functionName = "i64_atomic_rmw32_sub_u";
                break;
            }
            /* And */
            case wasmThreadsOpcodeI32AtomicRMWAnd: {
                expectedAlign = WASM_MEMARG32_ALIGN;
                resultType = wasmValueTypeI32;
                functionName = "i32_atomic_rmw_and";
                break;
            }
            case wasmThreadsOpcodeI64AtomicRMWAnd: {
                expectedAlign = WASM_MEMARG64_ALIGN;
                resultType = wasmValueTypeI64;
                functionName = "i64_atomic_rmw_and";
                break;
            }
            case wasmThreadsOpcodeI32AtomicRMW8AndU: {
                expectedAlign = WASM_MEMARG8_ALIGN;
                resultType = wasmValueTypeI32;
                functionName = "i32_atomic_rmw8_and_u";
                break;
            }
            case wasmThreadsOpcodeI32AtomicRMW16AndU: {
                expectedAlign = WASM_MEMARG16_ALIGN;
                resultType = wasmValueTypeI32;
                functionName = "i32_atomic_rmw16_and_u";
                break;
            }
            case wasmThreadsOpcodeI64AtomicRMW8AndU: {
                expectedAlign = WASM_MEMARG8_ALIGN;
                resultType = wasmValueTypeI64;
                functionName = "i64_atomic_rmw8_and_u";
                break;
            }
            case wasmThreadsOpcodeI64AtomicRMW16AndU: {
                expectedAlign = WASM_MEMARG16_ALIGN;
                resultType = wasmValueTypeI64;
                functionName = "i64_atomic_rmw16_and_u";
                break;
            }
            case wasmThreadsOpcodeI64AtomicRMW32AndU: {
                expectedAlign = WASM_MEMARG32_ALIGN;
                resultType = wasmValueTypeI64;
                functionName = "i64_atomic_rmw32_and_u";
                break;
            }
            /* Or */
            case wasmThreadsOpcodeI32AtomicRMWOr: {
                expectedAlign = WASM_MEMARG32_ALIGN;
                resultType = wasmValueTypeI32;
                functionName = "i32_atomic_rmw_or";
                break;
            }
            case wasmThreadsOpcodeI64AtomicRMWOr: {
                expectedAlign = WASM_MEMARG64_ALIGN;
                resultType = wasmValueTypeI64;
                functionName = "i64_atomic_rmw_or";
                break;
            }
            case wasmThreadsOpcodeI32AtomicRMW8OrU: {
                expectedAlign = WASM_MEMARG8_ALIGN;
                resultType = wasmValueTypeI32;
                functionName = "i32_atomic_rmw8_or_u";
                break;
            }
            case wasmThreadsOpcodeI32AtomicRMW16OrU: {
                expectedAlign = WASM_MEMARG16_ALIGN;
                resultType = wasmValueTypeI32;
                functionName = "i32_atomic_rmw16_or_u";
                break;
            }
            case wasmThreadsOpcodeI64AtomicRMW8OrU: {
                expectedAlign = WASM_MEMARG8_ALIGN;
                resultType = wasmValueTypeI64;
                functionName = "i64_atomic_rmw8_or_u";
                break;
            }
            case wasmThreadsOpcodeI64AtomicRMW16OrU: {
                expectedAlign = WASM_MEMARG16_ALIGN;
                resultType = wasmValueTypeI64;
                functionName = "i64_atomic_rmw16_or_u";
                break;
            }
            case wasmThreadsOpcodeI64AtomicRMW32OrU: {
                expectedAlign = WASM_MEMARG32_ALIGN;
                resultType = wasmValueTypeI64;
                functionName = "i64_atomic_rmw32_or_u";
                break;
            }
            /* Xor */
            case wasmThreadsOpcodeI32AtomicRMWXor: {
                expectedAlign = WASM_MEMARG32_ALIGN;
                resultType = wasmValueTypeI32;
                functionName = "i32_atomic_rmw_xor";
                break;
            }
            case wasmThreadsOpcodeI64AtomicRMWXor: {
                expectedAlign = WASM_MEMARG64_ALIGN;
                resultType = wasmValueTypeI64;
                functionName = "i64_atomic_rmw_xor";
                break;
            }
            case wasmThreadsOpcodeI32AtomicRMW8XorU: {
                expectedAlign = WASM_MEMARG8_ALIGN;
                resultType = wasmValueTypeI32;
                functionName = "i32_atomic_rmw8_xor_u";
                break;
            }
            case wasmThreadsOpcodeI32AtomicRMW16XorU: {
                expectedAlign = WASM_MEMARG16_ALIGN;
                resultType = wasmValueTypeI32;
                functionName = "i32_atomic_rmw16_xor_u";
                break;
            }
            case wasmThreadsOpcodeI64AtomicRMW8XorU: {
                expectedAlign = WASM_MEMARG8_ALIGN;
                resultType = wasmValueTypeI64;
                functionName = "i64_atomic_rmw8_xor_u";
                break;
            }
            case wasmThreadsOpcodeI64AtomicRMW16XorU: {
                expectedAlign = WASM_MEMARG16_ALIGN;
                resultType = wasmValueTypeI64;
                functionName = "i64_atomic_rmw16_xor_u";
                break;
            }
            case wasmThreadsOpcodeI64AtomicRMW32XorU: {
                expectedAlign = WASM_MEMARG32_ALIGN;
                resultType = wasmValueTypeI64;
                functionName = "i64_atomic_rmw32_xor_u";
                break;
            }
            /* Xchg */
            case wasmThreadsOpcodeI32AtomicRMWXchg: {
                expectedAlign = WASM_MEMARG32_ALIGN;
                resultType = wasmValueTypeI32;
                functionName = "i32_atomic_rmw_xchg";
                break;
            }
            case wasmThreadsOpcodeI64AtomicRMWXchg: {
                expectedAlign = WASM_MEMARG64_ALIGN;
                resultType = wasmValueTypeI64;
                functionName = "i64_atomic_rmw_xchg";
                break;
            }
            case wasmThreadsOpcodeI32AtomicRMW8XchgU: {
                expectedAlign = WASM_MEMARG8_ALIGN;
                resultType = wasmValueTypeI32;
                functionName = "i32_atomic_rmw8_xchg_u";
                break;
            }
            case wasmThreadsOpcodeI32AtomicRMW16XchgU: {
                expectedAlign = WASM_MEMARG16_ALIGN;
                resultType = wasmValueTypeI32;
                functionName = "i32_atomic_rmw16_xchg_u";
                break;
            }
            case wasmThreadsOpcodeI64AtomicRMW8XchgU: {
                expectedAlign = WASM_MEMARG8_ALIGN;
                resultType = wasmValueTypeI64;
                functionName = "i64_atomic_rmw8_xchg_u";
                break;
            }
            case wasmThreadsOpcodeI64AtomicRMW16XchgU: {
                expectedAlign = WASM_MEMARG16_ALIGN;
                resultType = wasmValueTypeI64;
                functionName = "i64_atomic_rmw16_xchg_u";
                break;
            }
            case wasmThreadsOpcodeI64AtomicRMW32XchgU: {
                expectedAlign = WASM_MEMARG32_ALIGN;
                resultType = wasmValueTypeI64;
                functionName = "i64_atomic_rmw32_xchg_u";
                break;
            }
            default: {
                fprintf(
                    stderr,
                    "w2c2: unsupported atomic RMW instruction opcode: %s\n",
                    wasmThreadsOpcodeDescription(opcode)
                );
                return false;
            }
        }

        if (instruction.align != expectedAlign) {
            fprintf(
                stderr,
                "w2c2: invalid %s instruction encoding: expected align %d, got %d\n",
                wasmThreadsOpcodeDescription(opcode),
                expectedAlign,
                instruction.align
            );
            return false;
        }

        {
            const U32 stackIndex1 = wasmTypeStackGetTopIndex(writer->typeStack, 1);
            const U32 stackIndex0 = wasmTypeStackGetTopIndex(writer->typeStack, 0);

            MUST (wasmTypeStackSet(writer->stackDeclarations, stackIndex1, resultType))

            MUST (wasmCWriteIndent(writer))
            MUST (wasmCWriteStringStackName(writer->builder, stackIndex1, resultType))
            MUST (wasmCWriteAssign(writer))
            MUST (wasmCWrite(writer, functionName))
            MUST (wasmCWriteChar(writer, '('))
            MUST (wasmCWriteStringMemoryUse(writer->builder, writer->module, 0, true))
            MUST (wasmCWriteComma(writer))
            MUST (wasmCWrite(writer, "(U64)"))
            MUST (wasmCWriteStringStackName(
                    writer->builder,
                stackIndex1,
                writer->typeStack->valueTypes[stackIndex1]
            ))
            if (instruction.offset != 0) {
                MUST (wasmCWritePlus(writer))
                MUST (stringBuilderAppendU32(writer->builder, instruction.offset))
                MUST (wasmCWriteChar(writer, 'U'))
            }
            MUST (wasmCWriteComma(writer))
            MUST (wasmCWriteStringStackName(
                writer->builder,
                stackIndex0,
                writer->typeStack->valueTypes[stackIndex0]
            ))
            MUST (wasmCWrite(writer, ");\n"))

            wasmTypeStackDrop(writer->typeStack, 2);
            MUST (wasmTypeStackAppend(writer->typeStack, resultType))
        }
    }

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteAtomicRMWCmpxchgExpr(
    const WasmCFunctionWriter* writer,
    const WasmThreadsOpcode opcode
) {
    WasmMemoryArgumentInstruction instruction;
    if (!wasmMemoryArgumentInstructionRead(writer->code, &instruction)) {
        fprintf(
            stderr,
            "w2c2: invalid %s instruction encoding\n",
            wasmThreadsOpcodeDescription(opcode)
        );
        return false;
    }

    if (!writer->ignore) {
        U32 expectedAlign = 0;
        WasmValueType resultType = 0;
        char *functionName = NULL;
        switch (opcode) {
            case wasmThreadsOpcodeI32AtomicRMWCmpxchg: {
                expectedAlign = WASM_MEMARG32_ALIGN;
                resultType = wasmValueTypeI32;
                functionName = "i32_atomic_rmw_cmpxchg";
                break;
            }
            case wasmThreadsOpcodeI64AtomicRMWCmpxchg: {
                expectedAlign = WASM_MEMARG64_ALIGN;
                resultType = wasmValueTypeI64;
                functionName = "i64_atomic_rmw_cmpxchg";
                break;
            }
            case wasmThreadsOpcodeI32AtomicRMW8CmpxchgU: {
                expectedAlign = WASM_MEMARG8_ALIGN;
                resultType = wasmValueTypeI32;
                functionName = "i32_atomic_rmw8_cmpxchg_u";
                break;
            }
            case wasmThreadsOpcodeI32AtomicRMW16CmpxchgU: {
                expectedAlign = WASM_MEMARG16_ALIGN;
                resultType = wasmValueTypeI32;
                functionName = "i32_atomic_rmw16_cmpxchg_u";
                break;
            }
            case wasmThreadsOpcodeI64AtomicRMW8CmpxchgU: {
                expectedAlign = WASM_MEMARG8_ALIGN;
                resultType = wasmValueTypeI64;
                functionName = "i64_atomic_rmw8_cmpxchg_u";
                break;
            }
            case wasmThreadsOpcodeI64AtomicRMW16CmpxchgU: {
                expectedAlign = WASM_MEMARG16_ALIGN;
                resultType = wasmValueTypeI64;
                functionName = "i64_atomic_rmw16_cmpxchg_u";
                break;
            }
            case wasmThreadsOpcodeI64AtomicRMW32CmpxchgU: {
                expectedAlign = WASM_MEMARG32_ALIGN;
                resultType = wasmValueTypeI64;
                functionName = "i64_atomic_rmw32_cmpxchg_u";
                break;
            }
            default: {
                fprintf(
                    stderr,
                    "w2c2: unsupported atomic RMW compare-exchange instruction opcode: %s\n",
                    wasmThreadsOpcodeDescription(opcode)
                );
                return false;
            }
        }

        if (instruction.align != expectedAlign) {
            fprintf(
                stderr,
                "w2c2: invalid %s instruction encoding: expected align %d, got %d\n",
                wasmThreadsOpcodeDescription(opcode),
                expectedAlign,
                instruction.align
            );
            return false;
        }

        {
            const U32 stackIndex2 = wasmTypeStackGetTopIndex(writer->typeStack, 2);
            const U32 stackIndex1 = wasmTypeStackGetTopIndex(writer->typeStack, 1);
            const U32 stackIndex0 = wasmTypeStackGetTopIndex(writer->typeStack, 0);

            MUST (wasmTypeStackSet(writer->stackDeclarations, stackIndex2, resultType))

            MUST (wasmCWriteIndent(writer))
            MUST (wasmCWriteStringStackName(writer->builder, stackIndex2, resultType))
            MUST (wasmCWriteAssign(writer))
            MUST (wasmCWrite(writer, functionName))
            MUST (wasmCWriteChar(writer, '('))
            MUST (wasmCWriteStringMemoryUse(writer->builder, writer->module, 0, true))
            MUST (wasmCWriteComma(writer))
            MUST (wasmCWrite(writer, "(U64)"))
            MUST (wasmCWriteStringStackName(
                    writer->builder,
                    stackIndex2,
                    writer->typeStack->valueTypes[stackIndex2]
            ))
            if (instruction.offset != 0) {
                MUST (wasmCWritePlus(writer))
                MUST (stringBuilderAppendU32(writer->builder, instruction.offset))
                MUST (wasmCWriteChar(writer, 'U'))
            }
            MUST (wasmCWriteComma(writer))
            MUST (wasmCWriteStringStackName(
                    writer->builder,
                    stackIndex1,
                    writer->typeStack->valueTypes[stackIndex1]
            ))
            MUST (wasmCWriteComma(writer))
            MUST (wasmCWriteStringStackName(
                    writer->builder,
                    stackIndex0,
                    writer->typeStack->valueTypes[stackIndex0]
            ))
            MUST (wasmCWrite(writer, ");\n"))

            wasmTypeStackDrop(writer->typeStack, 3);
            MUST (wasmTypeStackAppend(writer->typeStack, resultType))
        }
    }

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteFunctionCode(
    WasmCFunctionWriter* writer,
    WasmOpcode* opcode
) {
    while (true) {
        if (writer->debug) {
            const size_t relativeAddress = writer->function.code.length - writer->code->length;
            const size_t absoluteAddress = writer->function.start + relativeAddress;
            const WasmDebugLine* debugLine = wasmCGetDebugLine(
                writer->debugLines,
                absoluteAddress
            );
            if (debugLine != NULL) {
                MUST (wasmCWriteDebugLine(writer->builder, debugLine))
            }
        }

        if (!wasmOpcodeRead(writer->code, opcode)) {
            break;
        }

        switch (*opcode) {
            case wasmOpcodeNop:
                break;
            case wasmOpcodeElse:
            case wasmOpcodeEnd:
                return true;
            case wasmOpcodeIf: {
                MUST (wasmCWriteIfExpr(writer, opcode))
                if (*opcode == wasmOpcodeElse) {
                    return true;
                }
                break;
            }
            case wasmOpcodeBlock: {
                MUST (wasmCWriteBlockExpr(writer, opcode))
                if (*opcode == wasmOpcodeElse) {
                    return true;
                }
                break;
            }
            case wasmOpcodeLoop: {
                MUST (wasmCWriteLoopExpr(writer, opcode))
                if (*opcode == wasmOpcodeElse) {
                    return true;
                }
                break;
            }
            case wasmOpcodeCall: {
                MUST (wasmCWriteCallExpr(writer))
                break;
            }
            case wasmOpcodeCallIndirect: {
                MUST (wasmCWriteCallIndirectExpr(writer))
                break;
            }
            case wasmOpcodeBr: {
                MUST (wasmCWriteBranchExpr(writer))
                writer->ignore = true;
                break;
            }
            case wasmOpcodeBrIf: {
                MUST (wasmCWriteBranchIfExpr(writer))
                break;
            }
            case wasmOpcodeBrTable: {
                MUST (wasmCWriteBranchTableExpr(writer))
                writer->ignore = true;
                break;
            }
            case wasmOpcodeLocalGet: {
                MUST (wasmCWriteLocalGetExpr(writer))
                break;
            }
            case wasmOpcodeLocalSet:
            case wasmOpcodeLocalTee: {
                MUST (wasmCWriteLocalAssignmentExpr(writer, *opcode))
                break;
            }
            case wasmOpcodeGlobalGet: {
                MUST (wasmCWriteGlobalGetExpr(writer))
                break;
            }
            case wasmOpcodeGlobalSet: {
                MUST (wasmCWriteGlobalSetExpr(writer))
                break;
            }
            case wasmOpcodeI32Const:
            case wasmOpcodeI64Const:
            case wasmOpcodeF32Const:
            case wasmOpcodeF64Const: {
                MUST (wasmCWriteConstExpr(writer, *opcode))
                break;
            }
            case wasmOpcodeI32Load:
            case wasmOpcodeI64Load:
            case wasmOpcodeF32Load:
            case wasmOpcodeF64Load:
            case wasmOpcodeI32Load8S:
            case wasmOpcodeI32Load8U:
            case wasmOpcodeI32Load16S:
            case wasmOpcodeI32Load16U:
            case wasmOpcodeI64Load8S:
            case wasmOpcodeI64Load8U:
            case wasmOpcodeI64Load16S:
            case wasmOpcodeI64Load16U:
            case wasmOpcodeI64Load32S:
            case wasmOpcodeI64Load32U: {
                MUST (wasmCWriteLoadExpr(writer, *opcode))
                break;
            }
            case wasmOpcodeI32Store:
            case wasmOpcodeI64Store:
            case wasmOpcodeF32Store:
            case wasmOpcodeF64Store:
            case wasmOpcodeI32Store8:
            case wasmOpcodeI32Store16:
            case wasmOpcodeI64Store8:
            case wasmOpcodeI64Store16:
            case wasmOpcodeI64Store32: {
                MUST (wasmCWriteStoreExpr(writer, *opcode))
                break;
            }
            case wasmOpcodeMemorySize: {
                MUST (wasmCWriteMemorySizeExpr(writer))
                break;
            }
            case wasmOpcodeMemoryGrow: {
                MUST (wasmCWriteMemoryGrowExpr(writer))
                break;
            }
            case wasmOpcodeThreadsPrefix: {
                WasmThreadsOpcode threadsOpcode = 0;
                MUST (leb128ReadU32(writer->code, (U32*)&threadsOpcode) > 0)

                switch (threadsOpcode) {
                    case wasmThreadsOpcodeMemoryAtomicNotify: {
                        MUST (wasmCWriteMemoryAtomicNotifyExpr(writer))
                        break;
                    }
                    case wasmThreadsOpcodeMemoryAtomicWait32: {
                        MUST (wasmCWriteMemoryAtomicWait32Expr(writer))
                        break;
                    }
                    case wasmThreadsOpcodeMemoryAtomicWait64: {
                        MUST (wasmCWriteMemoryAtomicWait64Expr(writer))
                        break;
                    }
                    case wasmThreadsOpcodeAtomicFence: {
                        MUST (wasmCWriteAtomicFenceExpr(writer))
                        break;
                    }
                    case wasmThreadsOpcodeI32AtomicLoad:
                    case wasmThreadsOpcodeI64AtomicLoad:
                    case wasmThreadsOpcodeI32AtomicLoad8U:
                    case wasmThreadsOpcodeI32AtomicLoad16U:
                    case wasmThreadsOpcodeI64AtomicLoad8U:
                    case wasmThreadsOpcodeI64AtomicLoad16U:
                    case wasmThreadsOpcodeI64AtomicLoad32U: {
                        MUST (wasmCWriteAtomicLoadExpr(writer, threadsOpcode))
                        break;
                    }
                    case wasmThreadsOpcodeI32AtomicStore:
                    case wasmThreadsOpcodeI64AtomicStore:
                    case wasmThreadsOpcodeI32AtomicStore8:
                    case wasmThreadsOpcodeI32AtomicStore16:
                    case wasmThreadsOpcodeI64AtomicStore8:
                    case wasmThreadsOpcodeI64AtomicStore16:
                    case wasmThreadsOpcodeI64AtomicStore32: {
                        MUST (wasmCWriteAtomicStoreExpr(writer, threadsOpcode))
                        break;
                    }
                    case wasmThreadsOpcodeI32AtomicRMWAdd:
                    case wasmThreadsOpcodeI64AtomicRMWAdd:
                    case wasmThreadsOpcodeI32AtomicRMW8AddU:
                    case wasmThreadsOpcodeI32AtomicRMW16AddU:
                    case wasmThreadsOpcodeI64AtomicRMW8AddU:
                    case wasmThreadsOpcodeI64AtomicRMW16AddU:
                    case wasmThreadsOpcodeI64AtomicRMW32AddU:
                    case wasmThreadsOpcodeI32AtomicRMWSub:
                    case wasmThreadsOpcodeI64AtomicRMWSub:
                    case wasmThreadsOpcodeI32AtomicRMW8SubU:
                    case wasmThreadsOpcodeI32AtomicRMW16SubU:
                    case wasmThreadsOpcodeI64AtomicRMW8SubU:
                    case wasmThreadsOpcodeI64AtomicRMW16SubU:
                    case wasmThreadsOpcodeI64AtomicRMW32SubU:
                    case wasmThreadsOpcodeI32AtomicRMWAnd:
                    case wasmThreadsOpcodeI64AtomicRMWAnd:
                    case wasmThreadsOpcodeI32AtomicRMW8AndU:
                    case wasmThreadsOpcodeI32AtomicRMW16AndU:
                    case wasmThreadsOpcodeI64AtomicRMW8AndU:
                    case wasmThreadsOpcodeI64AtomicRMW16AndU:
                    case wasmThreadsOpcodeI64AtomicRMW32AndU:
                    case wasmThreadsOpcodeI32AtomicRMWOr:
                    case wasmThreadsOpcodeI64AtomicRMWOr:
                    case wasmThreadsOpcodeI32AtomicRMW8OrU:
                    case wasmThreadsOpcodeI32AtomicRMW16OrU:
                    case wasmThreadsOpcodeI64AtomicRMW8OrU:
                    case wasmThreadsOpcodeI64AtomicRMW16OrU:
                    case wasmThreadsOpcodeI64AtomicRMW32OrU:
                    case wasmThreadsOpcodeI32AtomicRMWXor:
                    case wasmThreadsOpcodeI64AtomicRMWXor:
                    case wasmThreadsOpcodeI32AtomicRMW8XorU:
                    case wasmThreadsOpcodeI32AtomicRMW16XorU:
                    case wasmThreadsOpcodeI64AtomicRMW8XorU:
                    case wasmThreadsOpcodeI64AtomicRMW16XorU:
                    case wasmThreadsOpcodeI64AtomicRMW32XorU:
                    case wasmThreadsOpcodeI32AtomicRMWXchg:
                    case wasmThreadsOpcodeI64AtomicRMWXchg:
                    case wasmThreadsOpcodeI32AtomicRMW8XchgU:
                    case wasmThreadsOpcodeI32AtomicRMW16XchgU:
                    case wasmThreadsOpcodeI64AtomicRMW8XchgU:
                    case wasmThreadsOpcodeI64AtomicRMW16XchgU:
                    case wasmThreadsOpcodeI64AtomicRMW32XchgU: {
                        MUST (wasmCWriteAtomicRMWExpr(writer, threadsOpcode))
                        break;
                    }
                    case wasmThreadsOpcodeI32AtomicRMWCmpxchg:
                    case wasmThreadsOpcodeI64AtomicRMWCmpxchg:
                    case wasmThreadsOpcodeI32AtomicRMW8CmpxchgU:
                    case wasmThreadsOpcodeI32AtomicRMW16CmpxchgU:
                    case wasmThreadsOpcodeI64AtomicRMW8CmpxchgU:
                    case wasmThreadsOpcodeI64AtomicRMW16CmpxchgU:
                    case wasmThreadsOpcodeI64AtomicRMW32CmpxchgU: {
                        MUST (wasmCWriteAtomicRMWCmpxchgExpr(writer, threadsOpcode))
                        break;
                    }
                }

                break;
            }
            case wasmOpcodeMiscPrefix: {
                WasmMiscOpcode miscOpcode = 0;
                MUST (leb128ReadU32(writer->code, (U32*)&miscOpcode) > 0)

                switch (miscOpcode) {
                    case wasmMiscOpcodeMemoryInit: {
                        MUST (wasmCWriteMemoryInitExpr(writer))
                        break;
                    }
                    case wasmMiscOpcodeDataDrop: {
                        /* TODO: refactor into instruction read function */
                        U32 dataIndex = 0;
                        MUST (leb128ReadU32(writer->code, &dataIndex) > 0)

                        /* TODO */
                        fprintf(
                            stderr,
                            "w2c2: unimplemented opcode: %s\n",
                            wasmMiscOpcodeDescription(miscOpcode)
                        );

                        break;
                    }
                    case wasmMiscOpcodeMemoryCopy: {
                        MUST (wasmCWriteMemoryCopyExpr(writer))
                        continue;
                    }
                    case wasmMiscOpcodeMemoryFill: {
                        MUST (wasmCWriteMemoryFillExpr(writer, miscOpcode))
                        continue;
                    }
                    case wasmMiscOpcodeTableInit: {
                        /* TODO: refactor into instruction read function */
                        U32 elemIndex = 0;
                        U32 tableIndex = 0;
                        MUST (leb128ReadU32(writer->code, &elemIndex) > 0)
                        MUST (leb128ReadU32(writer->code, &tableIndex) > 0)

                        /* TODO */
                        fprintf(
                            stderr,
                            "w2c2: unimplemented opcode: %s\n",
                            wasmMiscOpcodeDescription(miscOpcode)
                        );

                        break;
                    }
                    case wasmMiscOpcodeElemDrop: {
                        /* TODO: refactor into instruction read function */
                        U32 elemIndex = 0;
                        MUST (leb128ReadU32(writer->code, &elemIndex) > 0)

                        /* TODO */
                        fprintf(
                            stderr,
                            "w2c2: unimplemented opcode: %s\n",
                            wasmMiscOpcodeDescription(miscOpcode)
                        );

                        break;
                    }
                    case wasmMiscOpcodeTableCopy: {
                        /* TODO: refactor into instruction read function */
                        U32 tableIndex1 = 0;
                        U32 tableIndex2 = 0;
                        MUST (leb128ReadU32(writer->code, &tableIndex1) > 0)
                        MUST (leb128ReadU32(writer->code, &tableIndex2) > 0)

                        /* TODO */
                        fprintf(
                            stderr,
                            "w2c2: unimplemented opcode: %s\n",
                            wasmMiscOpcodeDescription(miscOpcode)
                        );

                        break;
                    }
                    case wasmMiscOpcodeTableGrow: {
                        /* TODO: refactor into instruction read function */
                        U32 tableIndex = 0;
                        MUST (leb128ReadU32(writer->code, &tableIndex) > 0)

                        /* TODO */
                        fprintf(
                            stderr,
                            "w2c2: unimplemented opcode: %s\n",
                            wasmMiscOpcodeDescription(miscOpcode)
                        );

                        break;
                    }
                    case wasmMiscOpcodeTableSize: {
                        /* TODO: refactor into instruction read function */
                        U32 tableIndex = 0;
                        MUST (leb128ReadU32(writer->code, &tableIndex) > 0)

                        /* TODO */
                        fprintf(
                            stderr,
                            "w2c2: unimplemented opcode: %s\n",
                            wasmMiscOpcodeDescription(miscOpcode)
                        );

                        break;
                    }
                    case wasmMiscOpcodeTableFill: {
                        /* TODO: refactor into instruction read function */
                        U32 tableIndex = 0;
                        MUST (leb128ReadU32(writer->code, &tableIndex) > 0)

                        /* TODO */
                        fprintf(
                            stderr,
                            "w2c2: unimplemented opcode: %s\n",
                            wasmMiscOpcodeDescription(miscOpcode)
                        );

                        break;
                    }
                    default:
                        if (writer->ignore) {
                            break;
                        }

                        switch (miscOpcode) {
                            case wasmMiscOpcodeI32TruncSatF32S: {
                                MUST (wasmCWriteUnaryExpr(writer, wasmValueTypeI32, "I32_TRUNC_SAT_S_F32"))
                                break;
                            }
                            case wasmMiscOpcodeI64TruncSatF32S: {
                                MUST (wasmCWriteUnaryExpr(writer, wasmValueTypeI64, "I64_TRUNC_SAT_S_F32"))
                                break;
                            }
                            case wasmMiscOpcodeI32TruncSatF64S: {
                                MUST (wasmCWriteUnaryExpr(writer, wasmValueTypeI32, "I32_TRUNC_SAT_S_F64"))
                                break;
                            }
                            case wasmMiscOpcodeI64TruncSatF64S: {
                                MUST (wasmCWriteUnaryExpr(writer, wasmValueTypeI64, "I64_TRUNC_SAT_S_F64"))
                                break;
                            }
                            case wasmMiscOpcodeI32TruncSatF32U: {
                                MUST (wasmCWriteUnaryExpr(writer, wasmValueTypeI32, "I32_TRUNC_SAT_U_F32"))
                                break;
                            }
                            case wasmMiscOpcodeI64TruncSatF32U: {
                                MUST (wasmCWriteUnaryExpr(writer, wasmValueTypeI64, "I64_TRUNC_SAT_U_F32"))
                                break;
                            }
                            case wasmMiscOpcodeI32TruncSatF64U: {
                                MUST (wasmCWriteUnaryExpr(writer, wasmValueTypeI32, "I32_TRUNC_SAT_U_F64"))
                                break;
                            }
                            case wasmMiscOpcodeI64TruncSatF64U: {
                                MUST (wasmCWriteUnaryExpr(writer, wasmValueTypeI64, "I64_TRUNC_SAT_U_F64"))
                                break;
                            }
                            default: {
                                fprintf(
                                    stderr,
                                    "w2c2: unsupported misc opcode: %s\n",
                                    wasmMiscOpcodeDescription(miscOpcode)
                                );
                                return false;
                            }
                        }

                        break;
                }

                break;
            }
            default: {
                if (writer->ignore) {
                    break;
                }

                switch (*opcode) {
                    case wasmOpcodeDrop: {
                        wasmTypeStackDrop(writer->typeStack, 1);
                        break;
                    }
                    case wasmOpcodeUnreachable: {
                        MUST (wasmCWriteIndent(writer))
                        MUST (wasmCWrite(writer, "UNREACHABLE;\n"))
                        writer->ignore = true;
                        break;
                    }
                    case wasmOpcodeSelect: {
                        MUST (wasmCWriteSelectExpr(writer))
                        break;
                    }
                    case wasmOpcodeReturn: {
                        MUST (wasmCWriteGoto(writer, 0))
                        writer->ignore = true;
                        break;
                    }
                    case wasmOpcodeI32Eq:
                    case wasmOpcodeI64Eq:
                    case wasmOpcodeF32Eq:
                    case wasmOpcodeF64Eq: {
                        MUST (wasmCWriteInfixBinaryExpr(writer, wasmValueTypeI32, "==", false))
                        break;
                    }
                    case wasmOpcodeI32Ne:
                    case wasmOpcodeI64Ne:
                    case wasmOpcodeF32Ne:
                    case wasmOpcodeF64Ne: {
                        MUST (wasmCWriteInfixBinaryExpr(writer, wasmValueTypeI32, "!=", false))
                        break;
                    }
                    case wasmOpcodeI32LtS:
                    case wasmOpcodeI64LtS: {
                        MUST (wasmCWriteSignedInfixBinaryExpr(writer, *opcode, "<"))
                        break;
                    }
                    case wasmOpcodeI32LtU:
                    case wasmOpcodeI64LtU:
                    case wasmOpcodeF32Lt:
                    case wasmOpcodeF64Lt: {
                        MUST (wasmCWriteInfixBinaryExpr(writer, wasmValueTypeI32, "<", false))
                        break;
                    }
                    case wasmOpcodeI32LeS:
                    case wasmOpcodeI64LeS: {
                        MUST (wasmCWriteSignedInfixBinaryExpr(writer, *opcode, "<="))
                        break;
                    }
                    case wasmOpcodeI32LeU:
                    case wasmOpcodeI64LeU:
                    case wasmOpcodeF32Le:
                    case wasmOpcodeF64Le: {
                        MUST (wasmCWriteInfixBinaryExpr(writer, wasmValueTypeI32, "<=", false))
                        break;
                    }
                    case wasmOpcodeI32GtS:
                    case wasmOpcodeI64GtS: {
                        MUST (wasmCWriteSignedInfixBinaryExpr(writer, *opcode, ">"))
                        break;
                    }
                    case wasmOpcodeI32GtU:
                    case wasmOpcodeI64GtU:
                    case wasmOpcodeF32Gt:
                    case wasmOpcodeF64Gt: {
                        MUST (wasmCWriteInfixBinaryExpr(writer, wasmValueTypeI32, ">", false))
                        break;
                    }
                    case wasmOpcodeI32GeS:
                    case wasmOpcodeI64GeS: {
                        MUST (wasmCWriteSignedInfixBinaryExpr(writer, *opcode, ">="))
                        break;
                    }
                    case wasmOpcodeI32GeU:
                    case wasmOpcodeI64GeU:
                    case wasmOpcodeF32Ge:
                    case wasmOpcodeF64Ge: {
                        MUST (wasmCWriteInfixBinaryExpr(writer, wasmValueTypeI32, ">=", false))
                        break;
                    }
                    case wasmOpcodeI32Add: {
                        MUST (wasmCWriteInfixBinaryExpr(writer, wasmValueTypeI32, "+", true))
                        break;
                    }
                    case wasmOpcodeI64Add: {
                        MUST (wasmCWriteInfixBinaryExpr(writer, wasmValueTypeI64, "+", true))
                        break;
                    }
                    case wasmOpcodeF32Add: {
                        MUST (wasmCWriteInfixBinaryExpr(writer, wasmValueTypeF32, "+", true))
                        break;
                    }
                    case wasmOpcodeF64Add: {
                        MUST (wasmCWriteInfixBinaryExpr(writer, wasmValueTypeF64, "+", true))
                        break;
                    }
                    case wasmOpcodeI32Sub: {
                        MUST (wasmCWriteInfixBinaryExpr(writer, wasmValueTypeI32, "-", true))
                        break;
                    }
                    case wasmOpcodeI64Sub: {
                        MUST (wasmCWriteInfixBinaryExpr(writer, wasmValueTypeI64, "-", true))
                        break;
                    }
                    case wasmOpcodeF32Sub: {
                        MUST (wasmCWriteInfixBinaryExpr(writer, wasmValueTypeF32, "-", true))
                        break;
                    }
                    case wasmOpcodeF64Sub: {
                       MUST (wasmCWriteInfixBinaryExpr(writer, wasmValueTypeF64, "-", true))
                        break;
                    }
                    case wasmOpcodeI32Mul: {
                        MUST (wasmCWriteInfixBinaryExpr(writer, wasmValueTypeI32, "*", true))
                        break;
                    }
                    case wasmOpcodeI64Mul: {
                        MUST (wasmCWriteInfixBinaryExpr(writer, wasmValueTypeI64, "*", true))
                        break;
                    }
                    case wasmOpcodeF32Mul: {
                        MUST (wasmCWriteInfixBinaryExpr(writer, wasmValueTypeF32, "*", true))
                        break;
                    }
                    case wasmOpcodeF64Mul: {
                        MUST (wasmCWriteInfixBinaryExpr(writer, wasmValueTypeF64, "*", true))
                        break;
                    }
                    case wasmOpcodeI32DivS: {
                        MUST (wasmCWritePrefixBinaryExpr(writer, wasmValueTypeI32, "I32_DIV_S"))
                        break;
                    }
                    case wasmOpcodeI64DivS: {
                        MUST (wasmCWritePrefixBinaryExpr(writer, wasmValueTypeI64, "I64_DIV_S"))
                        break;
                    }
                    case wasmOpcodeI32DivU: {
                        MUST (wasmCWritePrefixBinaryExpr(writer, wasmValueTypeI32, "DIV_U"))
                        break;
                    }
                    case wasmOpcodeI64DivU: {
                        MUST (wasmCWritePrefixBinaryExpr(writer, wasmValueTypeI64, "DIV_U"))
                        break;
                    }
                    case wasmOpcodeF32Div: {
                        MUST (wasmCWriteInfixBinaryExpr(writer, wasmValueTypeF32, "/", true))
                        break;
                    }
                    case wasmOpcodeF64Div: {
                        MUST (wasmCWriteInfixBinaryExpr(writer, wasmValueTypeF64, "/", true))
                        break;
                    }
                    case wasmOpcodeI32Eqz:
                    case wasmOpcodeI64Eqz: {
                        MUST (wasmCWriteUnaryExpr(writer, wasmValueTypeI32, "!"))
                        break;
                    }
                    case wasmOpcodeI32And: {
                        MUST (wasmCWriteInfixBinaryExpr(writer, wasmValueTypeI32, "&", true))
                        break;
                    }
                    case wasmOpcodeI64And: {
                        MUST (wasmCWriteInfixBinaryExpr(writer, wasmValueTypeI64, "&", true))
                        break;
                    }
                    case wasmOpcodeI32Or: {
                        MUST (wasmCWriteInfixBinaryExpr(writer, wasmValueTypeI32, "|", true))
                        break;
                    }
                    case wasmOpcodeI64Or: {
                        MUST (wasmCWriteInfixBinaryExpr(writer, wasmValueTypeI64, "|", true))
                        break;
                    }
                    case wasmOpcodeI32Xor: {
                        MUST (wasmCWriteInfixBinaryExpr(writer, wasmValueTypeI32, "^", true))
                        break;
                    }
                    case wasmOpcodeI64Xor: {
                        MUST (wasmCWriteInfixBinaryExpr(writer, wasmValueTypeI64, "^", true))
                        break;
                    }
                    case wasmOpcodeI32RemS: {
                        MUST (wasmCWritePrefixBinaryExpr(writer, wasmValueTypeI32, "I32_REM_S"))
                        break;
                    }
                    case wasmOpcodeI64RemS: {
                        MUST (wasmCWritePrefixBinaryExpr(writer, wasmValueTypeI64, "I64_REM_S"))
                        break;
                    }
                    case wasmOpcodeI32RemU: {
                        MUST (wasmCWritePrefixBinaryExpr(writer, wasmValueTypeI32, "REM_U"))
                        break;
                    }
                    case wasmOpcodeI64RemU: {
                        MUST (wasmCWritePrefixBinaryExpr(writer, wasmValueTypeI64, "REM_U"))
                        break;
                    }
                    case wasmOpcodeI32Clz: {
                        MUST (wasmCWriteUnaryExpr(writer, wasmValueTypeI32, "I32_CLZ"))
                        break;
                    }
                    case wasmOpcodeI64Clz: {
                        MUST (wasmCWriteUnaryExpr(writer, wasmValueTypeI64, "I64_CLZ"))
                        break;
                    }
                    case wasmOpcodeI32Ctz: {
                        MUST (wasmCWriteUnaryExpr(writer, wasmValueTypeI32, "I32_CTZ"))
                        break;
                    }
                    case wasmOpcodeI64Ctz: {
                        MUST (wasmCWriteUnaryExpr(writer, wasmValueTypeI64, "I64_CTZ"))
                        break;
                    }
                    case wasmOpcodeI32PopCnt: {
                        MUST (wasmCWriteUnaryExpr(writer, wasmValueTypeI32, "I32_POPCNT"))
                        break;
                    }
                    case wasmOpcodeI64PopCnt: {
                        MUST (wasmCWriteUnaryExpr(writer, wasmValueTypeI64, "I64_POPCNT"))
                        break;
                    }
                    case wasmOpcodeF32Neg: {
                        MUST (wasmCWriteUnaryExpr(writer, wasmValueTypeF32, "-"))
                        break;
                    }
                    case wasmOpcodeF64Neg: {
                        MUST (wasmCWriteUnaryExpr(writer, wasmValueTypeF64, "-"))
                        break;
                    }
                    case wasmOpcodeF32Abs: {
                        MUST (wasmCWriteUnaryExpr(writer, wasmValueTypeF32, "fabsf"))
                        break;
                    }
                    case wasmOpcodeF64Abs: {
                        MUST (wasmCWriteUnaryExpr(writer, wasmValueTypeF64, "fabs"))
                        break;
                    }
                    case wasmOpcodeF32Sqrt: {
                        MUST (wasmCWriteUnaryExpr(writer, wasmValueTypeF32, "sqrtf"))
                        break;
                    }
                    case wasmOpcodeF64Sqrt: {
                        MUST (wasmCWriteUnaryExpr(writer, wasmValueTypeF64, "sqrt"))
                        break;
                    }
                    case wasmOpcodeF32Ceil: {
                        MUST (wasmCWriteUnaryExpr(writer, wasmValueTypeF32, "ceilf"))
                        break;
                    }
                    case wasmOpcodeF64Ceil: {
                        MUST (wasmCWriteUnaryExpr(writer, wasmValueTypeF64, "ceil"))
                        break;
                    }
                    case wasmOpcodeF32Floor: {
                        MUST (wasmCWriteUnaryExpr(writer, wasmValueTypeF32, "floorf"))
                        break;
                    }
                    case wasmOpcodeF64Floor: {
                        MUST (wasmCWriteUnaryExpr(writer, wasmValueTypeF64, "floor"))
                        break;
                    }
                    case wasmOpcodeF32Trunc: {
                        MUST (wasmCWriteUnaryExpr(writer, wasmValueTypeF32, "truncf"))
                        break;
                    }
                    case wasmOpcodeF64Trunc: {
                        MUST (wasmCWriteUnaryExpr(writer, wasmValueTypeF64, "trunc"))
                        break;
                    }
                    case wasmOpcodeF32Nearest: {
                        MUST (wasmCWriteUnaryExpr(writer, wasmValueTypeF32, "nearbyintf"))
                        break;
                    }
                    case wasmOpcodeF64Nearest: {
                        MUST (wasmCWriteUnaryExpr(writer, wasmValueTypeF64, "nearbyint"))
                        break;
                    }
                    case wasmOpcodeI32Extend8S: {
                        MUST (wasmCWriteUnaryExpr(writer, wasmValueTypeI32, "(U32)(U32)(I8)(U8)"));
                        break;
                    }
                    case wasmOpcodeI32Extend16S: {
                        MUST (wasmCWriteUnaryExpr(writer, wasmValueTypeI32, "(U32)(I32)(I16)(U16)"));
                        break;
                    }
                    case wasmOpcodeI64Extend8S: {
                        MUST (wasmCWriteUnaryExpr(writer, wasmValueTypeI64, "(U64)(I64)(I8)(U8)"));
                        break;
                    }
                    case wasmOpcodeI64Extend16S: {
                        MUST (wasmCWriteUnaryExpr(writer, wasmValueTypeI64, "(U64)(I64)(I16)(U16)"));
                        break;
                    }
                    case wasmOpcodeI64Extend32S: {
                        MUST (wasmCWriteUnaryExpr(writer, wasmValueTypeI64, "(U64)(I64)(I32)(U32)"));
                        break;
                    }
                    case wasmOpcodeI32Shl:
                    case wasmOpcodeI64Shl: {
                        MUST (wasmCWriteShiftLeftExpr(writer, *opcode))
                        break;
                    }
                    case wasmOpcodeI32ShrS:
                    case wasmOpcodeI64ShrS: {
                        MUST (wasmCWriteSignedShiftRightExpr(writer, *opcode))
                        break;
                    }
                    case wasmOpcodeI32ShrU:
                    case wasmOpcodeI64ShrU: {
                        MUST (wasmCWriteUnsignedShiftRightExpr(writer, *opcode))
                        break;
                    }
                    case wasmOpcodeI32Rotl: {
                        MUST (wasmCWritePrefixBinaryExpr(writer, wasmValueTypeI32, "I32_ROTL"))
                        break;
                    }
                    case wasmOpcodeI64Rotl: {
                        MUST (wasmCWritePrefixBinaryExpr(writer, wasmValueTypeI64, "I64_ROTL"))
                        break;
                    }
                    case wasmOpcodeI32Rotr: {
                        MUST (wasmCWritePrefixBinaryExpr(writer, wasmValueTypeI32, "I32_ROTR"))
                        break;
                    }
                    case wasmOpcodeI64Rotr: {
                        MUST (wasmCWritePrefixBinaryExpr(writer, wasmValueTypeI64, "I64_ROTR"))
                        break;
                    }
                    case wasmOpcodeF32Min: {
                        MUST (wasmCWritePrefixBinaryExpr(writer, wasmValueTypeF32, "FMIN"))
                        break;
                    }
                    case wasmOpcodeF64Min: {
                        MUST (wasmCWritePrefixBinaryExpr(writer, wasmValueTypeF64, "FMIN"))
                        break;
                    }
                    case wasmOpcodeF32Max: {
                        MUST (wasmCWritePrefixBinaryExpr(writer, wasmValueTypeF32, "FMAX"))
                        break;
                    }
                    case wasmOpcodeF64Max: {
                        MUST (wasmCWritePrefixBinaryExpr(writer, wasmValueTypeF64, "FMAX"))
                        break;
                    }
                    case wasmOpcodeF32CopySign: {
                        MUST (wasmCWritePrefixBinaryExpr(writer, wasmValueTypeF32, "copysignf"))
                        break;
                    }
                    case wasmOpcodeF64CopySign: {
                        MUST (wasmCWritePrefixBinaryExpr(writer,  wasmValueTypeF64, "copysign"))
                        break;
                    }
                    case wasmOpcodeI64ExtendI32S: {
                        MUST (wasmCWriteUnaryExpr(writer, wasmValueTypeI64, "(U64)(I64)(I32)"))
                        break;
                    }
                    case wasmOpcodeI64ExtendI32U: {
                        MUST (wasmCWriteUnaryExpr(writer, wasmValueTypeI64, "(U64)"))
                        break;
                    }
                    case wasmOpcodeI32WrapI64: {
                        MUST (wasmCWriteUnaryExpr(writer, wasmValueTypeI32, "(U32)"))
                        break;
                    }
                    case wasmOpcodeI32TruncF32S: {
                        MUST (wasmCWriteUnaryExpr(writer, wasmValueTypeI32, "I32_TRUNC_S_F32"))
                        break;
                    }
                    case wasmOpcodeI64TruncF32S: {
                        MUST (wasmCWriteUnaryExpr(writer, wasmValueTypeI64, "I64_TRUNC_S_F32"))
                        break;
                    }
                    case wasmOpcodeI32TruncF64S: {
                        MUST (wasmCWriteUnaryExpr(writer, wasmValueTypeI32, "I32_TRUNC_S_F64"))
                        break;
                    }
                    case wasmOpcodeI64TruncF64S: {
                        MUST (wasmCWriteUnaryExpr(writer, wasmValueTypeI64, "I64_TRUNC_S_F64"))
                        break;
                    }
                    case wasmOpcodeI32TruncF32U: {
                        MUST (wasmCWriteUnaryExpr(writer, wasmValueTypeI32, "I32_TRUNC_U_F32"))
                        break;
                    }
                    case wasmOpcodeI64TruncF32U: {
                        MUST (wasmCWriteUnaryExpr(writer, wasmValueTypeI64, "I64_TRUNC_U_F32"))
                        break;
                    }
                    case wasmOpcodeI32TruncF64U: {
                        MUST (wasmCWriteUnaryExpr(writer, wasmValueTypeI32, "I32_TRUNC_U_F64"))
                        break;
                    }
                    case wasmOpcodeI64TruncF64U: {
                        MUST (wasmCWriteUnaryExpr(writer, wasmValueTypeI64, "I64_TRUNC_U_F64"))
                        break;
                    }
                    case wasmOpcodeF32ConvertI32S: {
                        MUST (wasmCWriteUnaryExpr(writer, wasmValueTypeF32, "(F32)(I32)"))
                        break;
                    }
                    case wasmOpcodeF32ConvertI64S: {
                        MUST (wasmCWriteUnaryExpr(writer, wasmValueTypeF32, "(F32)(I64)"))
                        break;
                    }
                    case wasmOpcodeF32ConvertI32U:
                    case wasmOpcodeF32DemoteF64: {
                        MUST (wasmCWriteUnaryExpr(writer, wasmValueTypeF32, "(F32)"))
                        break;
                    }
                    case wasmOpcodeF32ConvertI64U: {
                        /* TODO */
                        MUST (wasmCWriteUnaryExpr(writer, wasmValueTypeF32, "(F32)"))
                        break;
                    }
                    case wasmOpcodeF64ConvertI32S: {
                        MUST (wasmCWriteUnaryExpr(writer, wasmValueTypeF64, "(F64)(I32)"))
                        break;
                    }
                    case wasmOpcodeF64ConvertI64S: {
                        MUST (wasmCWriteUnaryExpr(writer, wasmValueTypeF64, "(F64)(I64)"))
                        break;
                    }
                    case wasmOpcodeF64ConvertI32U:
                    case wasmOpcodeF64PromoteF32: {
                        MUST (wasmCWriteUnaryExpr(writer, wasmValueTypeF64, "(F64)"))
                        break;
                    }
                    case wasmOpcodeF64ConvertI64U: {
                        /* TODO */
                        MUST (wasmCWriteUnaryExpr(writer, wasmValueTypeF64, "(F64)"))
                        break;
                    }
                    case wasmOpcodeF32ReinterpretI32: {
                        MUST (wasmCWriteUnaryExpr(writer, wasmValueTypeF32, "f32_reinterpret_i32"))
                        break;
                    }
                    case wasmOpcodeI32ReinterpretF32: {
                        MUST (wasmCWriteUnaryExpr(writer, wasmValueTypeI32, "i32_reinterpret_f32"))
                        break;
                    }
                    case wasmOpcodeF64ReinterpretI64: {
                        MUST (wasmCWriteUnaryExpr(writer, wasmValueTypeF64, "f64_reinterpret_i64"))
                        break;
                    }
                    case wasmOpcodeI64ReinterpretF64: {
                        MUST (wasmCWriteUnaryExpr(writer, wasmValueTypeI64, "i64_reinterpret_f64"))
                        break;
                    }
                    default: {
                        fprintf(
                            stderr,
                            "w2c2: unsupported opcode %s (0x%X)\n",
                            wasmOpcodeDescription(*opcode),
                            *opcode
                        );
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

static
void
wasmCWriteStackDeclarations(
    FILE* file,
    const WasmTypeStack* stackDeclarations,
    const bool pretty
) {
    WasmValueType testType = 0;
    for (; testType < wasmValueType_count; testType++) {
        U32 written = 0;

        U32 stackDeclarationIndex = 0;
        for (; stackDeclarationIndex < stackDeclarations->length; stackDeclarationIndex++) {
            const WasmValueType entry = stackDeclarations->valueTypes[stackDeclarationIndex];
            if (!entry) {
                continue;
            }
            if (!wasmTypeStackIsSet(stackDeclarations, stackDeclarationIndex, testType)) {
                continue;
            }
            if (written == 0) {
                if (pretty) {
                    fputs(indentation, file);
                }
                fputs(valueTypeNames[testType], file);
                fputc(' ', file);
            } else {
                if (pretty) {
                    fputs(", ", file);
                } else {
                    fputc(',', file);
                }
            }

            wasmCWriteFileStackName(file, stackDeclarationIndex, testType);

            written++;
        }

        if (written > 0) {
            fputs(";\n", file);
        }
    }
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteFunctionReturn(
    const WasmCFunctionWriter* writer,
    const WasmFunctionType functionType
) {
    if (!functionType.resultCount) {
        return true;
    }

    if (writer->stackDeclarations->length > 0) {
        /* TODO: add support for multiple result values */
        const WasmValueType returnType = functionType.resultTypes[0];
        wasmTypeStackClear(writer->typeStack);
        MUST (wasmTypeStackAppend(writer->typeStack, returnType))

        {
            const U32 stackIndex0 = wasmTypeStackGetTopIndex(writer->typeStack, 0);

            MUST (wasmTypeStackSet(writer->stackDeclarations, stackIndex0, returnType))

            MUST (wasmCWriteIndent(writer))
            MUST (wasmCWrite(writer, "return "))
            MUST (wasmCWriteStringStackName(writer->builder, stackIndex0, returnType))
            MUST (wasmCWrite(writer, ";\n"))
        }
    }

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteFunctionBody(
    FILE* file,
    WasmTypeStack* typeStack,
    WasmTypeStack* stackDeclarations,
    WasmLabelStack* labelStack,
    const WasmModule* module,
    const char* moduleName,
    const WasmFunction function,
    WasmDebugLines* debugLines,
    const bool pretty,
    const bool debug,
    const bool multipleModules
) {
    Buffer code = function.code;
    StringBuilder stringBuilder = emptyStringBuilder;
    WasmOpcode opcode = wasmOpcodeUnreachable;
    WasmLabel label = wasmEmptyLabel;
    WasmValueType* resultType = NULL;

    const WasmFunctionType functionType =
        module->functionTypes.functionTypes[function.functionTypeIndex];

    if (functionType.resultCount) {
        resultType = &functionType.resultTypes[0];
        /* TODO: add support for multiple result values */
        if (functionType.resultCount > 1) {
            fprintf(stderr, "w2c2: function with multiple return values\n");
            return false;
        }
    } else {
        resultType = NULL;
    }

    MUST (stringBuilderInitialize(&stringBuilder))

    {
        WasmCFunctionWriter writer;
        writer.builder = &stringBuilder;
        writer.typeStack = typeStack;
        writer.stackDeclarations = stackDeclarations;
        writer.labelStack = labelStack;
        writer.module = module;
        writer.moduleName = moduleName;
        writer.function = function;
        writer.code = &code;
        writer.indent = 0;
        writer.ignore = false;
        writer.pretty = pretty;
        writer.debug = debug;
        writer.multipleModules = multipleModules;
        writer.debugLines = debugLines;

        MUST (wasmLabelStackPush(writer.labelStack, 0, resultType, &label))
        MUST (wasmCWriteFunctionCode(&writer, &opcode))
        MUST (wasmCWriteLabel(&writer, label.index))
        MUST (wasmCWriteFunctionReturn(&writer, functionType))
    }

    fputs("{\n", file);
    wasmCWriteFileLocalsDeclarations(file, module, function, pretty);
    wasmCWriteStackDeclarations(file, stackDeclarations, pretty);
    fputs(stringBuilder.string, file);
    fputs("}\n", file);

    stringBuilderFree(&stringBuilder);

    return true;
}

static
void
wasmCWriteFileParameters(
    FILE* file,
    const char* moduleName,
    const WasmFunctionType functionType,
    const bool writeParameterNames,
    const bool voidPointerInstanceType,
    const bool pretty
) {
    fputc('(', file);
    if (voidPointerInstanceType) {
        fputs("void*", file);
    } else {
        fputs(moduleName, file);
        fputs("Instance*", file);
    }

    if (writeParameterNames) {
        if (pretty) {
            fputs(" i", file);
        } else {
            fputc('i', file);
        }
    }
    {
        U32 parameterIndex = 0;
        for (; parameterIndex < functionType.parameterCount; parameterIndex++) {
            const WasmValueType parameterType = functionType.parameterTypes[parameterIndex];
            const char* parameterTypeName = valueTypeNames[parameterType];
            if (pretty) {
                fputs(", ", file);
            } else {
                fputc(',', file);
            }
            fputs(parameterTypeName, file);
            if (writeParameterNames) {
                fputc(' ', file);
                wasmCWriteFileLocalName(file, parameterIndex);
            }
        }
    }
    fputc(')', file);
}


static
void
wasmCWriteFileFunctionSignature(
    FILE* file,
    const WasmModule* module,
    const char* moduleName,
    const WasmFunction function,
    const U32 functionIndex,
    const bool writeParameterNames,
    const bool pretty,
    const bool prefix
) {
    const WasmFunctionType functionType =
        module->functionTypes.functionTypes[function.functionTypeIndex];

    fputs(wasmCGetReturnType(functionType), file);
    fputc(' ', file);
    if (prefix) {
        fputs(moduleName, file);
        fputc('_', file);
    }
    wasmCWriteFileFunctionNonImportName(file, functionIndex);
    wasmCWriteFileParameters(
        file,
        moduleName,
        functionType,
        writeParameterNames,
        false,
        pretty
    );
}

static
void
wasmCWriteFunctionDeclarations(
    FILE* file,
    const WasmModule* module,
    const char* moduleName,
    const bool pretty,
    const bool debug,
    const bool multipleModules
) {
    const size_t functionImportCount = module->functionImports.length;
    const U32 functionCount = module->functions.count;

    U32 declaredFunctionIndex = 0;
    for (; declaredFunctionIndex < functionCount; declaredFunctionIndex++) {
        const WasmFunction function = module->functions.functions[declaredFunctionIndex];
        const U32 moduleFunctionIndex = assertSizeU32(functionImportCount) + declaredFunctionIndex;
        wasmCWriteFileFunctionSignature(
            file,
            module,
            moduleName,
            function,
            moduleFunctionIndex,
            false,
            pretty,
            multipleModules
        );

        if (debug && function.exportName == NULL && moduleFunctionIndex < module->functionNames.length) {
            char* functionName = module->functionNames.names[moduleFunctionIndex];
            if (functionName != NULL) {
                fprintf(file, " __asm__(\"%s_%s\")", moduleName, functionName);
            }
        }
        fputs(";\n\n", file);
    }
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteFunctionImplementations(
    FILE* file,
    const WasmModule* module,
    const char* moduleName,
    WasmDebugLines* debugLines,
    const U32 startIDIndex,
    const U32 endIDIndex,
    const WasmFunctionIDs functionIDs,
    const bool pretty,
    const bool debug,
    const bool multipleModules
) {
    const size_t functionImportCount = module->functionImports.length;

    WasmTypeStack typeStack = wasmEmptyTypeStack;
    WasmTypeStack stackDeclarations = wasmEmptyTypeStack;
    WasmLabelStack labelStack = wasmEmptyLabelStack;

    U32 functionIDIndex = startIDIndex;
    for (; functionIDIndex < endIDIndex; functionIDIndex++) {
        const WasmFunctionID functionID = functionIDs.functionIDs[functionIDIndex];
        const U32 functionIndex = functionID.functionIndex;
        const WasmFunction function = module->functions.functions[functionIndex];

        wasmTypeStackClear(&typeStack);
        wasmTypeStackClear(&stackDeclarations);
        wasmLabelStackClear(&labelStack);

        if (debug) {
            const WasmDebugLine* debugLine = wasmCGetDebugLine(debugLines, function.start);
            if (debugLine != NULL) {
                fprintf(file, "#line %u \"%s\"\n", (U32)debugLine->number, debugLine->path);
            }
        }

        wasmCWriteFileFunctionSignature(
            file,
            module,
            moduleName,
            function,
            assertSizeU32(functionImportCount) + functionIndex,
            true,
            pretty,
            multipleModules
        );
        fputc(' ', file);
        MUST (wasmCWriteFunctionBody(
            file,
            &typeStack,
            &stackDeclarations,
            &labelStack,
            module,
            moduleName,
            function,
            debugLines,
            pretty,
            debug,
            multipleModules
        ))
        fputs("\n", file);
    }

    wasmTypeStackFree(&typeStack);
    wasmTypeStackFree(&stackDeclarations);
    wasmLabelsFree(&labelStack.labels);

    return true;
}

static
W2C2_INLINE
void
wasmCWriteGlobalImportType(
    FILE* file,
    const WasmGlobalImport import
) {
    fputs(valueTypeNames[import.globalType.valueType], file);
    fputc('*', file);
}

static
void
wasmCWriteGlobalImports(
    FILE* file,
    const WasmModule* module,
    const bool pretty
) {
    const size_t globalImportCount = module->globalImports.length;
    U32 globalIndex = 0;
    for (; globalIndex < globalImportCount; globalIndex++) {
        const WasmGlobalImport import = module->globalImports.imports[globalIndex];
        if (pretty) {
            fputs(indentation, file);
        }
        wasmCWriteGlobalImportType(file, import);
        if (pretty) {
            fputc(' ', file);
        }
        wasmCWriteFileImportName(file, import.module, import.name);
        fputs(";\n", file);
    }
}

static
void
wasmCWriteGlobals(
    FILE* file,
    const WasmModule* module,
    const bool pretty
) {
    const size_t globalImportCount = module->globalImports.length;
    const U32 globalCount = module->globals.count;

    U32 globalIndex = 0;
    for (; globalIndex < globalCount; globalIndex++) {
        const WasmGlobal global = module->globals.globals[globalIndex];
        if (pretty) {
            fputs(indentation, file);
        }
        fputs(valueTypeNames[global.type.valueType], file);
        fputc(' ', file);
        wasmCWriteFileGlobalNonImportName(file, assertSizeU32(globalImportCount) + globalIndex);
        fputs(";\n", file);
    }
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteConstantExpr(
    StringBuilder* builder,
    const WasmModule* module,
    Buffer code
) {
    WasmOpcode opcode;
    MUST (wasmOpcodeRead(&code, &opcode))
    switch (opcode) {
        case wasmOpcodeI32Const:
        case wasmOpcodeI64Const:
        case wasmOpcodeF32Const:
        case wasmOpcodeF64Const: {
            const WasmValueType resultType = wasmOpcodeResultType(opcode);
            WasmConstInstruction instruction;
            if (!wasmConstInstructionRead(&code, opcode, &instruction)) {
                fprintf(stderr, "w2c2: invalid const instruction encoding\n");
                return false;
            }
            MUST (wasmCWriteLiteral(builder, resultType, instruction.value))
            break;
        }
        case wasmOpcodeGlobalGet: {
            WasmGlobalInstruction instruction;
            MUST (wasmGlobalInstructionRead(&code, &instruction))
            MUST (wasmCWriteStringGlobalUse(builder, module, instruction.globalIndex, false))
            break;
        }
        default: {
            fprintf(stderr, "w2c2: invalid init expression instruction %s\n", wasmOpcodeDescription(opcode));
            return false;
        }
    }

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteInitGlobals(
    FILE* file,
    const WasmModule* module,
    const char* moduleName,
    const bool pretty
) {
    const size_t globalImportCount = module->globalImports.length;
    const U32 globalCount = module->globals.count;

    if (globalCount > 0) {
        StringBuilder stringBuilder = emptyStringBuilder;
        MUST (stringBuilderInitialize(&stringBuilder))

        fprintf(file, "static void %sInitGlobals(%sInstance* i) {\n", moduleName, moduleName);

        {
            U32 globalIndex = 0;
            for (; globalIndex < globalCount; globalIndex++) {
                const WasmGlobal global = module->globals.globals[globalIndex];

                if (pretty) {
                    fputs(indentation, file);
                }
                wasmCWriteFileGlobalUse(file, module, assertSizeU32(globalImportCount) + globalIndex, false);
                if (pretty) {
                    fputs(" = ", file);
                } else {
                    fputc('=', file);
                }
                {
                    const Buffer code = global.init;
                    MUST (stringBuilderReset(&stringBuilder))

                    MUST (wasmCWriteConstantExpr(&stringBuilder, module, code))
                    fputs(stringBuilder.string, file);
                }
                fputs(";\n", file);
            }
        }

        fputs("}\n\n", file);

        stringBuilderFree(&stringBuilder);
    }

    return true;
}

static
W2C2_INLINE
void
wasmCWriteInitImportAssignment(
    FILE* file,
    const char* module,
    const char* name,
    const bool pretty
) {
    if (pretty) {
        fputs(indentation, file);
    }
    fputs("i->", file);
    wasmCWriteFileImportName(file, module, name);
    if (pretty) {
        fputs(" =\n", file);
        if (pretty) {
            fputs(indentation, file);
            fputs(indentation, file);
        }
    } else {
        fputc('=', file);
    }
}

static
W2C2_INLINE
void
wasmCWriteInitImportValue(
    FILE* file,
    const char* module,
    const char* name
) {
    fprintf(file, "resolve(\"%s\", \"%s\");\n", module, name);
}

static
W2C2_INLINE
void
wasmCWriteFunctionImport(
    FILE* file,
    const WasmModule* module,
    const char* moduleName,
    const WasmFunctionImport import,
    const bool declaration,
    const bool pretty,
    const bool prefix
) {
    const WasmFunctionType functionType = module->functionTypes.functionTypes[import.functionTypeIndex];
    fputs(wasmCGetReturnType(functionType), file);
    fputc(' ', file);
    if (declaration) {
        if (prefix) {
            fputs(moduleName, file);
            fputc('_', file);
        }
        wasmCWriteFileImportName(file, import.module, import.name);
    }
    wasmCWriteFileParameters(
        file,
        moduleName,
        functionType,
        false,
        declaration,
        pretty
    );
}

static
void
wasmCWriteInitGlobalImports(
    FILE* file,
    const WasmModule* module,
    const bool pretty
) {
    const size_t globalImportCount = module->globalImports.length;
    U32 globalIndex = 0;
    for (; globalIndex < globalImportCount; globalIndex++) {
        const WasmGlobalImport import = module->globalImports.imports[globalIndex];
        wasmCWriteInitImportAssignment(file, import.module, import.name, pretty);
        fputc('(', file);
        wasmCWriteGlobalImportType(file, import);
        fputc(')', file);
        wasmCWriteInitImportValue(file, import.module, import.name);
    }
}

static
W2C2_INLINE
void
wasmCWriteMemoryType(
    FILE* file
) {
    fputs("wasmMemory*", file);
}

static
void
wasmCWriteInitMemoryImports(
    FILE* file,
    const WasmModule* module,
    const bool pretty
) {
    const size_t memoryImportCount = module->memoryImports.length;

    U32 memoryIndex = 0;
    for (; memoryIndex < memoryImportCount; memoryIndex++) {
        const WasmMemoryImport import = module->memoryImports.imports[memoryIndex];
        wasmCWriteInitImportAssignment(file, import.module, import.name, pretty);
        fputc('(', file);
        wasmCWriteMemoryType(file);
        fputc(')', file);
        wasmCWriteInitImportValue(file, import.module, import.name);
    }
}

static
W2C2_INLINE
void
wasmCWriteTableType(
    FILE* file
) {
    fputs("wasmTable*", file);
}

static
void
wasmCWriteInitTableImports(
    FILE* file,
    const WasmModule* module,
    const bool pretty
) {
    const size_t tableImportCount = module->tableImports.length;

    U32 tableIndex = 0;
    for (; tableIndex < tableImportCount; tableIndex++) {
        const WasmTableImport import = module->tableImports.imports[tableIndex];
        wasmCWriteInitImportAssignment(file, import.module, import.name, pretty);
        fputc('(', file);
        wasmCWriteTableType(file);
        fputc(')', file);
        wasmCWriteInitImportValue(file, import.module, import.name);
    }
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteInitImports(
    FILE* file,
    const WasmModule* module,
    const char* moduleName,
    const bool pretty
) {
    fprintf(
        file,
        "static void %sInitImports(%sInstance* i, void* resolve(const char* module, const char* name)) {\n",
        moduleName,
        moduleName
    );
    if (pretty) {
        fputs(indentation, file);
    }
    fputs("if (resolve == NULL) { return; }\n", file);

    wasmCWriteInitMemoryImports(file, module, pretty);
    wasmCWriteInitTableImports(file, module, pretty);
    wasmCWriteInitGlobalImports(file, module, pretty);

    fputs("}\n\n", file);

    return true;
}

static
W2C2_INLINE
void
wasmCWriteExportName(
    FILE* file,
    const char* moduleName,
    const char* name
) {
    fprintf(file, "%s_", moduleName);
    wasmCWriteFileEscaped(file, name);
}

static
void
wasmCWriteFunctionExport(
    FILE* file,
    const WasmModule* module,
    const char* moduleName,
    const WasmExport export,
    const WasmFunctionType functionType,
    const bool writeBody,
    const bool pretty,
    const bool multipleModules
) {
    const U32 parameterCount = functionType.parameterCount;

    fputs(wasmCGetReturnType(functionType), file);
    fputc(' ', file);
    wasmCWriteExportName(file, moduleName, export.name);
    wasmCWriteFileParameters(
        file,
        moduleName,
        functionType,
        true,
        false,
        pretty
    );
    if (writeBody) {
        if (pretty) {
            fputc(' ', file);
        }
        fputs("{\n", file);
        if (pretty) {
            fputs(indentation, file);
        }
        if (functionType.resultCount > 0) {
            fputs("return ", file);
        }
        wasmCWriteFileFunctionUse(file, module, moduleName, export.index, false, multipleModules);
        fputs("(i", file);
        {
            U32 parameterIndex = 0;
            for (; parameterIndex < parameterCount; parameterIndex++) {
                if (pretty) {
                    fputs(", ", file);
                } else {
                    fputc(',', file);
                }
                wasmCWriteFileLocalName(file, parameterIndex);
            }
        }
        fputs(");\n}\n\n", file);
    } else {
        fputs(";\n\n", file);
    }
}

static
void
wasmCWriteMemoryExport(
    FILE* file,
    const WasmModule* module,
    const char* moduleName,
    const WasmExport export,
    const bool writeBody,
    const bool pretty
) {
    wasmCWriteMemoryType(file);
    if (pretty) {
        fputc(' ', file);
    }
    wasmCWriteExportName(file, moduleName, export.name);
    fprintf(file, "(%sInstance* i)", moduleName);
    if (writeBody) {
        if (pretty) {
            fputc(' ', file);
        }
        fputs("{\n", file);
        if (pretty) {
            fputs(indentation, file);
        }
        fputs("return ", file);
        wasmCWriteFileMemoryUse(file, module, export.index, NULL, true);
        fputs(";\n}\n\n", file);
    } else {
        fputs(";\n\n", file);
    }
}

static
void
wasmCWriteExports(
    FILE* file,
    const WasmModule* module,
    const char* moduleName,
    const bool writeBody,
    const bool pretty,
    const bool multipleModules
) {
    const size_t functionImportCount = module->functionImports.length;
    const U32 exportCount = module->exports.count;

    U32 exportIndex = 0;
    for (; exportIndex < exportCount; exportIndex++) {
        const WasmExport export = module->exports.exports[exportIndex];
        switch (export.kind) {
            case wasmExportKindFunction: {
                WasmFunctionType functionType = wasmEmptyFunctionType;
                U32 functionTypeIndex = 0;
                if (export.index < functionImportCount) {
                    const WasmFunctionImport import = module->functionImports.imports[export.index];
                    functionTypeIndex = import.functionTypeIndex;
                } else {
                    const WasmFunction function = module->functions.functions[export.index - functionImportCount];
                    functionTypeIndex = function.functionTypeIndex;
                }
                functionType = module->functionTypes.functionTypes[functionTypeIndex];
                wasmCWriteFunctionExport(file, module, moduleName, export, functionType, writeBody, pretty, multipleModules);
                break;
            }
            case wasmExportKindMemory: {
                wasmCWriteMemoryExport(file, module, moduleName, export, writeBody, pretty);
                break;
            }
            default: {
                /* TODO: other export kinds */
                fprintf(
                    stderr,
                    "w2c2: unsupported export: %s (%s)\n",
                    export.name,
                    wasmExportKindDescription(export.kind)
                );
            }
        }
    }
}

/* TODO: add support for multiple modules */
static
void
wasmCWriteDataSegments(
    FILE* file,
    const WasmModule* module,
    const WasmDataSegmentMode mode,
    const bool pretty
) {
    const U32 dataSegmentCount = module->dataSegments.count;

    {
        U32 dataSegmentIndex = 0;
        for (; dataSegmentIndex < dataSegmentCount; dataSegmentIndex++) {
            const WasmDataSegment dataSegment = module->dataSegments.dataSegments[dataSegmentIndex];

            switch (mode) {
                case wasmDataSegmentModeArrays: {
                    fputs("const U8 ", file);
                    /* TODO: add support for multiple modules */
                    wasmCWriteFileDataSegmentName(file, dataSegmentIndex);
                    if (pretty) {
                        fputs("[] = {\n", file);
                    } else {
                        fputs("[]={\n", file);
                    }
                    if (pretty) {
                        fputs(indentation, file);
                    }
                    {
                        U32 byteIndex = 0;
                        for (; byteIndex < dataSegment.bytes.length; byteIndex++) {
                            fprintf(file, "0x%x", dataSegment.bytes.data[byteIndex]);
                            if (pretty) {
                                fputs(", ", file);
                            } else {
                                fputc(',', file);
                            }
                        }
                    }
                    fputs("\n};\n\n", file);
                    break;
                }
                case wasmDataSegmentModeGNULD:
                case wasmDataSegmentModeSectcreate1:
                case wasmDataSegmentModeSectcreate2: {
                    fputs("U8* ", file);
                    /* TODO: add support for multiple modules */
                    wasmCWriteFileDataSegmentName(file, dataSegmentIndex);
                    fputs(";\n", file);
                    break;
                }
                default: {
                    fprintf(stderr, "w2c2: unsupported data segment mode: %d\n", mode);
                    abort();
                }
            }
        }
    }
}

static
void
wasmCWriteDataSegmentsFromSection(
    FILE* file,
    const WasmModule* module,
    const WasmDataSegmentMode mode
) {
    static const char* const filename = "datasegments";
    const U32 dataSegmentCount = module->dataSegments.count;

    U32 dataSegmentIndex = 0;
    FILE* segmentsFile = NULL;

    switch (mode) {
        case wasmDataSegmentModeGNULD: {
            fputs("extern char _binary_datasegments_start[];\n\n", file);
            fputs("static char* ds = _binary_datasegments_start;\n", file);
            break;
        }
        case wasmDataSegmentModeSectcreate1: {
            fputs("extern char data_segments_data __asm(\"section$start$__DATA$__datasegments\");\n\n", file);
            fputs("static char* ds = &data_segments_data;\n", file);
            break;
        }
        case wasmDataSegmentModeSectcreate2: {
            /*
             * On Rhapsody, mach-o/getsect.h was added.
             * On OPENSTEP, libc.h is needed.
             */
            fputs(
                "#include <mach/mach.h>\n"
                "#ifdef __MACH30__\n"
                "#include <mach-o/getsect.h>\n"
                "#define SECT_DATA_SIZE_TYPE unsigned long\n"
                "#else\n"
                "#include <libc.h>\n"
                "#define SECT_DATA_SIZE_TYPE int\n"
                "#endif\n",
                file
            );
            fputs(
                "SECT_DATA_SIZE_TYPE len = 0;\n"
                "static char* ds = getsectdata(\"__DATA\", \"__datasegments\", &len);\n",
                file
            );
            break;
        }
        default: {
            fprintf(stderr, "w2c2: unsupported data segment mode: %d\n", mode);
            abort();
        }
    }

    segmentsFile = fopen(filename, "wb");
    if (segmentsFile == NULL) {
        fprintf(
            stderr,
            "w2c2: failed to create data segments file %s: %s\n",
            filename,
            strerror(errno)
        );
        abort();
    }

    for (; dataSegmentIndex < dataSegmentCount; dataSegmentIndex++) {
        const WasmDataSegment dataSegment = module->dataSegments.dataSegments[dataSegmentIndex];
        const size_t length = dataSegment.bytes.length;
        const size_t written = fwrite(dataSegment.bytes.data, 1, length, segmentsFile);
        if (written != length) {
            fprintf(
                stderr,
                "w2c2: failed to write data segment %u: %s",
                dataSegmentIndex,
                strerror(errno)
            );
            abort();
        }
    }

    if (fclose(segmentsFile) != 0) {
        fprintf(
            stderr,
            "w2c2: failed to close data segments file %s: %s",
            filename,
            strerror(errno)
        );
        abort();
    }
}

static
void
wasmCWriteMemoryImports(
    FILE* file,
    const WasmModule* module,
    const bool pretty
) {
    const size_t memoryImportCount = module->memoryImports.length;

    U32 memoryIndex = 0;
    for (; memoryIndex < memoryImportCount; memoryIndex++) {
        const WasmMemoryImport import = module->memoryImports.imports[memoryIndex];
        if (pretty) {
            fputs(indentation, file);
        }
        wasmCWriteMemoryType(file);
        if (pretty) {
            fputc(' ', file);
        }
        wasmCWriteFileImportName(file, import.module, import.name);
        fputs(";\n", file);
    }
}

static
void
wasmCWriteMemories(
    FILE* file,
    const WasmModule* module,
    const bool pretty
) {
    const size_t memoryImportCount = module->memoryImports.length;
    const U32 memoryCount = module->memories.count;

    U32 memoryIndex = 0;
    for (; memoryIndex < memoryCount; memoryIndex++) {
        U32 moduleMemoryIndex = assertSizeU32(memoryImportCount) + memoryIndex;
        if (pretty) {
            fputs(indentation, file);
        }
        fputs("wasmMemory* ", file);
        wasmCWriteFileMemoryNonImportName(file, moduleMemoryIndex);
        fputs(";\n", file);
    }
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteInitMemories(
    FILE* file,
    const WasmModule* module,
    const char* moduleName,
    const WasmDataSegmentMode dataSegmentMode,
    const bool pretty
) {
    const size_t memoryImportCount = module->memoryImports.length;
    const U32 memoryCount = module->memories.count;
    if (memoryCount > 0) {

        StringBuilder stringBuilder = emptyStringBuilder;
        MUST (stringBuilderInitialize(&stringBuilder))

        fprintf(
            file,
            "static void %sInitMemories(%sInstance* i, %sInstance* parent) {\n",
            moduleName,
            moduleName,
            moduleName
        );

        {
            U32 memoryIndex = 0;
            for (; memoryIndex < memoryCount; memoryIndex++) {
                const WasmMemory memory = module->memories.memories[memoryIndex];
                U32 moduleMemoryIndex = assertSizeU32(memoryImportCount) + memoryIndex;

                if (memory.shared) {
                    if (pretty) {
                        fputs(indentation, file);
                    }
                    fputs("if (parent == NULL) {\n", file);
                    {
                        if (pretty) {
                            fputs(indentation, file);
                            fputs(indentation, file);
                        }
                        wasmCWriteFileMemoryUse(file, module, moduleMemoryIndex, NULL, true);
                        fprintf(file, "= WASM_MEMORY_ALLOCATE_SHARED(%u, %u);\n", memory.min, memory.max);
                    }
                    if (pretty) {
                        fputs(indentation, file);
                    }
                    fputs("} else {\n", file);
                    {
                        if (pretty) {
                            fputs(indentation, file);
                            fputs(indentation, file);
                        }
                        wasmCWriteFileMemoryUse(file, module, moduleMemoryIndex, NULL, true);
                        fputs(" = ", file);
                        wasmCWriteFileMemoryUse(file, module, moduleMemoryIndex, "parent", true);
                        fputs(";\n", file);
                    }
                    if (pretty) {
                        fputs(indentation, file);
                    }
                    fputs("}\n", file);
                } else {
                    if (pretty) {
                        fputs(indentation, file);
                    }
                    wasmCWriteFileMemoryUse(file, module, moduleMemoryIndex, NULL, true);
                    fprintf(file, " = wasmMemoryAllocate(%u, %u, false);\n", memory.min, memory.max);
                }
            }
        }

        {
            const U32 dataSegmentCount = module->dataSegments.count;
            U32 dataSegmentIndex = 0;
            U64 byteOffset = 0;
            for (; dataSegmentIndex < dataSegmentCount; dataSegmentIndex++) {
                const WasmDataSegment dataSegment = module->dataSegments.dataSegments[dataSegmentIndex];
                const size_t dataSegmentLength = dataSegment.bytes.length;
                const Buffer code = dataSegment.offset;

                switch (dataSegmentMode) {
                    case wasmDataSegmentModeGNULD:
                    case wasmDataSegmentModeSectcreate1:
                    case wasmDataSegmentModeSectcreate2: {
                        /* TODO: add support for multiple modules */
                        wasmCWriteFileDataSegmentName(file, dataSegmentIndex);
                        if (pretty) {
                            fprintf(file, " = ds + %llu", byteOffset);
                        } else {
                            fprintf(file, "=ds+%llu", byteOffset);
                        }
                        fputs(";\n", file);
                        break;
                    }
                }

                /* Load active segments */
                if (code.data != NULL) {
                    if (pretty) {
                        fputs(indentation, file);
                    }
                    fputs("LOAD_DATA(", file);
                    wasmCWriteFileMemoryUse(
                            file,
                            module,
                            dataSegment.memoryIndex,
                            NULL,
                            false
                    );
                    fputs(", ", file);
                    MUST (stringBuilderReset(&stringBuilder))
                    MUST (wasmCWriteConstantExpr(&stringBuilder, module, code))
                    fputs(stringBuilder.string, file);
                    fputs(", ", file);
                    /* TODO: add support for multiple modules */
                    wasmCWriteFileDataSegmentName(file, dataSegmentIndex);
                    fprintf(file, ", %lu);\n", (unsigned long) dataSegmentLength);
                }

                byteOffset += dataSegment.bytes.length;
            }
        }

        fputs("}\n\n", file);

        stringBuilderFree(&stringBuilder);
    }
    return true;
}

static
void
wasmCWriteFreeMemories(
    FILE* file,
    const WasmModule* module,
    const bool pretty
) {
    const size_t memoryImportCount = module->memoryImports.length;
    const U32 memoryCount = module->memories.count;
    U32 memoryIndex = 0;
    for (; memoryIndex < memoryCount; memoryIndex++) {
        U32 moduleMemoryIndex = assertSizeU32(memoryImportCount) + memoryIndex;
        if (pretty) {
            fputs(indentation, file);
        }
        fputs("wasmMemoryFree(", file);
        wasmCWriteFileMemoryUse(file, module, moduleMemoryIndex, NULL, true);
        fputs(");\n", file);
    }
}

static
void
wasmCWriteTableImports(
    FILE* file,
    const WasmModule* module,
    const bool pretty
) {
    const size_t tableImportCount = module->tableImports.length;

    U32 tableIndex = 0;
    for (; tableIndex < tableImportCount; tableIndex++) {
        const WasmTableImport import = module->tableImports.imports[tableIndex];
        if (pretty) {
            fputs(indentation, file);
        }
        wasmCWriteTableType(file);
        if (pretty) {
            fputc(' ', file);
        }
        wasmCWriteFileImportName(file, import.module, import.name);
        fputs(";\n", file);
    }
}

static
void
wasmCWriteTables(
    FILE* file,
    const WasmModule* module,
    const bool pretty
) {
    const size_t tableImportCount = module->tableImports.length;
    const U32 tableCount = module->tables.count;

    U32 tableIndex = 0;
    for (; tableIndex < tableCount; tableIndex++) {
        if (pretty) {
            fputs(indentation, file);
        }
        fputs("wasmTable ", file);
        wasmCWriteFileTableNonImportName(file, assertSizeU32(tableImportCount) + tableIndex);
        fputs(";\n", file);
    }
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteInitTables(
    FILE* file,
    const WasmModule* module,
    const char* moduleName,
    const bool pretty,
    const bool multipleModules
) {
    const size_t tableImportCount = module->tableImports.length;
    const U32 elementSegmentCount = module->elementSegments.count;
    const U32 tableCount = module->tables.count;
    if (tableCount > 0 || elementSegmentCount > 0) {
        StringBuilder stringBuilder = emptyStringBuilder;
        MUST (stringBuilderInitialize(&stringBuilder))

        fprintf(file, "static void %sInitTables(%sInstance* i) {\n", moduleName, moduleName);

        if (elementSegmentCount > 0) {
            if (pretty) {
                fputs(indentation, file);
            }
            fputs("U32 offset;\n", file);
        }

        {
            U32 tableIndex = 0;
            for (; tableIndex < tableCount; tableIndex++) {
                const WasmTable table = module->tables.tables[tableIndex];

                if (pretty) {
                    fputs(indentation, file);
                }
                fputs("wasmTableAllocate(", file);
                wasmCWriteFileTableUse(file, module, assertSizeU32(tableImportCount) + tableIndex, true);
                fprintf(file, ", %u, %u);\n", table.min, table.max);
            }
        }

        {
            U32 elementSegmentIndex = 0;
            for (; elementSegmentIndex < elementSegmentCount; elementSegmentIndex++) {
                const WasmElementSegment elementSegment = module->elementSegments.elementSegments[elementSegmentIndex];

                if (pretty) {
                    fputs(indentation, file);
                    fputs("offset = ", file);
                } else {
                    fputs("offset=", file);
                }
                {
                    const Buffer code = elementSegment.offset;
                    MUST (stringBuilderReset(&stringBuilder))
                    MUST (wasmCWriteConstantExpr(&stringBuilder, module, code))
                    fputs(stringBuilder.string, file);
                }
                fputs(";\n", file);

                {
                    U32 functionIndexIndex = 0;
                    for (; functionIndexIndex < elementSegment.functionIndexCount; functionIndexIndex++) {
                        const U32 functionIndex = elementSegment.functionIndices[functionIndexIndex];
                        if (pretty) {
                            fputs(indentation, file);
                        }
                        wasmCWriteFileTableUse(file, module, elementSegment.tableIndex, false);
                        if (pretty) {
                            fprintf(file, ".data[offset + %u] = (wasmFunc)", functionIndexIndex);
                        } else {
                            fprintf(file, ".data[offset+%u]=(wasmFunc)", functionIndexIndex);
                        }
                        wasmCWriteFileFunctionUse(file, module, moduleName, functionIndex, true, multipleModules);
                        fputs(";\n", file);
                    }
                }
            }
        }

        fputs("}\n\n", file);

        stringBuilderFree(&stringBuilder);
    }

    return true;
}

static
void
wasmCWriteFreeTables(
    FILE* file,
    const WasmModule* module,
    const bool pretty
) {
    const size_t tableImportCount = module->tableImports.length;
    const U32 tableCount = module->tables.count;
    U32 tableIndex = 0;
    for (; tableIndex < tableCount; tableIndex++) {
        if (pretty) {
            fputs(indentation, file);
        }
        fputs("wasmTableFree(", file);
        wasmCWriteFileTableUse(file, module, assertSizeU32(tableImportCount) + tableIndex, true);
        fputs(");\n", file);
    }
}

static
void
wasmCWriteFunctionImports(
    FILE* file,
    const WasmModule* module,
    const char* moduleName,
    const bool pretty,
    const bool multipleModules
) {
    const size_t functionImportCount = module->functionImports.length;
    U32 functionIndex = 0;
    for (; functionIndex < functionImportCount; functionIndex++) {
        const WasmFunctionImport import = module->functionImports.imports[functionIndex];
        if (pretty) {
            fputs(indentation, file);
        }
        wasmCWriteFunctionImport(file, module, moduleName, import, true, pretty, multipleModules);
        fputs(";\n\n", file);
    }
}

static
W2C2_INLINE
void
wasmCWriteBaseInclude(
    FILE* file
) {
    fputs("#include \"w2c2_base.h\"\n\n", file);
}

static
W2C2_INLINE
void
wasmCWriteIncludes(
    FILE* file,
    const char* headerName
) {
    wasmCWriteBaseInclude(file);
    fprintf(file, "#include \"%s\"\n\n", headerName);
}

static
void
wasmCWriteModuleInstanceDeclaration(
    FILE* file,
    const WasmModule* module,
    const char* moduleName,
    const bool pretty
) {
    fprintf(file, "typedef struct %sInstance {\n", moduleName);

    if (pretty) {
        fputs(indentation, file);
    }
    fputs("wasmModuleInstance common;\n", file);

    wasmCWriteMemoryImports(file, module, pretty);
    wasmCWriteTableImports(file, module, pretty);
    wasmCWriteGlobalImports(file, module, pretty);

    wasmCWriteMemories(file, module, pretty);
    wasmCWriteTables(file, module, pretty);
    wasmCWriteGlobals(file, module, pretty);

    fprintf(file, "} %sInstance;\n\n", moduleName);
}

static
void
wasmCWriteModuleDeclarations(
    FILE* file,
    const WasmModule* module,
    const char* moduleName,
    const bool pretty,
    const bool debug,
    const bool multipleModules
) {
    wasmCWriteModuleInstanceDeclaration(file, module, moduleName, pretty);
    wasmCWriteFunctionImports(file, module, moduleName, pretty, multipleModules);
    wasmCWriteFunctionDeclarations(file, module, moduleName, pretty, debug, multipleModules);
    wasmCWriteExports(file, module, moduleName, false, pretty, multipleModules);
}

/* TODO: verify */
static
void
wasmCWriteNewChildFunction(
    FILE* file,
    const WasmModule* module,
    const char* moduleName,
    const bool pretty,
    const bool multipleModules
) {
    fprintf(
        file,
        "%sInstance* %sNewChild(%sInstance* self) {\n",
        moduleName,
        moduleName,
        moduleName
    );

    /* TODO: clean up */
    if (pretty) {
        fputs(indentation, file);
    }
    fprintf(
        file,
        "%sInstance* child = (%sInstance*)calloc(1, sizeof(%sInstance));\n",
        moduleName,
        moduleName,
        moduleName
    );

    if (pretty) {
        fputs(indentation, file);
    }
    fputs("child->common.funcExports = self->common.funcExports;\n", file);

    if (pretty) {
        fputs(indentation, file);
    }
    fputs("child->common.resolveImports = self->common.resolveImports;\n", file);

    if (pretty) {
        fputs(indentation, file);
    }
    fputs("child->common.newChild = self->common.newChild;\n", file);

    if (pretty) {
        fputs(indentation, file);
    }
    fprintf(file, "%sInitImports(child, self->common.resolveImports);\n", moduleName);

    if (module->memories.count > 0) {
        if (pretty) {
            fputs(indentation, file);
        }
        fprintf(file, "%sInitMemories(child, self);\n", moduleName);
    }

    if (module->tables.count > 0
        || module->elementSegments.count > 0
            ) {
        if (pretty) {
            fputs(indentation, file);
        }
        fprintf(file, "%sInitTables(child);\n", moduleName);
    }

    if (module->globals.count > 0) {
        if (pretty) {
            fputs(indentation, file);
        }
        fprintf(file, "%sInitGlobals(child);\n", moduleName);
    }

    if (module->hasStartFunction) {
        if (pretty) {
            fputs(indentation, file);
        }
        wasmCWriteFileFunctionUse(file, module, moduleName, module->startFunctionIndex, false, multipleModules);
        fputs("(child);\n", file);
    }

    if (pretty) {
        fputs(indentation, file);
    }
    fputs("return child;\n", file);

    fputs("}\n\n", file);
}


static
void
wasmCWriteInstantiateFunction(
    FILE* file,
    const WasmModule* module,
    const char* moduleName,
    const bool pretty,
    const bool multipleModules
) {
    fprintf(
        file,
        "void %sInstantiate(%sInstance* i, void* resolveImports(const char* module, const char* name)) {\n",
        moduleName,
        moduleName
    );

    if (pretty) {
        fputs(indentation, file);
    }
    fprintf(file, "i->common.funcExports = %sFuncExports;\n", moduleName);

    if (pretty) {
        fputs(indentation, file);
    }
    fputs("i->common.resolveImports = resolveImports;\n", file);

    if (pretty) {
        fputs(indentation, file);
    }
    fprintf(file, "i->common.newChild = (struct wasmModuleInstance* (*)(struct wasmModuleInstance*))%sNewChild;\n", moduleName);

    if (pretty) {
        fputs(indentation, file);
    }
    fprintf(file, "%sInitImports(i, resolveImports);\n", moduleName);

    if (module->memories.count > 0) {
        if (pretty) {
            fputs(indentation, file);
        }
        fprintf(file, "%sInitMemories(i, NULL);\n", moduleName);
    }

    if (module->tables.count > 0
        || module->elementSegments.count > 0
    ) {
        if (pretty) {
            fputs(indentation, file);
        }
        fprintf(file, "%sInitTables(i);\n", moduleName);
    }

    if (module->globals.count > 0) {
        if (pretty) {
            fputs(indentation, file);
        }
        fprintf(file, "%sInitGlobals(i);\n", moduleName);
    }

    if (module->hasStartFunction) {
        if (pretty) {
            fputs(indentation, file);
        }
        wasmCWriteFileFunctionUse(file, module, moduleName, module->startFunctionIndex, false, multipleModules);
        fputs("(i);\n", file);
    }

    fputs("}\n\n", file);
}

static
void
wasmCWriteFreeFunction(
    FILE* file,
    const WasmModule* module,
    const char* moduleName,
    const bool pretty
) {
    fprintf(file, "void %sFreeInstance(%sInstance* i) {\n", moduleName, moduleName);

    wasmCWriteFreeMemories(file, module, pretty);
    wasmCWriteFreeTables(file, module, pretty);

    fputs("}\n\n", file);
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteModuleHeader(
    const WasmModule* module,
    const char* moduleName,
    const char* filename,
    const bool pretty,
    const bool debug,
    const bool multipleModules
) {
    /* Create file */
    FILE* file = NULL;

    file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(
            stderr,
            "w2c2: failed to create header file %s: %s\n",
            filename,
            strerror(errno)
        );
        return false;
    }

    fprintf(file, "#ifndef %s_H\n", moduleName);
    fprintf(file, "#define %s_H\n\n", moduleName);

    fputs("#ifdef __cplusplus\nextern \"C\" {\n#endif\n\n", file);

    wasmCWriteBaseInclude(file);
    wasmCWriteModuleDeclarations(file, module, moduleName, pretty, debug, multipleModules);
    fprintf(
        file,
        "void %sInstantiate(%sInstance* instance, void* resolve(const char* module, const char* name));\n\n",
        moduleName,
        moduleName
    );
    fprintf(
        file,
        "void %sFreeInstance(%sInstance* instance);\n\n",
        moduleName,
        moduleName
    );

    fputs("#ifdef __cplusplus\n}\n#endif\n\n", file);

    fprintf(file, "#endif /* %s_H */\n\n", moduleName);

    if (fclose(file) != 0) {
        fprintf(
            stderr,
            "w2c2: failed to close header file: %s: %s\n",
            filename,
            strerror(errno)
        );
        return false;
    }

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteModuleFunctionExportsArray(
    FILE* file,
    const WasmModule* module,
    const char* moduleName,
    const bool pretty,
    const bool multipleModules
) {
    U32 functionExportCount = 0;
    {
        U32 exportIndex = 0;
        for (; exportIndex < module->exports.count; exportIndex++) {
            const WasmExport export = module->exports.exports[exportIndex];
            if (export.kind == wasmExportKindFunction) {
                functionExportCount += 1;
            }
        }
    }

    fprintf(
        file,
        "wasmFuncExport %sFuncExports[%u] = {\n",
        moduleName,
        functionExportCount + 1
    );

    {
        U32 exportIndex = 0;
        for (; exportIndex < module->exports.count; exportIndex++) {
            const WasmExport export = module->exports.exports[exportIndex];
            if (export.kind != wasmExportKindFunction) {
                continue;
            }

            fputs("{(wasmFunc)", file);
            wasmCWriteFileFunctionUse(
                file,
                module,
                moduleName,
                export.index,
                false,
                multipleModules
            );
            fprintf(file, ",\"%s\"},\n", export.name);
        }
    }

    fputs("{NULL,NULL}\n};\n\n", file);

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteInits(
    const WasmModule* module,
    const char* moduleName,
    FILE* file,
    const WasmDataSegmentMode dataSegmentMode,
    const bool pretty,
    const bool multipleModules
) {
    MUST (wasmCWriteModuleFunctionExportsArray(file, module, moduleName, pretty, multipleModules))

    MUST (wasmCWriteInitMemories(file, module, moduleName, dataSegmentMode, pretty))
    MUST (wasmCWriteInitTables(file, module, moduleName, pretty, multipleModules))
    MUST (wasmCWriteInitGlobals(file, module, moduleName, pretty))
    MUST (wasmCWriteInitImports(file, module, moduleName, pretty))

    wasmCWriteExports(file, module, moduleName, true, pretty, multipleModules);

    wasmCWriteNewChildFunction(file, module, moduleName, pretty, multipleModules);
    wasmCWriteInstantiateFunction(file, module, moduleName, pretty, multipleModules);
    wasmCWriteFreeFunction(file, module, moduleName, pretty);

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteImplementationFile(
    const WasmModule* module,
    const char* moduleName,
    const char* headerName,
    WasmDebugLines* debugLines,
    const char filePrefix,
    const U32 fileIndex,
    const U32 functionsPerFile,
    const U32 startFunctionIDIndex,
    const WasmFunctionIDs functionIDs,
    const bool pretty,
    const bool debug,
    const bool multipleModules
) {
    FILE* file = NULL;
    char filename[W2C2_IMPL_FILENAME_LENGTH+1];
    const U32 functionCount = (U32)functionIDs.length;

    U32 endFunctionIDIndex = startFunctionIDIndex + (U32)functionsPerFile;
    if (endFunctionIDIndex > functionCount) {
        endFunctionIDIndex = functionCount;
    }

    /* Do not create empty files */
    if (startFunctionIDIndex > endFunctionIDIndex) {
        return true;
    }

    sprintf(filename, "%c%010u.c", filePrefix, fileIndex);
    file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(
            stderr,
            "w2c2: failed to create implementation file %s: %s\n",
            filename,
            strerror(errno)
        );
        return false;
    }

    wasmCWriteIncludes(file, headerName);

    MUST (wasmCWriteFunctionImplementations(
        file,
        module,
        moduleName,
        debugLines,
        startFunctionIDIndex,
        endFunctionIDIndex,
        functionIDs,
        pretty,
        debug,
        multipleModules
    ))

    if (fclose(file) != 0) {
        fprintf(
            stderr,
            "w2c2: failed to close implementation file: %s: %s\n",
            filename,
            strerror(errno)
        );
        return false;
    }

    return true;
}

#if HAS_PTHREAD

typedef struct WasmCImplementationWriterTask {
    char filePrefix;
    U32 fileIndex;
    U32 functionsPerFile;
    const WasmModule* module;
    const char* moduleName;
    const char* headerName;
    U32 startFunctionIDIndex;
    WasmFunctionIDs functionIDs;
    bool pretty;
    bool debug;
    bool multipleModules;
    bool result;
    WasmDebugLines* debugLines;
} WasmCImplementationWriterTask;

typedef struct WasmCImplementationConcurrentWriter {
    pthread_mutex_t mutex;
    pthread_cond_t consume;
    pthread_cond_t produce;
    WasmCImplementationWriterTask* task;
    bool done;
} WasmCImplementationConcurrentWriter;

static
WasmCImplementationConcurrentWriter
wasmCImplementationConcurrentWriterNew(
    void
) {
    WasmCImplementationConcurrentWriter writer;
    pthread_mutex_init(&writer.mutex, NULL);
    pthread_cond_init(&writer.consume, NULL);
    pthread_cond_init(&writer.produce, NULL);
    writer.task = NULL;
    writer.done = false;
    return writer;
}

static
void
wasmCImplementationConcurrentWriterDestroy(
    WasmCImplementationConcurrentWriter* writer
) {
    pthread_mutex_destroy(&writer->mutex);
    pthread_cond_destroy(&writer->consume);
    pthread_cond_destroy(&writer->produce);
}

static
void*
wasmCImplementationWriterThread(
    void* arg
) {
    WasmCImplementationConcurrentWriter* writer = (WasmCImplementationConcurrentWriter*)arg;

    while (true) {
        pthread_mutex_lock(&writer->mutex);
        pthread_cond_signal(&writer->produce);

        while (!writer->done && writer->task == NULL) {
            pthread_cond_wait(
                &writer->consume,
                &writer->mutex
            );
        }

        if (writer->done) {
            pthread_mutex_unlock(&writer->mutex);
            return NULL;
        }

        {
            const WasmCImplementationWriterTask* task = writer->task;

            const WasmModule* module = task->module;
            const char* moduleName = task->moduleName;
            const char* headerName = task->headerName;
            const char filePrefix = task->filePrefix;
            const U32 fileIndex = task->fileIndex;
            const U32 functionsPerFile = task->functionsPerFile;
            const U32 startFunctionIDIndex = task->startFunctionIDIndex;
            const WasmFunctionIDs functionIDs = task->functionIDs;
            const bool pretty = task->pretty;
            const bool debug = task->debug;
            const bool multipleModules = task->multipleModules;
            WasmDebugLines* debugLines = task->debugLines;

            writer->task = NULL;

            pthread_mutex_unlock(&writer->mutex);

            {
                const bool result = wasmCWriteImplementationFile(
                    module,
                    moduleName,
                    headerName,
                    debugLines,
                    filePrefix,
                    fileIndex,
                    functionsPerFile,
                    startFunctionIDIndex,
                    functionIDs,
                    pretty,
                    debug,
                    multipleModules
                );
                if (!result) {
                    const WasmFunctionID startFunctionID = functionIDs.functionIDs[startFunctionIDIndex];
                    fprintf(
                        stderr,
                        "w2c2: failed to write implementation file %d. start function index: %d\n",
                        fileIndex,
                        startFunctionID.functionIndex
                    );
                    exit(1);
                }
            }
        }
    }

    return NULL;
}

#endif /* HAS_PTHREAD */

static
bool
WARN_UNUSED_RESULT
wasmCWriteModuleImplementationFiles(
    const WasmModule* module,
    const char* moduleName,
    const char* headerName,
    WasmFunctionIDs functionIDs,
    char filePrefix,
    WasmCWriteModuleOptions options
) {
    WasmDebugLines debugLines = module->debugLines;

    U32 fileIndex = 0;
    const size_t functionCount = functionIDs.length;
    U32 functionsPerFile = options.functionsPerFile;
    size_t fileCount = 0;
    if (functionCount == 0) {
        return true;
    }
    if (functionsPerFile == 0) {
        functionsPerFile = UINT32_MAX;
    }
    fileCount = 1 + (functionCount - 1) / functionsPerFile;

    {

#if HAS_PTHREAD
        U32 threadCount = options.threadCount;
        pthread_t* threads = calloc(threadCount, sizeof(pthread_t));
        U32 jobIndex = 0;

        bool setDebugLines = options.debug && options.threadCount == 1;

        WasmCImplementationConcurrentWriter writer = wasmCImplementationConcurrentWriterNew();

        WasmCImplementationWriterTask task;
        task.functionsPerFile = functionsPerFile;
        task.module = module;
        task.moduleName = moduleName;
        task.headerName = headerName;
        task.pretty = options.pretty;
        task.debug = options.debug;
        task.multipleModules = options.multipleModules;

        for (; jobIndex < threadCount; jobIndex++) {
            int err = pthread_create(
                &threads[jobIndex],
                NULL,
                wasmCImplementationWriterThread,
                &writer
            );
            if (err) {
                fprintf(
                    stderr,
                    "w2c2: failed to create implementations thread: %s\n",
                    strerror(err)
                );
                return false;
            }
        }
#endif /* HAS_PTHREAD */

        for (; fileIndex < fileCount; fileIndex++) {
            U32 startFunctionIDIndex = fileIndex * functionsPerFile;
#if HAS_PTHREAD
            pthread_mutex_lock(&writer.mutex);

            while (writer.task != NULL) {
                pthread_cond_wait(
                    &writer.produce,
                    &writer.mutex
                );
            }

            task.filePrefix = filePrefix;
            task.fileIndex = fileIndex;
            task.startFunctionIDIndex = startFunctionIDIndex;
            task.functionIDs = functionIDs;
            if (setDebugLines) {
                task.debugLines = &debugLines;
            } else {
                task.debugLines = NULL;
            }

            writer.task = &task;

            pthread_cond_signal(&writer.consume);
            pthread_mutex_unlock(&writer.mutex);

#else
            MUST (wasmCWriteImplementationFile(
                module,
                moduleName,
                headerName,
                &debugLines,
                filePrefix,
                fileIndex,
                functionsPerFile,
                startFunctionIDIndex,
                functionIDs,
                options.pretty,
                options.debug,
                options.multipleModules
            ))
#endif /* HAS_PTHREAD */
        }
#if HAS_PTHREAD

        pthread_mutex_lock(&writer.mutex);

        while (writer.task != NULL) {
            pthread_cond_wait(
                &writer.produce,
                &writer.mutex
            );
        }

        writer.done = true;
        pthread_cond_broadcast(&writer.consume);
        pthread_mutex_unlock(&writer.mutex);

        for (jobIndex = 0; jobIndex < threadCount; jobIndex++) {
            int err = pthread_join(threads[jobIndex], NULL);
            if (err) {
                fprintf(stderr, "w2c2: failed to join writer thread: %s\n", strerror(err));
                return false;
            }
        }

        free(threads);

        wasmCImplementationConcurrentWriterDestroy(&writer);
#endif /* HAS_PTHREAD */
    }

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteModuleImplementation(
    const WasmModule* module,
    const char* moduleName,
    const char* filename,
    const char* headerName,
    const WasmFunctionIDs staticFunctionIDs,
    const WasmFunctionIDs dynamicFunctionIDs,
    const WasmCWriteModuleOptions options
) {
    /* Create file */
    FILE* file = NULL;

    file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(
            stderr,
            "w2c2: failed to open output file %s: %s\n",
            filename,
            strerror(errno)
        );
        return false;
    }

    wasmCWriteIncludes(file, headerName);

    switch (options.dataSegmentMode) {
        case wasmDataSegmentModeGNULD:
        case wasmDataSegmentModeSectcreate1:
        case wasmDataSegmentModeSectcreate2: {
            wasmCWriteDataSegmentsFromSection(
                file,
                module,
                options.dataSegmentMode
            );
            break;
        }
        case wasmDataSegmentModeArrays: {
            /* NO-OP */
            break;
        }
        default: {
            fprintf(stderr, "w2c2: unsupported data segment mode: %d\n", options.dataSegmentMode);
            abort();
        }
    }

    wasmCWriteDataSegments(
        file, module,
        options.dataSegmentMode,
        options.pretty
    );

    /* Write implementations */

    if (options.functionsPerFile >= module->functions.count
        && dynamicFunctionIDs.length == 0)
    {
        WasmDebugLines debugLines = module->debugLines;

        MUST (wasmCWriteFunctionImplementations(
            file,
            module,
            moduleName,
            &debugLines,
            0,
            (U32)staticFunctionIDs.length,
            staticFunctionIDs,
            options.pretty,
            options.debug,
            options.multipleModules
        ))
    } else {

        MUST (wasmCWriteModuleImplementationFiles(
            module,
            moduleName,
            headerName,
            staticFunctionIDs,
            's',
            options
        ))

        MUST (wasmCWriteModuleImplementationFiles(
            module,
            moduleName,
            headerName,
            dynamicFunctionIDs,
            'd',
            options
        ))
    }

    /* Write initializations code */

    MUST (wasmCWriteInits(
        module,
        moduleName,
        file,
        options.dataSegmentMode,
        options.pretty,
        options.multipleModules
    ))

    /* Close file */

    if (fclose(file) != 0) {
        fprintf(
            stderr,
            "w2c2: failed to close output file: %s: %s\n",
            filename,
            strerror(errno)
        );
        return false;
    }

    return true;
}

bool
WARN_UNUSED_RESULT
wasmCWriteModule(
    const WasmModule* module,
    const char* moduleName,
    const WasmCWriteModuleOptions options,
    const WasmFunctionIDs staticFunctionIDs,
    const WasmFunctionIDs dynamicFunctionIDs
) {
    char outputName[PATH_MAX];
    char headerName[PATH_MAX];

    const char* outputPath = options.outputPath;

    strcpy(outputName, outputPath);
    strcpy(outputName, basename(outputName));

    strcpy(headerName, outputName);

    {
        char* headerExt = strrchr(headerName, '.');
        if (headerExt == NULL) {
            headerExt = headerName + strlen(headerName);
        }
        strcpy(headerExt, ".h");
    }

    MUST (wasmCWriteModuleHeader(
        module,
        moduleName,
        headerName,
        options.pretty,
        options.debug,
        options.multipleModules
    ))

    MUST (wasmCWriteModuleImplementation(
        module,
        moduleName,
        outputName,
        headerName,
        staticFunctionIDs,
        dynamicFunctionIDs,
        options
    ))

    return true;
}
