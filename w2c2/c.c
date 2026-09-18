#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#if HAS_PTHREAD
  #include <pthread.h>
#endif /* HAS_PTHREAD */
#include <limits.h>

#include "output_internal.h"
#include "w2c2_base.h"
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
bool
wasmCWriteLocalName(
    WasmOutput* file,
    const U32 localIndex
) {
    wasmOutputChar(file, localNamePrefix);
    wasmOutputU32(file, localIndex);
    return !file->failed;
}

static
W2C2_INLINE
void
wasmCWriteEscaped(
    WasmOutput* file,
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
                wasmOutputString(file, "__");
            } else {
                wasmOutputChar(file, c);
            }
        } else if (c != escapeChar && isalnum(c)) {
            wasmOutputChar(file, c);
        } else {
            wasmOutputChar(file, escapeChar);
            wasmOutputHex(file, (unsigned int)c, wasmOutputHexUpperPadded);
        }
    }
}

static const char* wasmImportNameSeparator = "__";

static
W2C2_INLINE
void
wasmCWriteGlobalNonImportName(
    WasmOutput* file,
    const U32 globalIndex
) {
    wasmOutputChar(file, globalNamePrefix);
    wasmOutputU32(file, globalIndex);
}

static
W2C2_INLINE
void
wasmCWriteImportName(
    WasmOutput* file,
    const char* module,
    const char* name
) {
    wasmCWriteEscaped(file, module);
    wasmOutputString(file, wasmImportNameSeparator);
    wasmCWriteEscaped(file, name);
}


static
W2C2_INLINE
bool
wasmCWriteGlobalUse(
    WasmOutput* file,
    const WasmModule* module,
    const U32 globalIndex,
    const bool reference
) {
    if (globalIndex < module->globalImports.length) {
        const WasmGlobalImport import = module->globalImports.imports[globalIndex];
        if (!reference) {
            wasmOutputString(file, "(*");
        }
        wasmOutputString(file, "i->");
        wasmCWriteImportName(file, import.module, import.name);
        if (!reference) {
            wasmOutputChar(file, ')');
        }
    } else {
        if (reference) {
            wasmOutputChar(file, '&');
        }
        wasmOutputString(file, "i->");
        wasmCWriteGlobalNonImportName(file, globalIndex);
    }
    return !file->failed;
}

static
W2C2_INLINE
void
wasmCWriteMemoryNonImportName(
    WasmOutput* file,
    const U32 memoryIndex
) {
    wasmOutputChar(file, memoryNamePrefix);
    wasmOutputU32(file, memoryIndex);
}

static
W2C2_INLINE
bool
wasmCWriteMemoryUse(
    WasmOutput* file,
    const WasmModule* module,
    const U32 memoryIndex,
    const char *variableName,
    const bool reference
) {
    if (variableName == NULL) {
        variableName = "i";
    }

    if (!reference) {
        wasmOutputString(file, "(*");
    }
    wasmOutputString(file, variableName);
    wasmOutputString(file, "->");
    if (memoryIndex < module->memoryImports.length) {
        const WasmMemoryImport import = module->memoryImports.imports[memoryIndex];
        wasmCWriteImportName(file, import.module, import.name);
    } else {
        wasmCWriteMemoryNonImportName(file, memoryIndex);
    }
    if (!reference) {
        wasmOutputChar(file, ')');
    }
    return !file->failed;
}

static
void
wasmCWriteTableNonImportName(
    WasmOutput* file,
    const U32 tableIndex
) {
    wasmOutputChar(file, tableNamePrefix);
    wasmOutputU32(file, tableIndex);
}

static
W2C2_INLINE
bool
wasmCWriteTableUse(
    WasmOutput* file,
    const WasmModule* module,
    const U32 tableIndex,
    const bool reference
) {
    if (tableIndex < module->tableImports.length) {
        const WasmTableImport import = module->tableImports.imports[tableIndex];
        if (!reference) {
            wasmOutputString(file, "(*");
        }
        wasmOutputString(file, "i->");
        wasmCWriteImportName(file, import.module, import.name);
        if (!reference) {
            wasmOutputChar(file, ')');
        }
    } else {
        if (reference) {
            wasmOutputChar(file, '&');
        }
        wasmOutputString(file, "i->");
        wasmCWriteTableNonImportName(file, tableIndex);
    }
    return !file->failed;
}

/* TODO: add support for multiple modules */
static
W2C2_INLINE
bool
wasmCWriteDataSegmentName(
    WasmOutput* file,
    const U32 dataSegmentIndex
) {
    wasmOutputChar(file, dataSegmentNamePrefix);
    wasmOutputU32(file, dataSegmentIndex);
    return !file->failed;
}

static
W2C2_INLINE
void
wasmCWriteFunctionNonImportName(
    WasmOutput* file,
    const U32 functionIndex
) {
    wasmOutputString(file, "f");
    wasmOutputU32(file, functionIndex);
}

static
W2C2_INLINE
bool
wasmCWriteFunctionUse(
    WasmOutput* file,
    const WasmModule* module,
    const char* moduleName,
    const U32 functionIndex,
    const bool reference,
    const bool prefix
) {
    if (reference) {
        wasmOutputChar(file, '&');
    }
    if (prefix) {
        wasmOutputString(file, moduleName);
        wasmOutputChar(file, '_');
    }
    if (functionIndex < module->functionImports.length) {
        const WasmFunctionImport import = module->functionImports.imports[functionIndex];
        wasmCWriteImportName(file, import.module, import.name);
    } else {
        wasmCWriteFunctionNonImportName(file, functionIndex);
    }
    return !file->failed;
}

static
W2C2_INLINE
bool
wasmCWriteStackName(
    WasmOutput* file,
    const U32 stackIndex,
    const WasmValueType valueType
) {
    wasmOutputChar(file, stackNamePrefix);
    wasmOutputChar(file, valueTypeStackNames[valueType]);
    wasmOutputU32(file, stackIndex);
    return !file->failed;
}

static
W2C2_INLINE
bool
WARN_UNUSED_RESULT
wasmCWriteLabelName(
    WasmOutput* output,
    const U32 labelIndex
) {
    wasmOutputChar(output, labelNamePrefix);
    wasmOutputU32(output, labelIndex);
    return !output->failed;
}

static
W2C2_INLINE
bool
WARN_UNUSED_RESULT
wasmCGetReturnType(
    const WasmFunctionType functionType,
    const U32 typeIndex,
    const char** result,
    WasmDiagnosticContext* diagnostics
) {
    switch (functionType.resultCount) {
        case 0:
            *result = "void";
            return true;
        case 1:
            *result = valueTypeNames[functionType.resultTypes[0]];
            return true;
        default:
            /* TODO: add support for multiple result values */
            wasmDiagnosticReportUnsupportedFunctionResults(
                diagnostics, typeIndex, functionType.resultCount
            );
            return false;
    }
}

static
void
wasmCWriteLocalsDeclarations(
    WasmOutput* file,
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
                wasmOutputString(file, indentation);
            }
            wasmOutputString(file, valueTypeNames[localsDeclaration.type]);
            wasmOutputChar(file, ' ');
            wasmCWriteLocalName(file, parameterCount + localIndex);
            wasmOutputString(file, pretty ? " = 0;\n" : "=0;\n");
        }
    }
}

typedef struct WasmCFunctionWriter {
    StringBuilder* builder;
    WasmOutput* output;
    WasmDiagnosticContext* diagnostics;
    WasmTypeStack* typeStack;
    WasmTypeStack* stackDeclarations;
    WasmLabelStack* labelStack;
    const WasmModule* module;
    const char* moduleName;
    WasmFunction function;
    Buffer* code;
    U8* codeStart;
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
        wasmDiagnosticReportInvalidInstruction(
            writer->diagnostics,
            wasmDiagnosticOpcodeUnprefixed,
            (U32)wasmOpcodeCall
        );
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
                MUST (wasmCWriteStackName(writer->output, resultStackIndex, resultType))
                MUST (wasmCWriteAssign(writer))
            }

            MUST (wasmCWriteFunctionUse(
                writer->output,
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
                    MUST (wasmCWriteStackName(writer->output, paramStackIndex, parameterType))
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
wasmCWriteParameters(
    WasmOutput* file,
    const char* moduleName,
    const WasmFunctionType functionType,
    const bool writeParameterNames,
    const bool voidPointerInstanceType,
    const bool pretty
) {
    wasmOutputChar(file, '(');
    if (voidPointerInstanceType) {
        wasmOutputString(file, "void*");
    } else {
        wasmOutputString(file, moduleName);
        wasmOutputString(file, "Instance*");
    }

    if (writeParameterNames) {
        if (pretty) {
            wasmOutputString(file, " i");
        } else {
            wasmOutputChar(file, 'i');
        }
    }
    {
        U32 parameterIndex = 0;
        for (; parameterIndex < functionType.parameterCount; parameterIndex++) {
            const WasmValueType parameterType = functionType.parameterTypes[parameterIndex];
            const char* parameterTypeName = valueTypeNames[parameterType];
            if (pretty) {
                wasmOutputString(file, ", ");
            } else {
                wasmOutputChar(file, ',');
            }
            wasmOutputString(file, parameterTypeName);
            if (writeParameterNames) {
                wasmOutputChar(file, ' ');
                wasmCWriteLocalName(file, parameterIndex);
            }
        }
    }
    wasmOutputChar(file, ')');
    return !file->failed;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteCallIndirectExpr(
    const WasmCFunctionWriter* writer
) {
    WasmCallIndirectInstruction instruction;
    if (!wasmCallIndirectInstructionRead(writer->code, &instruction)) {
        wasmDiagnosticReportInvalidInstruction(
            writer->diagnostics,
            wasmDiagnosticOpcodeUnprefixed,
            (U32)wasmOpcodeCallIndirect
        );
        return false;
    }

    if (!writer->ignore) {
        const WasmFunctionType functionType = writer->module->functionTypes.functionTypes[instruction.functionTypeIndex];
        const char* returnType = NULL;

        const U32 parameterCount = functionType.parameterCount;
        const U32 resultCount = functionType.resultCount;

        MUST (wasmCGetReturnType(functionType, instruction.functionTypeIndex, &returnType, writer->diagnostics))

        MUST (wasmCWriteIndent(writer))

        if (resultCount > 0) {
            /* TODO: add support for multiple result values */
            const WasmValueType resultType = functionType.resultTypes[0];

            U32 resultStackIndex = assertSizeU32(writer->typeStack->length - 1);
            if (parameterCount > 0) {
                resultStackIndex -= parameterCount;
            }

            MUST (wasmTypeStackSet(writer->stackDeclarations, resultStackIndex, resultType))
            MUST (wasmCWriteStackName(writer->output, resultStackIndex, resultType))
            MUST (wasmCWriteAssign(writer))
        }

        MUST (wasmCWrite(writer, "TF("))
        MUST (wasmCWriteTableUse(writer->output, writer->module, instruction.tableIndex, false))
        MUST (wasmCWriteComma(writer))

        {
            const U32 stackIndex0 = wasmTypeStackGetTopIndex(writer->typeStack, 0);
            MUST (wasmCWriteStackName(
                writer->output,
                stackIndex0,
                writer->typeStack->valueTypes[stackIndex0]
            ))
        }

        MUST (wasmCWriteComma(writer))
        MUST (wasmCWrite(writer, returnType))
        MUST (wasmCWrite(writer, " (*)"))

        MUST (wasmCWriteParameters(
            writer->output, writer->moduleName, functionType, false, false, writer->pretty
        ))

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
                MUST (wasmCWriteStackName(writer->output, paramStackIndex, parameterType))
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
        wasmDiagnosticReportInvalidInstruction(
            writer->diagnostics,
            wasmDiagnosticOpcodeUnprefixed,
            (U32)wasmOpcodeLocalGet
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
            wasmDiagnosticReportInvalidLocalIndex(
                writer->diagnostics,
                wasmDiagnosticOpcodeUnprefixed,
                (U32)wasmOpcodeLocalGet,
                instruction.localIndex
            );
            return false;
        }
        MUST (wasmTypeStackAppend(writer->typeStack, localType))
        {
            const U32 stackIndex0 = wasmTypeStackGetTopIndex(writer->typeStack, 0);
            MUST (wasmTypeStackSet(writer->stackDeclarations, stackIndex0, localType))

            MUST (wasmCWriteIndent(writer))
            MUST (wasmCWriteStackName(writer->output, stackIndex0, localType))
            MUST (wasmCWriteAssign(writer))
            MUST (wasmCWriteLocalName(writer->output, instruction.localIndex))
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
        wasmDiagnosticReportInvalidInstruction(
            writer->diagnostics,
            wasmDiagnosticOpcodeUnprefixed,
            (U32)opcode
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
            wasmDiagnosticReportInvalidLocalIndex(
                writer->diagnostics,
                wasmDiagnosticOpcodeUnprefixed,
                (U32)opcode,
                instruction.localIndex
            );
            return false;
        }
        {
            const U32 stackIndex0 = wasmTypeStackGetTopIndex(writer->typeStack, 0);
            MUST (wasmTypeStackSet(writer->stackDeclarations, stackIndex0, localType))

            MUST (wasmCWriteIndent(writer))
            MUST (wasmCWriteLocalName(writer->output, instruction.localIndex))
            MUST (wasmCWriteAssign(writer))
            MUST (wasmCWriteStackName(writer->output, stackIndex0, localType))
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
        wasmDiagnosticReportInvalidInstruction(
            writer->diagnostics,
            wasmDiagnosticOpcodeUnprefixed,
            (U32)opcode
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
            wasmDiagnosticReportInvalidGlobalIndex(
                writer->diagnostics,
                wasmDiagnosticOpcodeUnprefixed,
                (U32)opcode,
                instruction.globalIndex
            );
            return false;
        }
        MUST (wasmTypeStackAppend(writer->typeStack, globalType))
        {
            const U32 stackIndex0 = wasmTypeStackGetTopIndex(writer->typeStack, 0);
            MUST (wasmTypeStackSet(writer->stackDeclarations, stackIndex0, globalType))

            MUST (wasmCWriteIndent(writer))
            MUST (wasmCWriteStackName(writer->output, stackIndex0, globalType))
            MUST (wasmCWriteAssign(writer))
            MUST (wasmCWriteGlobalUse(writer->output, writer->module, instruction.globalIndex, false))
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
        wasmDiagnosticReportInvalidInstruction(
            writer->diagnostics,
            wasmDiagnosticOpcodeUnprefixed,
            (U32)opcode
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
            wasmDiagnosticReportInvalidGlobalIndex(
                writer->diagnostics,
                wasmDiagnosticOpcodeUnprefixed,
                (U32)opcode,
                instruction.globalIndex
            );
            return false;
        }
        {
            const U32 stackIndex0 = wasmTypeStackGetTopIndex(writer->typeStack, 0);
            MUST (wasmTypeStackSet(writer->stackDeclarations, stackIndex0, globalType))

            MUST (wasmCWriteIndent(writer))
            MUST (wasmCWriteGlobalUse(writer->output, writer->module, instruction.globalIndex, false))
            MUST (wasmCWriteAssign(writer))
            MUST (wasmCWriteStackName(writer->output, stackIndex0, globalType))
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
    const WasmValue value,
    WasmDiagnosticContext* diagnostics
) {
    switch (valueType) {
        case wasmValueTypeI32: {
            MUST (stringBuilderAppendI32(builder, value.i32))
            MUST (stringBuilderAppendChar(builder, 'U'))
            break;
        }
        case wasmValueTypeI64: {
            MUST (stringBuilderAppend(builder, "W2C2_LL("))
            MUST (stringBuilderAppendI64(builder, value.i64))
            MUST (stringBuilderAppend(builder, "U)"))
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
            if ((bits & W2C2_LL(0x7ff0000000000000U)) == W2C2_LL(0x7ff0000000000000U)) {
                const bool isNegative = (bits & W2C2_LL(0x8000000000000000U)) != 0;
                const U64 significand = bits & W2C2_LL(0x7fffffU);
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
            } else if (bits == W2C2_LL(0x8000000000000000U)) {
                MUST (stringBuilderAppend(builder, "-0.f"))
            } else {
                MUST (stringBuilderAppendF64(builder, value.f64))
            }
            break;
        }
        default:
            wasmDiagnosticReportUnsupportedValueType(diagnostics, valueType);
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
        wasmDiagnosticReportInvalidInstruction(
            writer->diagnostics,
            wasmDiagnosticOpcodeUnprefixed,
            (U32)opcode
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
            MUST (wasmCWriteStackName(writer->output, stackIndex0, resultType))
            MUST (wasmCWriteAssign(writer))
            MUST (wasmCWriteLiteral(writer->builder, resultType, instruction.value, writer->diagnostics))
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
    MUST (wasmCWriteStackName(writer->output, stackIndex0, resultType))
    MUST (wasmCWriteAssign(writer))
    MUST (wasmCWrite(writer, functionName))
    MUST (wasmCWriteChar(writer, '('))
    MUST (wasmCWriteMemoryUse(writer->output, writer->module, 0, NULL, true))
    MUST (wasmCWriteComma(writer))
    MUST (wasmCWriteStackName(
        writer->output,
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
        wasmDiagnosticReportInvalidInstruction(
            writer->diagnostics,
            wasmDiagnosticOpcodeUnprefixed,
            (U32)opcode
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
                wasmDiagnosticReportUnsupportedOpcode(
                    writer->diagnostics,
                    wasmDiagnosticOpcodeUnprefixed,
                    (U32)opcode
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
    MUST (wasmCWriteMemoryUse(writer->output, writer->module, 0, NULL, true))
    MUST (wasmCWriteComma(writer))
    MUST (wasmCWriteStackName(
        writer->output,
        stackIndex1,
        writer->typeStack->valueTypes[stackIndex1]
    ))
    if (instruction.offset != 0) {
        MUST (wasmCWritePlus(writer))
        MUST (stringBuilderAppendU32(writer->builder, instruction.offset))
        MUST (wasmCWriteChar(writer, 'U'))
    }
    MUST (wasmCWriteComma(writer))
    MUST (wasmCWriteStackName(
        writer->output,
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
        wasmDiagnosticReportInvalidInstruction(
            writer->diagnostics,
            wasmDiagnosticOpcodeUnprefixed,
            (U32)opcode
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
                wasmDiagnosticReportUnsupportedOpcode(
                    writer->diagnostics,
                    wasmDiagnosticOpcodeUnprefixed,
                    (U32)opcode
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
        wasmDiagnosticReportInvalidInstruction(
            writer->diagnostics,
            wasmDiagnosticOpcodeUnprefixed,
            (U32)wasmOpcodeMemorySize
        );
        return false;
    }

    {
        static const U32 expectedMemoryIndex = 0;
        if (instruction.memoryIndex != expectedMemoryIndex) {
            wasmDiagnosticReportUnexpectedMemoryIndex(
                writer->diagnostics,
                wasmDiagnosticOpcodeUnprefixed,
                (U32)wasmOpcodeMemorySize,
                1,
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
            MUST (wasmCWriteStackName(
                writer->output,
                stackIndex0,
                resultType
            ))
            MUST (wasmCWriteAssign(writer))
            MUST (wasmCWriteMemoryUse(
                writer->output,
                writer->module,
                instruction.memoryIndex,
                NULL,
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
        wasmDiagnosticReportInvalidInstruction(
            writer->diagnostics,
            wasmDiagnosticOpcodeUnprefixed,
            (U32)wasmOpcodeMemoryGrow
        );
        return false;
    }

    {
        static const U32 expectedMemoryIndex = 0;
        if (instruction.memoryIndex != expectedMemoryIndex) {
            wasmDiagnosticReportUnexpectedMemoryIndex(
                writer->diagnostics,
                wasmDiagnosticOpcodeUnprefixed,
                (U32)wasmOpcodeMemoryGrow,
                1,
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
            MUST (wasmCWriteStackName(writer->output, stackIndex0, resultType))
            MUST (wasmCWriteAssign(writer))
            MUST (wasmCWrite(writer, "wasmMemoryGrow("))
            MUST (wasmCWriteMemoryUse(
                writer->output,
                writer->module,
                instruction.memoryIndex,
                NULL,
                true
            ))
            MUST (wasmCWriteComma(writer))
            MUST (wasmCWriteStackName(
                writer->output,
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
        wasmDiagnosticReportInvalidInstruction(
            writer->diagnostics,
            wasmDiagnosticOpcodeMisc,
            (U32)wasmMiscOpcodeMemoryInit
        );
        return false;
    }

    if (!writer->ignore) {
        const U32 stackIndex0 = wasmTypeStackGetTopIndex(writer->typeStack, 0);
        const U32 stackIndex1 = wasmTypeStackGetTopIndex(writer->typeStack, 1);
        const U32 stackIndex2 = wasmTypeStackGetTopIndex(writer->typeStack, 2);

        MUST (wasmCWriteIndent(writer))
        MUST (wasmCWrite(writer, "LOAD_DATA("))
        MUST (wasmCWriteMemoryUse(
            writer->output,
            writer->module,
            instruction.memoryIndex,
            NULL,
            false
        ))
        MUST (wasmCWriteComma(writer))
        MUST (wasmCWriteStackName(
            writer->output,
            stackIndex2,
            writer->typeStack->valueTypes[stackIndex2]
        ))
        MUST (wasmCWriteComma(writer))
        /* TODO: add support for multiple modules */
        MUST (wasmCWriteDataSegmentName(writer->output, instruction.dataSegmentIndex))
        MUST (wasmCWriteChar(writer, '+'))
        MUST (wasmCWriteStackName(
            writer->output,
            stackIndex1,
            writer->typeStack->valueTypes[stackIndex1]
        ))
        MUST (wasmCWriteComma(writer))
        MUST (wasmCWriteStackName(
            writer->output,
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
        wasmDiagnosticReportInvalidInstruction(
            writer->diagnostics,
            wasmDiagnosticOpcodeMisc,
            (U32)wasmMiscOpcodeMemoryCopy
        );
        return false;
    }

    /* Validate */
    {
        static const U32 expectedMemoryIndex = 0;
        if (instruction.memoryIndex1 != expectedMemoryIndex) {
            wasmDiagnosticReportUnexpectedMemoryIndex(
                writer->diagnostics,
                wasmDiagnosticOpcodeMisc,
                (U32)wasmMiscOpcodeMemoryCopy,
                1,
                expectedMemoryIndex,
                instruction.memoryIndex1
            );
            return false;
        }

        if (instruction.memoryIndex2 != expectedMemoryIndex) {
            wasmDiagnosticReportUnexpectedMemoryIndex(
                writer->diagnostics,
                wasmDiagnosticOpcodeMisc,
                (U32)wasmMiscOpcodeMemoryCopy,
                2,
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
        MUST (wasmCWriteMemoryUse(
            writer->output,
            writer->module,
            instruction.memoryIndex1,
            NULL,
            true
        ))
        MUST (wasmCWriteComma(writer))
        MUST (wasmCWriteMemoryUse(
            writer->output,
            writer->module,
            instruction.memoryIndex2,
            NULL,
            true
        ))
        MUST (wasmCWriteComma(writer))
        MUST (wasmCWriteStackName(
            writer->output,
            stackIndex2,
            writer->typeStack->valueTypes[stackIndex2]
        ))
        MUST (wasmCWriteComma(writer))
        MUST (wasmCWriteStackName(
            writer->output,
            stackIndex1,
            writer->typeStack->valueTypes[stackIndex1]
        ))
        MUST (wasmCWriteComma(writer))
        MUST (wasmCWriteStackName(
            writer->output,
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
    UNUSED_PARAMETER(miscOpcode);

    if (!wasmMemoryInstructionRead(writer->code, &instruction)) {
        wasmDiagnosticReportInvalidInstruction(
            writer->diagnostics,
            wasmDiagnosticOpcodeMisc,
            (U32)wasmMiscOpcodeMemoryFill
        );
        return false;
    }

    {
        static const U32 expectedMemoryIndex = 0;
        if (instruction.memoryIndex != expectedMemoryIndex) {
            wasmDiagnosticReportUnexpectedMemoryIndex(
                writer->diagnostics,
                wasmDiagnosticOpcodeMisc,
                (U32)wasmMiscOpcodeMemoryFill,
                1,
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
        MUST (wasmCWriteMemoryUse(
            writer->output,
            writer->module,
            instruction.memoryIndex,
            NULL,
            true
        ))
        MUST (wasmCWriteComma(writer))
        MUST (wasmCWriteStackName(
            writer->output,
            stackIndex2,
            writer->typeStack->valueTypes[stackIndex2]
        ))
        MUST (wasmCWriteComma(writer))
        MUST (wasmCWriteStackName(
            writer->output,
            stackIndex1,
            writer->typeStack->valueTypes[stackIndex1]
        ))
        MUST (wasmCWriteComma(writer))
        MUST (wasmCWriteStackName(
            writer->output,
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
    MUST (wasmCWriteStackName(writer->output, stackIndex0, resultType))
    MUST (wasmCWriteAssign(writer))
    MUST (wasmCWrite(writer, operator))
    MUST (wasmCWriteChar(writer, '('))
    MUST (wasmCWriteStackName(
        writer->output,
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
    MUST (wasmCWriteStackName(writer->output, stackIndex1, resultType))

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
        MUST (wasmCWriteStackName(
            writer->output,
            stackIndex1,
            writer->typeStack->valueTypes[stackIndex1]
        ))
        MUST (wasmCWriteChar(writer, ' '))
        MUST (wasmCWrite(writer, operator))
        MUST (wasmCWriteChar(writer, ' '))
    }
    MUST (wasmCWriteStackName(
        writer->output,
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
    MUST (wasmCWriteStackName(writer->output, stackIndex1, resultType))
    if (writer->pretty) {
        MUST (wasmCWrite(writer, " = ("))
    } else {
        MUST (wasmCWrite(writer, "=("))
    }
    MUST (wasmCWrite(writer, valueTypeNames[parameter1Type]))
    MUST (wasmCWrite(writer, ")(("))
    MUST (wasmCWrite(writer, signedTypeNames[parameter1Type]))
    MUST (wasmCWriteChar(writer, ')'))
    MUST (wasmCWriteStackName(
        writer->output,
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
    MUST (wasmCWriteStackName(
        writer->output,
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
    MUST (wasmCWriteStackName(writer->output, stackIndex1, resultType))
    MUST (wasmCWriteAssign(writer))
    MUST (wasmCWrite(writer, operator))
    MUST (wasmCWriteChar(writer, '('))
    MUST (wasmCWriteStackName(
        writer->output,
        stackIndex1,
        writer->typeStack->valueTypes[stackIndex1]
    ))
    MUST (wasmCWriteComma(writer))
    MUST (wasmCWriteStackName(
        writer->output,
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
    MUST (wasmCWriteStackName(
        writer->output,
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
    MUST (wasmCWriteStackName(
        writer->output,
        stackIndex1,
        writer->typeStack->valueTypes[stackIndex1]
    ))
    if (writer->pretty) {
        MUST (wasmCWrite(writer, " >> ("))
    } else {
        MUST (wasmCWrite(writer, ">>("))
    }
    MUST (wasmCWriteStackName(
        writer->output,
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
    MUST (wasmCWriteStackName(
        writer->output,
        stackIndex1,
        writer->typeStack->valueTypes[stackIndex1]
    ))
    if (writer->pretty) {
        MUST (wasmCWrite(writer, " >>= ("))
    } else {
        MUST (wasmCWrite(writer, ">>=("))
    }
    MUST (wasmCWriteStackName(
        writer->output,
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
    MUST (wasmCWriteStackName(
        writer->output,
        stackIndex1,
        writer->typeStack->valueTypes[stackIndex1]
    ))
    if (writer->pretty) {
        MUST (wasmCWrite(writer, " <<= ("))
    } else {
        MUST (wasmCWrite(writer, "<<=("))
    }
    MUST (wasmCWriteStackName(
        writer->output,
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
    MUST (wasmCWriteLabelName(writer->output, labelIndex))
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
        wasmDiagnosticReportInvalidBlockType(writer->diagnostics, (U32)*opcode);
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
            MUST (wasmCWriteStackName(
                writer->output,
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
        wasmDiagnosticReportInvalidBlockType(writer->diagnostics, (U32)*opcode);
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
        wasmDiagnosticReportInvalidBlockType(writer->diagnostics, (U32)*opcode);
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
        MUST(wasmCWrite(writer, "W2C2_LOOP_START\n"))

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

            MUST (wasmCWriteStackName(writer->output, destinationStackIndex, resultType))
            MUST (wasmCWriteAssign(writer))
            MUST (wasmCWriteStackName(
                writer->output,
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
    MUST (wasmCWriteLabelName(writer->output, label.index))
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
    MUST (wasmCWriteStackName(
        writer->output,
        stackIndex2,
        resultType
    ))
    MUST (wasmCWriteAssign(writer))
    MUST (wasmCWriteStackName(
        writer->output,
        stackIndex0,
        writer->typeStack->valueTypes[stackIndex0]
    ))
    if (writer->pretty) {
        MUST (wasmCWrite(writer, " ? "))
    } else {
        MUST (wasmCWriteChar(writer, '?'))
    }
    MUST (wasmCWriteStackName(
        writer->output,
        stackIndex2,
        writer->typeStack->valueTypes[stackIndex2]
    ))
    if (writer->pretty) {
        MUST (wasmCWrite(writer, " : "))
    } else {
        MUST (wasmCWriteChar(writer, ':'))
    }
    MUST (wasmCWriteStackName(
        writer->output,
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
        wasmDiagnosticReportInvalidInstruction(
            writer->diagnostics,
            wasmDiagnosticOpcodeUnprefixed,
            (U32)wasmOpcodeBr
        );
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
        wasmDiagnosticReportInvalidInstruction(
            writer->diagnostics,
            wasmDiagnosticOpcodeUnprefixed,
            (U32)wasmOpcodeBrIf
        );
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
        MUST (wasmCWriteStackName(
            writer->output,
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
    bool result = false;
    if (!wasmBranchTableInstructionRead(writer->code, &instruction)) {
        wasmDiagnosticReportInvalidInstruction(
            writer->diagnostics,
            wasmDiagnosticOpcodeUnprefixed,
            (U32)wasmOpcodeBrTable
        );
        return false;
    }

    if (!writer->ignore) {
        const U32 stackIndex0 = wasmTypeStackGetTopIndex(writer->typeStack, 0);

        MUST_OR_GOTO (cleanup, wasmCWriteIndent(writer))
        if (writer->pretty) {
            MUST_OR_GOTO (cleanup, wasmCWrite(writer, "switch ("))
        } else {
            MUST_OR_GOTO (cleanup, wasmCWrite(writer, "switch("))
        }
        MUST_OR_GOTO (cleanup, wasmCWriteStackName(
            writer->output,
            stackIndex0,
            writer->typeStack->valueTypes[stackIndex0]
        ))
        if (writer->pretty) {
            MUST_OR_GOTO (cleanup, wasmCWrite(writer, ") {\n"))
        } else {
            MUST_OR_GOTO (cleanup, wasmCWrite(writer, "){\n"))
        }

        wasmTypeStackDrop(writer->typeStack, 1);

        {
            U32 index = 0;
            for (; index < instruction.labelIndexCount; index++) {
                MUST_OR_GOTO (cleanup, wasmCWriteIndent(writer))
                MUST_OR_GOTO (cleanup, wasmCWrite(writer, "case "))
                MUST_OR_GOTO (cleanup, stringBuilderAppendU32(writer->builder, index))
                MUST_OR_GOTO (cleanup, wasmCWrite(writer, ":\n"))
                writer->indent++;
                {
                    const U32 labelIndex = wasmLabelStackGetTopIndex(
                        writer->labelStack,
                        instruction.labelIndices[index]
                    );
                    MUST_OR_GOTO (cleanup, wasmCWriteGoto(writer, labelIndex))
                }
                writer->indent--;
            }
        }

        MUST_OR_GOTO (cleanup, wasmCWriteIndent(writer))
        MUST_OR_GOTO (cleanup, wasmCWrite(writer, "default:\n"))
        writer->indent++;
        {
            const U32 labelIndex = wasmLabelStackGetTopIndex(
                writer->labelStack,
                instruction.defaultLabelIndex
            );
            MUST_OR_GOTO (cleanup, wasmCWriteGoto(writer, labelIndex))
        }
        writer->indent--;

        MUST_OR_GOTO (cleanup, wasmCWriteIndent(writer))
        MUST_OR_GOTO (cleanup, wasmCWrite(writer, "}\n"))
    }

    result = true;

cleanup:
    wasmBranchTableInstructionFree(instruction);
    return result;
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
WasmDebugLines
wasmCDebugLinesAtAddress(
    WasmDebugLines debugLines,
    const size_t absoluteAddress
) {
    while (debugLines.length > 1
           && absoluteAddress >= debugLines.debugLines[1].address) {

        debugLines.length--;
        debugLines.debugLines++;
    }

    return debugLines;
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
        wasmDiagnosticReportInvalidInstruction(
            writer->diagnostics,
            wasmDiagnosticOpcodeThreads,
            (U32)opcode
        );
        return false;
    }

    if (!writer->ignore) {
        const U32 stackIndex0 = wasmTypeStackGetTopIndex(writer->typeStack, 0);
        const U32 stackIndex1 = wasmTypeStackGetTopIndex(writer->typeStack, 1);

        static const WasmValueType resultType = wasmValueTypeI32;

        MUST (wasmTypeStackSet(writer->stackDeclarations, stackIndex1, resultType))

        MUST (wasmCWriteIndent(writer))
        MUST (wasmCWriteStackName(writer->output, stackIndex1, resultType))
        MUST (wasmCWriteAssign(writer))
        MUST (wasmCWrite(writer, "wasmMemoryAtomicNotify("))
        MUST (wasmCWriteMemoryUse(
                writer->output,
                writer->module,
                0,
                NULL,
                true
        ))
        MUST (wasmCWriteComma(writer))
        MUST (wasmCWriteStackName(
                writer->output,
                stackIndex1,
                writer->typeStack->valueTypes[stackIndex1]
        ))
        MUST (wasmCWriteComma(writer))
        MUST (wasmCWriteStackName(
                writer->output,
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
        MUST (wasmCWriteStackName(writer->output, stackIndex2, resultType))
        MUST (wasmCWriteAssign(writer))
        MUST (wasmCWrite(writer, "wasmMemoryAtomicWait("))
        MUST (wasmCWriteMemoryUse(
                writer->output,
                writer->module,
                0,
                NULL,
                true
        ))
        MUST (wasmCWriteComma(writer))
        MUST (wasmCWriteStackName(
                writer->output,
                stackIndex2,
                writer->typeStack->valueTypes[stackIndex2]
        ))
        MUST (wasmCWriteComma(writer))
        MUST (wasmCWriteStackName(
                writer->output,
                stackIndex1,
                writer->typeStack->valueTypes[stackIndex1]
        ))
        MUST (wasmCWriteComma(writer))
        MUST (wasmCWriteStackName(
                writer->output,
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
        wasmDiagnosticReportInvalidInstruction(
            writer->diagnostics,
            wasmDiagnosticOpcodeThreads,
            (U32)opcode
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
        wasmDiagnosticReportInvalidInstruction(
            writer->diagnostics,
            wasmDiagnosticOpcodeThreads,
            (U32)opcode
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
        wasmDiagnosticReportInvalidInstruction(
            writer->diagnostics,
            wasmDiagnosticOpcodeThreads,
            (U32)opcode
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
        wasmDiagnosticReportInvalidInstruction(
            writer->diagnostics,
            wasmDiagnosticOpcodeThreads,
            (U32)opcode
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
                wasmDiagnosticReportUnsupportedOpcode(
                    writer->diagnostics,
                    wasmDiagnosticOpcodeThreads,
                    (U32)opcode
                );
                return false;
            }
        }

        if (instruction.align != expectedAlign) {
            wasmDiagnosticReportInvalidAlignment(
                writer->diagnostics,
                wasmDiagnosticOpcodeThreads,
                (U32)opcode,
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
        wasmDiagnosticReportInvalidInstruction(
            writer->diagnostics,
            wasmDiagnosticOpcodeThreads,
            (U32)opcode
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
                wasmDiagnosticReportUnsupportedOpcode(
                    writer->diagnostics,
                    wasmDiagnosticOpcodeThreads,
                    (U32)opcode
                );
                return false;
            }
        }

        if (instruction.align != expectedAlign) {
            wasmDiagnosticReportInvalidAlignment(
                writer->diagnostics,
                wasmDiagnosticOpcodeThreads,
                (U32)opcode,
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
        wasmDiagnosticReportInvalidInstruction(
            writer->diagnostics,
            wasmDiagnosticOpcodeThreads,
            (U32)opcode
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
                wasmDiagnosticReportUnsupportedOpcode(
                    writer->diagnostics,
                    wasmDiagnosticOpcodeThreads,
                    (U32)opcode
                );
                return false;
            }
        }

        if (instruction.align != expectedAlign) {
            wasmDiagnosticReportInvalidAlignment(
                writer->diagnostics,
                wasmDiagnosticOpcodeThreads,
                (U32)opcode,
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
            MUST (wasmCWriteStackName(writer->output, stackIndex1, resultType))
            MUST (wasmCWriteAssign(writer))
            MUST (wasmCWrite(writer, functionName))
            MUST (wasmCWriteChar(writer, '('))
            MUST (wasmCWriteMemoryUse(writer->output, writer->module, 0, NULL, true))
            MUST (wasmCWriteComma(writer))
            MUST (wasmCWriteStackName(
                    writer->output,
                stackIndex1,
                writer->typeStack->valueTypes[stackIndex1]
            ))
            if (instruction.offset != 0) {
                MUST (wasmCWritePlus(writer))
                MUST (stringBuilderAppendU32(writer->builder, instruction.offset))
                MUST (wasmCWriteChar(writer, 'U'))
            }
            MUST (wasmCWriteComma(writer))
            MUST (wasmCWriteStackName(
                writer->output,
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
        wasmDiagnosticReportInvalidInstruction(
            writer->diagnostics,
            wasmDiagnosticOpcodeThreads,
            (U32)opcode
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
                wasmDiagnosticReportUnsupportedOpcode(
                    writer->diagnostics,
                    wasmDiagnosticOpcodeThreads,
                    (U32)opcode
                );
                return false;
            }
        }

        if (instruction.align != expectedAlign) {
            wasmDiagnosticReportInvalidAlignment(
                writer->diagnostics,
                wasmDiagnosticOpcodeThreads,
                (U32)opcode,
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
            MUST (wasmCWriteStackName(writer->output, stackIndex2, resultType))
            MUST (wasmCWriteAssign(writer))
            MUST (wasmCWrite(writer, functionName))
            MUST (wasmCWriteChar(writer, '('))
            MUST (wasmCWriteMemoryUse(writer->output, writer->module, 0, NULL, true))
            MUST (wasmCWriteComma(writer))
            MUST (wasmCWriteStackName(
                    writer->output,
                    stackIndex2,
                    writer->typeStack->valueTypes[stackIndex2]
            ))
            if (instruction.offset != 0) {
                MUST (wasmCWritePlus(writer))
                MUST (stringBuilderAppendU32(writer->builder, instruction.offset))
                MUST (wasmCWriteChar(writer, 'U'))
            }
            MUST (wasmCWriteComma(writer))
            MUST (wasmCWriteStackName(
                    writer->output,
                    stackIndex1,
                    writer->typeStack->valueTypes[stackIndex1]
            ))
            MUST (wasmCWriteComma(writer))
            MUST (wasmCWriteStackName(
                    writer->output,
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
                    default:
                        wasmDiagnosticReportUnsupportedOpcode(
                            writer->diagnostics,
                            wasmDiagnosticOpcodeThreads,
                            (U32)threadsOpcode
                        );
                        return false;
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

                        /* TODO: implement data.drop semantics. */
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
                        wasmDiagnosticReportUnsupportedOpcode(
                            writer->diagnostics,
                            wasmDiagnosticOpcodeMisc,
                            (U32)miscOpcode
                        );

                        return false;
                    }
                    case wasmMiscOpcodeElemDrop: {
                        /* TODO: refactor into instruction read function */
                        U32 elemIndex = 0;
                        MUST (leb128ReadU32(writer->code, &elemIndex) > 0)

                        /* TODO */
                        wasmDiagnosticReportUnsupportedOpcode(
                            writer->diagnostics,
                            wasmDiagnosticOpcodeMisc,
                            (U32)miscOpcode
                        );

                        return false;
                    }
                    case wasmMiscOpcodeTableCopy: {
                        /* TODO: refactor into instruction read function */
                        U32 tableIndex1 = 0;
                        U32 tableIndex2 = 0;
                        MUST (leb128ReadU32(writer->code, &tableIndex1) > 0)
                        MUST (leb128ReadU32(writer->code, &tableIndex2) > 0)

                        /* TODO */
                        wasmDiagnosticReportUnsupportedOpcode(
                            writer->diagnostics,
                            wasmDiagnosticOpcodeMisc,
                            (U32)miscOpcode
                        );

                        return false;
                    }
                    case wasmMiscOpcodeTableGrow: {
                        /* TODO: refactor into instruction read function */
                        U32 tableIndex = 0;
                        MUST (leb128ReadU32(writer->code, &tableIndex) > 0)

                        /* TODO */
                        wasmDiagnosticReportUnsupportedOpcode(
                            writer->diagnostics,
                            wasmDiagnosticOpcodeMisc,
                            (U32)miscOpcode
                        );

                        return false;
                    }
                    case wasmMiscOpcodeTableSize: {
                        /* TODO: refactor into instruction read function */
                        U32 tableIndex = 0;
                        MUST (leb128ReadU32(writer->code, &tableIndex) > 0)

                        /* TODO */
                        wasmDiagnosticReportUnsupportedOpcode(
                            writer->diagnostics,
                            wasmDiagnosticOpcodeMisc,
                            (U32)miscOpcode
                        );

                        return false;
                    }
                    case wasmMiscOpcodeTableFill: {
                        /* TODO: refactor into instruction read function */
                        U32 tableIndex = 0;
                        MUST (leb128ReadU32(writer->code, &tableIndex) > 0)

                        /* TODO */
                        wasmDiagnosticReportUnsupportedOpcode(
                            writer->diagnostics,
                            wasmDiagnosticOpcodeMisc,
                            (U32)miscOpcode
                        );

                        return false;
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
                                wasmDiagnosticReportUnsupportedOpcode(
                                    writer->diagnostics,
                                    wasmDiagnosticOpcodeMisc,
                                    (U32)miscOpcode
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
                        wasmDiagnosticReportUnsupportedOpcode(
                            writer->diagnostics,
                            wasmDiagnosticOpcodeUnprefixed,
                            (U32)*opcode
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
    WasmOutput* file,
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
                    wasmOutputString(file, indentation);
                }
                wasmOutputString(file, valueTypeNames[testType]);
                wasmOutputChar(file, ' ');
            } else {
                if (pretty) {
                    wasmOutputString(file, ", ");
                } else {
                    wasmOutputChar(file, ',');
                }
            }

            wasmCWriteStackName(file, stackDeclarationIndex, testType);

            written++;
        }

        if (written > 0) {
            wasmOutputString(file, ";\n");
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
            MUST (wasmCWriteStackName(writer->output, stackIndex0, returnType))
            MUST (wasmCWrite(writer, ";\n"))
        }
    }

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteFunctionBody(
    WasmOutput* file,
    WasmTypeStack* typeStack,
    WasmTypeStack* stackDeclarations,
    WasmLabelStack* labelStack,
    const WasmModule* module,
    const char* moduleName,
    const WasmFunction function,
    WasmDebugLines* debugLines,
    const bool pretty,
    const bool debug,
    const bool multipleModules,
    WasmDiagnosticContext* diagnostics
) {
    Buffer code = function.code;
    StringBuilder stringBuilder = emptyStringBuilder;
    WasmOpcode opcode = wasmOpcodeUnreachable;
    WasmLabel label = wasmEmptyLabel;
    WasmValueType* resultType = NULL;
    bool result = false;

    const WasmFunctionType functionType =
        module->functionTypes.functionTypes[function.functionTypeIndex];

    if (functionType.resultCount) {
        resultType = &functionType.resultTypes[0];
        /* TODO: add support for multiple result values */
        if (functionType.resultCount > 1) {
            wasmDiagnosticReportUnsupportedFunctionResults(
                diagnostics,
                function.functionTypeIndex,
                functionType.resultCount
            );
            return false;
        }
    } else {
        resultType = NULL;
    }

    if (!stringBuilderInitialize(&stringBuilder)) {
        wasmDiagnosticReportAllocationFailed(diagnostics);
        goto cleanup;
    }

    {
        WasmOutput output = wasmOutputForStringBuilder(&stringBuilder, diagnostics);
        WasmCFunctionWriter writer;
        writer.output = &output;
        writer.diagnostics = diagnostics;
        writer.builder = &stringBuilder;
        writer.typeStack = typeStack;
        writer.stackDeclarations = stackDeclarations;
        writer.labelStack = labelStack;
        writer.module = module;
        writer.moduleName = moduleName;
        writer.function = function;
        writer.code = &code;
        writer.codeStart = code.data;
        writer.indent = 0;
        writer.ignore = false;
        writer.pretty = pretty;
        writer.debug = debug;
        writer.multipleModules = multipleModules;
        writer.debugLines = debugLines;

        MUST_OR_GOTO (
            cleanup,
            wasmLabelStackPush(writer.labelStack, 0, resultType, &label)
        )
        MUST_OR_GOTO (cleanup, wasmCWriteFunctionCode(&writer, &opcode))
        MUST_OR_GOTO (cleanup, wasmCWriteLabel(&writer, label.index))
        MUST_OR_GOTO (cleanup, wasmCWriteFunctionReturn(&writer, functionType))
    }

    wasmOutputString(file, "{\n");
    wasmCWriteLocalsDeclarations(file, module, function, pretty);
    wasmCWriteStackDeclarations(file, stackDeclarations, pretty);
    wasmOutputString(file, stringBuilder.string);
    wasmOutputString(file, "}\n");

    result = true;

cleanup:
    stringBuilderFree(&stringBuilder);
    return result;
}



static
bool
WARN_UNUSED_RESULT
wasmCWriteFunctionSignature(
    WasmOutput* file,
    const WasmModule* module,
    const char* moduleName,
    const WasmFunction function,
    const U32 functionIndex,
    const bool writeParameterNames,
    const bool pretty,
    const bool prefix,
    WasmDiagnosticContext* diagnostics
) {
    const char* returnType = NULL;
    const WasmFunctionType functionType =
        module->functionTypes.functionTypes[function.functionTypeIndex];

    MUST (wasmCGetReturnType(functionType, function.functionTypeIndex, &returnType, diagnostics))
    wasmOutputString(file, returnType);
    wasmOutputChar(file, ' ');
    if (prefix) {
        wasmOutputString(file, moduleName);
        wasmOutputChar(file, '_');
    }
    wasmCWriteFunctionNonImportName(file, functionIndex);
    wasmCWriteParameters(
        file,
        moduleName,
        functionType,
        writeParameterNames,
        false,
        pretty
    );
    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteFunctionDeclarations(
    WasmOutput* file,
    const WasmModule* module,
    const char* moduleName,
    const bool pretty,
    const bool debug,
    const bool multipleModules,
    WasmDiagnosticContext* diagnostics
) {
    const size_t functionImportCount = module->functionImports.length;
    const U32 functionCount = module->functions.count;

    U32 declaredFunctionIndex = 0;
    for (; declaredFunctionIndex < functionCount; declaredFunctionIndex++) {
        const WasmFunction function = module->functions.functions[declaredFunctionIndex];
        const U32 moduleFunctionIndex = assertSizeU32(functionImportCount) + declaredFunctionIndex;
        MUST (wasmCWriteFunctionSignature(
            file,
            module,
            moduleName,
            function,
            moduleFunctionIndex,
            false,
            pretty,
            multipleModules,
            diagnostics
        ))

        if (debug && function.exportName == NULL && moduleFunctionIndex < module->functionNames.length) {
            char* functionName = module->functionNames.names[moduleFunctionIndex];
            if (functionName != NULL) {
                wasmOutputString(file, " __asm__(\"");
                wasmOutputString(file, moduleName);
                wasmOutputString(file, "_");
                wasmOutputString(file, functionName);
                wasmOutputString(file, "\")");
            }
        }
        wasmOutputString(file, ";\n\n");
    }
    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteFunctionImplementations(
    WasmOutput* file,
    const WasmModule* module,
    const char* moduleName,
    WasmDebugLines* debugLines,
    const U32 startIDIndex,
    const U32 endIDIndex,
    const WasmFunctionIDs functionIDs,
    const bool pretty,
    const bool debug,
    const bool multipleModules,
    WasmDiagnosticContext* diagnostics
) {
    const size_t functionImportCount = module->functionImports.length;

    WasmTypeStack typeStack = wasmEmptyTypeStack;
    WasmTypeStack stackDeclarations = wasmEmptyTypeStack;
    WasmLabelStack labelStack = wasmEmptyLabelStack;
    bool result = false;

    U32 functionIDIndex = startIDIndex;
    for (; functionIDIndex < endIDIndex; functionIDIndex++) {
        const WasmFunctionID functionID = functionIDs.functionIDs[functionIDIndex];
        const U32 functionIndex = functionID.functionIndex;
        const WasmFunction function = module->functions.functions[functionIndex];

        diagnostics->location.hasFunctionIndex = true;
        diagnostics->location.functionIndex = assertSizeU32(functionImportCount) + functionIndex;
        wasmTypeStackClear(&typeStack);
        wasmTypeStackClear(&stackDeclarations);
        wasmLabelStackClear(&labelStack);

        if (debug) {
            const WasmDebugLine* debugLine = wasmCGetDebugLine(debugLines, function.start);
            if (debugLine != NULL) {
                wasmOutputString(file, "#line ");
                wasmOutputU32(file, (U32)debugLine->number);
                wasmOutputString(file, " \"");
                wasmOutputString(file, debugLine->path);
                wasmOutputString(file, "\"\n");
            }
        }

        MUST_OR_GOTO (cleanup, wasmCWriteFunctionSignature(
            file,
            module,
            moduleName,
            function,
            assertSizeU32(functionImportCount) + functionIndex,
            true,
            pretty,
            multipleModules,
            diagnostics
        ))
        wasmOutputChar(file, ' ');
        MUST_OR_GOTO (cleanup, wasmCWriteFunctionBody(
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
            multipleModules,
            diagnostics
        ))
        wasmOutputString(file, "\n");
        if (file->failed) {
            goto cleanup;
        }
    }

    result = true;

cleanup:
    if (!result && !diagnostics->hasError) {
        wasmDiagnosticReportTranslationFailed(diagnostics);
    }
    wasmTypeStackFree(&typeStack);
    wasmTypeStackFree(&stackDeclarations);
    wasmLabelsFree(&labelStack.labels);
    return result;
}

static
W2C2_INLINE
void
wasmCWriteGlobalImportType(
    WasmOutput* file,
    const WasmGlobalImport import
) {
    wasmOutputString(file, valueTypeNames[import.globalType.valueType]);
    wasmOutputChar(file, '*');
}

static
void
wasmCWriteGlobalImports(
    WasmOutput* file,
    const WasmModule* module,
    const bool pretty
) {
    const size_t globalImportCount = module->globalImports.length;
    U32 globalIndex = 0;
    for (; globalIndex < globalImportCount; globalIndex++) {
        const WasmGlobalImport import = module->globalImports.imports[globalIndex];
        if (pretty) {
            wasmOutputString(file, indentation);
        }
        wasmCWriteGlobalImportType(file, import);
        if (pretty) {
            wasmOutputChar(file, ' ');
        }
        wasmCWriteImportName(file, import.module, import.name);
        wasmOutputString(file, ";\n");
    }
}

static
void
wasmCWriteGlobals(
    WasmOutput* file,
    const WasmModule* module,
    const bool pretty
) {
    const size_t globalImportCount = module->globalImports.length;
    const U32 globalCount = module->globals.count;

    U32 globalIndex = 0;
    for (; globalIndex < globalCount; globalIndex++) {
        const WasmGlobal global = module->globals.globals[globalIndex];
        if (pretty) {
            wasmOutputString(file, indentation);
        }
        wasmOutputString(file, valueTypeNames[global.type.valueType]);
        wasmOutputChar(file, ' ');
        wasmCWriteGlobalNonImportName(file, assertSizeU32(globalImportCount) + globalIndex);
        wasmOutputString(file, ";\n");
    }
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteConstantExpr(
    StringBuilder* builder,
    const WasmModule* module,
    Buffer code,
    WasmDiagnosticContext* diagnostics
) {
    WasmOutput output = wasmOutputForStringBuilder(builder, diagnostics);
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
                wasmDiagnosticReportInvalidInstruction(
                    diagnostics,
                    wasmDiagnosticOpcodeUnprefixed,
                    (U32)opcode
                );
                return false;
            }
            MUST (wasmCWriteLiteral(builder, resultType, instruction.value, diagnostics))
            break;
        }
        case wasmOpcodeGlobalGet: {
            WasmGlobalInstruction instruction;
            MUST (wasmGlobalInstructionRead(&code, &instruction))
            MUST (wasmCWriteGlobalUse(&output, module, instruction.globalIndex, false))
            break;
        }
        default: {
            wasmDiagnosticReportUnsupportedOpcode(diagnostics, wasmDiagnosticOpcodeUnprefixed, (U32)opcode);
            return false;
        }
    }

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteInitGlobals(
    WasmOutput* file,
    const WasmModule* module,
    const char* moduleName,
    const bool pretty,
    WasmDiagnosticContext* diagnostics
) {
    const size_t globalImportCount = module->globalImports.length;
    const U32 globalCount = module->globals.count;

    if (globalCount > 0) {
        StringBuilder stringBuilder = emptyStringBuilder;
        bool result = false;
        if (!stringBuilderInitialize(&stringBuilder)) {
            wasmDiagnosticReportAllocationFailed(diagnostics);
            goto cleanup;
        }

        wasmOutputString(file, "static void ");
        wasmOutputString(file, moduleName);
        wasmOutputString(file, "InitGlobals(");
        wasmOutputString(file, moduleName);
        wasmOutputString(file, "Instance* i) {\n");

        {
            U32 globalIndex = 0;
            for (; globalIndex < globalCount; globalIndex++) {
                const WasmGlobal global = module->globals.globals[globalIndex];

                if (pretty) {
                    wasmOutputString(file, indentation);
                }
                wasmCWriteGlobalUse(file, module, assertSizeU32(globalImportCount) + globalIndex, false);
                if (pretty) {
                    wasmOutputString(file, " = ");
                } else {
                    wasmOutputChar(file, '=');
                }
                {
                    const Buffer code = global.init;
                    MUST_OR_GOTO (cleanup, stringBuilderReset(&stringBuilder))
                    MUST_OR_GOTO (
                        cleanup,
                        wasmCWriteConstantExpr(&stringBuilder, module, code, diagnostics)
                    )
                    wasmOutputString(file, stringBuilder.string);
                }
                wasmOutputString(file, ";\n");
            }
        }

        wasmOutputString(file, "}\n\n");

        result = true;

cleanup:
        stringBuilderFree(&stringBuilder);
        return result;
    }

    return true;
}

static
W2C2_INLINE
void
wasmCWriteInitImportAssignment(
    WasmOutput* file,
    const char* module,
    const char* name,
    const bool pretty
) {
    if (pretty) {
        wasmOutputString(file, indentation);
    }
    wasmOutputString(file, "i->");
    wasmCWriteImportName(file, module, name);
    if (pretty) {
        wasmOutputString(file, " =\n");
        if (pretty) {
            wasmOutputString(file, indentation);
            wasmOutputString(file, indentation);
        }
    } else {
        wasmOutputChar(file, '=');
    }
}

static
W2C2_INLINE
void
wasmCWriteInitImportValue(
    WasmOutput* file,
    const char* module,
    const char* name
) {
    wasmOutputString(file, "resolve(\"");
    wasmOutputString(file, module);
    wasmOutputString(file, "\", \"");
    wasmOutputString(file, name);
    wasmOutputString(file, "\");\n");
}

static
W2C2_INLINE
bool
WARN_UNUSED_RESULT
wasmCWriteFunctionImport(
    WasmOutput* file,
    const WasmModule* module,
    const char* moduleName,
    const WasmFunctionImport import,
    const bool declaration,
    const bool pretty,
    const bool prefix,
    WasmDiagnosticContext* diagnostics
) {
    const char* returnType = NULL;
    const WasmFunctionType functionType = module->functionTypes.functionTypes[import.functionTypeIndex];
    MUST (wasmCGetReturnType(functionType, import.functionTypeIndex, &returnType, diagnostics))
    wasmOutputString(file, returnType);
    wasmOutputChar(file, ' ');
    if (declaration) {
        if (prefix) {
            wasmOutputString(file, moduleName);
            wasmOutputChar(file, '_');
        }
        wasmCWriteImportName(file, import.module, import.name);
    }
    wasmCWriteParameters(
        file,
        moduleName,
        functionType,
        false,
        declaration,
        pretty
    );
    return true;
}

static
void
wasmCWriteInitGlobalImports(
    WasmOutput* file,
    const WasmModule* module,
    const bool pretty
) {
    const size_t globalImportCount = module->globalImports.length;
    U32 globalIndex = 0;
    for (; globalIndex < globalImportCount; globalIndex++) {
        const WasmGlobalImport import = module->globalImports.imports[globalIndex];
        wasmCWriteInitImportAssignment(file, import.module, import.name, pretty);
        wasmOutputChar(file, '(');
        wasmCWriteGlobalImportType(file, import);
        wasmOutputChar(file, ')');
        wasmCWriteInitImportValue(file, import.module, import.name);
    }
}

static
W2C2_INLINE
void
wasmCWriteMemoryType(
    WasmOutput* file
) {
    wasmOutputString(file, "wasmMemory*");
}

static
void
wasmCWriteInitMemoryImports(
    WasmOutput* file,
    const WasmModule* module,
    const bool pretty
) {
    const size_t memoryImportCount = module->memoryImports.length;

    U32 memoryIndex = 0;
    for (; memoryIndex < memoryImportCount; memoryIndex++) {
        const WasmMemoryImport import = module->memoryImports.imports[memoryIndex];
        wasmCWriteInitImportAssignment(file, import.module, import.name, pretty);
        wasmOutputChar(file, '(');
        wasmCWriteMemoryType(file);
        wasmOutputChar(file, ')');
        wasmCWriteInitImportValue(file, import.module, import.name);
    }
}

static
W2C2_INLINE
void
wasmCWriteTableType(
    WasmOutput* file
) {
    wasmOutputString(file, "wasmTable*");
}

static
void
wasmCWriteInitTableImports(
    WasmOutput* file,
    const WasmModule* module,
    const bool pretty
) {
    const size_t tableImportCount = module->tableImports.length;

    U32 tableIndex = 0;
    for (; tableIndex < tableImportCount; tableIndex++) {
        const WasmTableImport import = module->tableImports.imports[tableIndex];
        wasmCWriteInitImportAssignment(file, import.module, import.name, pretty);
        wasmOutputChar(file, '(');
        wasmCWriteTableType(file);
        wasmOutputChar(file, ')');
        wasmCWriteInitImportValue(file, import.module, import.name);
    }
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteInitImports(
    WasmOutput* file,
    const WasmModule* module,
    const char* moduleName,
    const bool pretty
) {
    wasmOutputString(file, "static void ");
    wasmOutputString(file, moduleName);
    wasmOutputString(file, "InitImports(");
    wasmOutputString(file, moduleName);
    wasmOutputString(file, "Instance* i, void* resolve(const char* module, const char* name)) {\n");
    if (pretty) {
        wasmOutputString(file, indentation);
    }
    wasmOutputString(file, "if (resolve == NULL) { return; }\n");

    wasmCWriteInitMemoryImports(file, module, pretty);
    wasmCWriteInitTableImports(file, module, pretty);
    wasmCWriteInitGlobalImports(file, module, pretty);

    wasmOutputString(file, "}\n\n");

    return true;
}

static
W2C2_INLINE
void
wasmCWriteExportName(
    WasmOutput* file,
    const char* moduleName,
    const char* name
) {
    wasmOutputString(file, moduleName);
    wasmOutputString(file, "_");
    wasmCWriteEscaped(file, name);
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteFunctionExport(
    WasmOutput* file,
    const WasmModule* module,
    const char* moduleName,
    const WasmExport export,
    const WasmFunctionType functionType,
    const U32 functionTypeIndex,
    const bool writeBody,
    const bool pretty,
    const bool multipleModules,
    WasmDiagnosticContext* diagnostics
) {
    const char* returnType = NULL;
    const U32 parameterCount = functionType.parameterCount;

    MUST (wasmCGetReturnType(functionType, functionTypeIndex, &returnType, diagnostics))
    wasmOutputString(file, returnType);
    wasmOutputChar(file, ' ');
    wasmCWriteExportName(file, moduleName, export.name);
    wasmCWriteParameters(
        file,
        moduleName,
        functionType,
        true,
        false,
        pretty
    );
    if (writeBody) {
        if (pretty) {
            wasmOutputChar(file, ' ');
        }
        wasmOutputString(file, "{\n");
        if (pretty) {
            wasmOutputString(file, indentation);
        }
        if (functionType.resultCount > 0) {
            wasmOutputString(file, "return ");
        }
        wasmCWriteFunctionUse(file, module, moduleName, export.index, false, multipleModules);
        wasmOutputString(file, "(i");
        {
            U32 parameterIndex = 0;
            for (; parameterIndex < parameterCount; parameterIndex++) {
                if (pretty) {
                    wasmOutputString(file, ", ");
                } else {
                    wasmOutputChar(file, ',');
                }
                wasmCWriteLocalName(file, parameterIndex);
            }
        }
        wasmOutputString(file, ");\n}\n\n");
    } else {
        wasmOutputString(file, ";\n\n");
    }
    return true;
}

static
void
wasmCWriteMemoryExport(
    WasmOutput* file,
    const WasmModule* module,
    const char* moduleName,
    const WasmExport export,
    const bool writeBody,
    const bool pretty
) {
    wasmCWriteMemoryType(file);
    if (pretty) {
        wasmOutputChar(file, ' ');
    }
    wasmCWriteExportName(file, moduleName, export.name);
    wasmOutputString(file, "(");
    wasmOutputString(file, moduleName);
    wasmOutputString(file, "Instance* i)");
    if (writeBody) {
        if (pretty) {
            wasmOutputChar(file, ' ');
        }
        wasmOutputString(file, "{\n");
        if (pretty) {
            wasmOutputString(file, indentation);
        }
        wasmOutputString(file, "return ");
        wasmCWriteMemoryUse(file, module, export.index, NULL, true);
        wasmOutputString(file, ";\n}\n\n");
    } else {
        wasmOutputString(file, ";\n\n");
    }
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteExports(
    WasmOutput* file,
    const WasmModule* module,
    const char* moduleName,
    const bool writeBody,
    const bool pretty,
    const bool multipleModules,
    WasmDiagnosticContext* diagnostics
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
                MUST (wasmCWriteFunctionExport(file, module, moduleName, export, functionType, functionTypeIndex, writeBody, pretty, multipleModules, diagnostics))
                break;
            }
            case wasmExportKindMemory: {
                wasmCWriteMemoryExport(file, module, moduleName, export, writeBody, pretty);
                break;
            }
            default: {
                /* TODO: other export kinds */
                wasmDiagnosticReportUnsupportedExport(diagnostics, export.name, export.kind);
            }
        }
    }
    return true;
}

#define DATA_SEGMENT_CHUNK_LENGTH 18

/* TODO: add support for multiple modules */
static
bool
WARN_UNUSED_RESULT
wasmCWriteDataSegments(
    WasmOutput* file,
    const WasmModule* module,
    const WasmDataSegmentMode mode,
    const bool pretty,
    WasmDiagnosticContext* diagnostics
) {
    const U32 dataSegmentCount = module->dataSegments.count;

    switch (mode) {
        case wasmDataSegmentModeArrays: {
            U32 dataSegmentIndex = 0;
            for (; dataSegmentIndex < dataSegmentCount; dataSegmentIndex++) {
                const WasmDataSegment dataSegment = module->dataSegments.dataSegments[dataSegmentIndex];
                const size_t byteCount = dataSegment.bytes.length;

                wasmOutputString(file, "const U8 ");
                /* TODO: add support for multiple modules */
                wasmCWriteDataSegmentName(file, dataSegmentIndex);
                if (pretty) {
                    wasmOutputString(file, "[] = {");
                } else {
                    wasmOutputString(file, "[]={");
                }
                if (byteCount > DATA_SEGMENT_CHUNK_LENGTH) {
                    wasmOutputChar(file, '\n');
                    if (pretty) {
                        wasmOutputString(file, indentation);
                    }
                }
                {
                    U32 byteIndex = 0;
                    for (; byteIndex < byteCount; byteIndex++) {
                        U8 value = dataSegment.bytes.data[byteIndex];
                        if (byteIndex > 0) {
                            if (pretty) {
                                wasmOutputString(file, ", ");
                            } else {
                                wasmOutputChar(file, ',');
                            }
                            if (byteIndex % DATA_SEGMENT_CHUNK_LENGTH == 0) {
                                wasmOutputString(file, "\n");
                                if (pretty) {
                                    wasmOutputString(file, indentation);
                                }
                            }
                        }
                        if (value < 10) {
                            wasmOutputU32(file, value);
                        } else {
                            wasmOutputString(file, "0x");
                            wasmOutputHex(file, (unsigned int)value, wasmOutputHexLower);
                        }
                    }
                }
                if (byteCount > DATA_SEGMENT_CHUNK_LENGTH) {
                    wasmOutputChar(file, '\n');
                }
                wasmOutputString(file, "};\n\n");
            }
            break;
        }
        case wasmDataSegmentModeGNULD:
        case wasmDataSegmentModeSectcreate1:
        case wasmDataSegmentModeSectcreate2: {
            U32 writtenCount = 0;
            U32 dataSegmentIndex = 0;
            for (; dataSegmentIndex < dataSegmentCount; dataSegmentIndex++) {
                const WasmDataSegment dataSegment = module->dataSegments.dataSegments[dataSegmentIndex];
                if (!dataSegment.passive) {
                    continue;
                }
                if (writtenCount == 0) {
                    wasmOutputString(file, "U8 ");
                } else {
                    wasmOutputChar(file, ',');
                }
                wasmOutputChar(file, '*');
                /* TODO: add support for multiple modules */
                wasmCWriteDataSegmentName(file, dataSegmentIndex);
                writtenCount += 1;
            }
            if (writtenCount > 0) {
                wasmOutputString(file, ";\n");
            }
            break;
        }
        default: {
            wasmDiagnosticReportInvalidDataSegmentMode(diagnostics, mode);
            return false;
        }
    }
    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteDataSegmentsFromSection(
    WasmOutput* file,
    const WasmModule* module,
    const WasmDataSegmentMode mode,
    WasmDiagnosticContext* diagnostics
) {
    static const char* const filename = "datasegments";
    const U32 dataSegmentCount = module->dataSegments.count;

    U32 dataSegmentIndex = 0;
    WasmOutput segmentsOutput;
    WasmOutput* segmentsFile = &segmentsOutput;
    bool result = false;

    switch (mode) {
        case wasmDataSegmentModeGNULD: {
            wasmOutputString(file, "extern U8 _binary_datasegments_start[];\n\n");
            wasmOutputString(file, "static U8* ds = _binary_datasegments_start;\n");
            break;
        }
        case wasmDataSegmentModeSectcreate1: {
            wasmOutputString(file, "extern U8 data_segments_data __asm(\"section$start$__DATA$__datasegments\");\n\n");
            wasmOutputString(file, "static U8* ds = &data_segments_data;\n");
            break;
        }
        case wasmDataSegmentModeSectcreate2: {
            /*
             * On Rhapsody, mach-o/getsect.h was added.
             * On OPENSTEP, libc.h is needed.
             */
            wasmOutputString(file, "#include <mach/mach.h>\n"
                "#ifdef __MACH30__\n"
                "#include <mach-o/getsect.h>\n"
                "#define SECT_DATA_SIZE_TYPE unsigned long\n"
                "#else\n"
                "#include <libc.h>\n"
                "#define SECT_DATA_SIZE_TYPE int\n"
                "#endif\n");
            wasmOutputString(file, "SECT_DATA_SIZE_TYPE len = 0;\n"
                "static char* ds = getsectdata(\"__DATA\", \"__datasegments\", &len);\n");
            break;
        }
        default: {
            wasmDiagnosticReportInvalidDataSegmentMode(diagnostics, mode);
            return false;
        }
    }

    if (file->failed) {
        return false;
    }

    diagnostics->location.outputName = filename;
    diagnostics->location.hasFunctionIndex = false;
    if (!wasmOutputOpen(segmentsFile, file->provider, filename, wasmOutputData, diagnostics)) {
        return false;
    }

    for (; dataSegmentIndex < dataSegmentCount; dataSegmentIndex++) {
        const WasmDataSegment dataSegment = module->dataSegments.dataSegments[dataSegmentIndex];
        const size_t length = dataSegment.bytes.length;
        wasmOutputWrite(segmentsFile, dataSegment.bytes.data, length);
        if (segmentsFile->failed) {
            goto cleanup;
        }
    }

    result = true;

cleanup:
    diagnostics->location.hasFunctionIndex = false;
    diagnostics->location.outputName = filename;
    if (!result) {
        wasmOutputAbort(segmentsFile);
        return false;
    }
    return wasmOutputClose(segmentsFile);

}

static
void
wasmCWriteMemoryImports(
    WasmOutput* file,
    const WasmModule* module,
    const bool pretty
) {
    const size_t memoryImportCount = module->memoryImports.length;

    U32 memoryIndex = 0;
    for (; memoryIndex < memoryImportCount; memoryIndex++) {
        const WasmMemoryImport import = module->memoryImports.imports[memoryIndex];
        if (pretty) {
            wasmOutputString(file, indentation);
        }
        wasmCWriteMemoryType(file);
        if (pretty) {
            wasmOutputChar(file, ' ');
        }
        wasmCWriteImportName(file, import.module, import.name);
        wasmOutputString(file, ";\n");
    }
}

static
void
wasmCWriteMemories(
    WasmOutput* file,
    const WasmModule* module,
    const bool pretty
) {
    const size_t memoryImportCount = module->memoryImports.length;
    const U32 memoryCount = module->memories.count;

    U32 memoryIndex = 0;
    for (; memoryIndex < memoryCount; memoryIndex++) {
        U32 moduleMemoryIndex = assertSizeU32(memoryImportCount) + memoryIndex;
        if (pretty) {
            wasmOutputString(file, indentation);
        }
        wasmOutputString(file, "wasmMemory* ");
        wasmCWriteMemoryNonImportName(file, moduleMemoryIndex);
        wasmOutputString(file, ";\n");
    }
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteInitMemories(
    WasmOutput* file,
    const WasmModule* module,
    const char* moduleName,
    const WasmDataSegmentMode dataSegmentMode,
    const bool pretty,
    WasmDiagnosticContext* diagnostics
) {
    const size_t memoryImportCount = module->memoryImports.length;
    const U32 memoryCount = module->memories.count;
    if (memoryCount > 0) {

        StringBuilder stringBuilder = emptyStringBuilder;
        bool result = false;
        if (!stringBuilderInitialize(&stringBuilder)) {
            wasmDiagnosticReportAllocationFailed(diagnostics);
            goto cleanup;
        }

        wasmOutputString(file, "static void ");
        wasmOutputString(file, moduleName);
        wasmOutputString(file, "InitMemories(");
        wasmOutputString(file, moduleName);
        wasmOutputString(file, "Instance* i, ");
        wasmOutputString(file, moduleName);
        wasmOutputString(file, "Instance* parent) {\n");

        {
            U32 memoryIndex = 0;
            for (; memoryIndex < memoryCount; memoryIndex++) {
                const WasmMemory memory = module->memories.memories[memoryIndex];
                U32 moduleMemoryIndex = assertSizeU32(memoryImportCount) + memoryIndex;

                if (memory.shared) {
                    if (pretty) {
                        wasmOutputString(file, indentation);
                    }
                    wasmOutputString(file, "if (parent == NULL) {\n");
                    {
                        if (pretty) {
                            wasmOutputString(file, indentation);
                            wasmOutputString(file, indentation);
                        }
                        wasmCWriteMemoryUse(file, module, moduleMemoryIndex, NULL, true);
                        wasmOutputString(file, "= WASM_MEMORY_ALLOCATE_SHARED(");
                        wasmOutputU32(file, memory.min);
                        wasmOutputString(file, ", ");
                        wasmOutputU32(file, memory.max);
                        wasmOutputString(file, ");\n");
                    }
                    if (pretty) {
                        wasmOutputString(file, indentation);
                    }
                    wasmOutputString(file, "} else {\n");
                    {
                        if (pretty) {
                            wasmOutputString(file, indentation);
                            wasmOutputString(file, indentation);
                        }
                        wasmCWriteMemoryUse(file, module, moduleMemoryIndex, NULL, true);
                        wasmOutputString(file, " = ");
                        wasmCWriteMemoryUse(file, module, moduleMemoryIndex, "parent", true);
                        wasmOutputString(file, ";\n");
                    }
                    if (pretty) {
                        wasmOutputString(file, indentation);
                    }
                    wasmOutputString(file, "}\n");
                } else {
                    if (pretty) {
                        wasmOutputString(file, indentation);
                    }
                    wasmCWriteMemoryUse(file, module, moduleMemoryIndex, NULL, true);
                    wasmOutputString(file, " = wasmMemoryAllocate(");
                    wasmOutputU32(file, memory.min);
                    wasmOutputString(file, ", ");
                    wasmOutputU32(file, memory.max);
                    wasmOutputString(file, ", false);\n");
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

                if (dataSegment.passive) {
                    switch (dataSegmentMode) {
                        case wasmDataSegmentModeGNULD:
                        case wasmDataSegmentModeSectcreate1:
                        case wasmDataSegmentModeSectcreate2: {
                            /* Initialize the data segment variable */
                            /* TODO: add support for multiple modules */
                            wasmCWriteDataSegmentName(file, dataSegmentIndex);
                            if (pretty) {
                                wasmOutputString(file, " = ds + ");
                                wasmOutputU64(file, byteOffset);
                            } else {
                                wasmOutputString(file, "=ds+");
                                wasmOutputU64(file, byteOffset);
                            }
                            wasmOutputString(file, ";\n");
                            break;
                        }
                        case wasmDataSegmentModeArrays:
                            /* The data segment variable is already initialized */
                            break;
                    }
                } else {
                    /* Load active segments */
                    if (code.data != NULL) {
                        if (pretty) {
                            wasmOutputString(file, indentation);
                        }
                        wasmOutputString(file, "LOAD_DATA(");
                        wasmCWriteMemoryUse(
                            file,
                            module,
                            dataSegment.memoryIndex,
                            NULL,
                            false
                        );
                        wasmOutputString(file, ", ");
                        MUST_OR_GOTO (cleanup, stringBuilderReset(&stringBuilder))
                        MUST_OR_GOTO (
                            cleanup,
                            wasmCWriteConstantExpr(&stringBuilder, module, code, diagnostics)
                        )
                        wasmOutputString(file, stringBuilder.string);
                        /* TODO: add support for multiple modules */
                        switch (dataSegmentMode) {
                            case wasmDataSegmentModeGNULD:
                            case wasmDataSegmentModeSectcreate1:
                            case wasmDataSegmentModeSectcreate2:
                                wasmOutputString(file, ", ds+");
                                wasmOutputU64(file, byteOffset);
                                break;
                            case wasmDataSegmentModeArrays:
                                wasmOutputString(file, ", ");
                                wasmCWriteDataSegmentName(file, dataSegmentIndex);
                                break;
                        }
                        wasmOutputString(file, ", ");
                        wasmOutputU64(file, (unsigned long) dataSegmentLength);
                        wasmOutputString(file, ");\n");
                    }
                }

                byteOffset += dataSegment.bytes.length;
            }
        }

        wasmOutputString(file, "}\n\n");

        result = true;

cleanup:
        stringBuilderFree(&stringBuilder);
        return result;
    }
    return true;
}

static
void
wasmCWriteFreeMemories(
    WasmOutput* file,
    const WasmModule* module,
    const bool pretty,
    const bool freeShared
) {
    const size_t memoryImportCount = module->memoryImports.length;
    const U32 memoryCount = module->memories.count;
    U32 memoryIndex = 0;
    for (; memoryIndex < memoryCount; memoryIndex++) {
        const WasmMemory memory = module->memories.memories[memoryIndex];
        U32 moduleMemoryIndex = assertSizeU32(memoryImportCount) + memoryIndex;
        if (!freeShared && memory.shared) {
            continue;
        }
        if (pretty) {
            wasmOutputString(file, indentation);
        }
        wasmOutputString(file, "wasmMemoryFree(");
        wasmCWriteMemoryUse(file, module, moduleMemoryIndex, NULL, true);
        wasmOutputString(file, ");\n");
        if (pretty) {
            wasmOutputString(file, indentation);
        }
        wasmCWriteMemoryUse(file, module, moduleMemoryIndex, NULL, true);
        if (pretty) {
            wasmOutputString(file, " = NULL;\n");
        } else {
            wasmOutputString(file, "=NULL;\n");
        }
    }
}

static
void
wasmCWriteTableImports(
    WasmOutput* file,
    const WasmModule* module,
    const bool pretty
) {
    const size_t tableImportCount = module->tableImports.length;

    U32 tableIndex = 0;
    for (; tableIndex < tableImportCount; tableIndex++) {
        const WasmTableImport import = module->tableImports.imports[tableIndex];
        if (pretty) {
            wasmOutputString(file, indentation);
        }
        wasmCWriteTableType(file);
        if (pretty) {
            wasmOutputChar(file, ' ');
        }
        wasmCWriteImportName(file, import.module, import.name);
        wasmOutputString(file, ";\n");
    }
}

static
void
wasmCWriteTables(
    WasmOutput* file,
    const WasmModule* module,
    const bool pretty
) {
    const size_t tableImportCount = module->tableImports.length;
    const U32 tableCount = module->tables.count;

    U32 tableIndex = 0;
    for (; tableIndex < tableCount; tableIndex++) {
        if (pretty) {
            wasmOutputString(file, indentation);
        }
        wasmOutputString(file, "wasmTable ");
        wasmCWriteTableNonImportName(file, assertSizeU32(tableImportCount) + tableIndex);
        wasmOutputString(file, ";\n");
    }
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteInitTables(
    WasmOutput* file,
    const WasmModule* module,
    const char* moduleName,
    const bool pretty,
    const bool multipleModules,
    WasmDiagnosticContext* diagnostics
) {
    const size_t tableImportCount = module->tableImports.length;
    const U32 elementSegmentCount = module->elementSegments.count;
    const U32 tableCount = module->tables.count;
    if (tableCount > 0 || elementSegmentCount > 0) {
        StringBuilder stringBuilder = emptyStringBuilder;
        bool result = false;
        if (!stringBuilderInitialize(&stringBuilder)) {
            wasmDiagnosticReportAllocationFailed(diagnostics);
            goto cleanup;
        }

        wasmOutputString(file, "static void ");
        wasmOutputString(file, moduleName);
        wasmOutputString(file, "InitTables(");
        wasmOutputString(file, moduleName);
        wasmOutputString(file, "Instance* i) {\n");

        if (elementSegmentCount > 0) {
            if (pretty) {
                wasmOutputString(file, indentation);
            }
            wasmOutputString(file, "U32 offset;\n");
        }

        {
            U32 tableIndex = 0;
            for (; tableIndex < tableCount; tableIndex++) {
                const WasmTable table = module->tables.tables[tableIndex];

                if (pretty) {
                    wasmOutputString(file, indentation);
                }
                wasmOutputString(file, "wasmTableAllocate(");
                wasmCWriteTableUse(file, module, assertSizeU32(tableImportCount) + tableIndex, true);
                wasmOutputString(file, ", ");
                wasmOutputU32(file, table.min);
                wasmOutputString(file, ", ");
                wasmOutputU32(file, table.max);
                wasmOutputString(file, ");\n");
            }
        }

        {
            U32 elementSegmentIndex = 0;
            for (; elementSegmentIndex < elementSegmentCount; elementSegmentIndex++) {
                const WasmElementSegment elementSegment = module->elementSegments.elementSegments[elementSegmentIndex];

                if (pretty) {
                    wasmOutputString(file, indentation);
                    wasmOutputString(file, "offset = ");
                } else {
                    wasmOutputString(file, "offset=");
                }
                {
                    const Buffer code = elementSegment.offset;
                    MUST_OR_GOTO (cleanup, stringBuilderReset(&stringBuilder))
                    MUST_OR_GOTO (
                        cleanup,
                        wasmCWriteConstantExpr(&stringBuilder, module, code, diagnostics)
                    )
                    wasmOutputString(file, stringBuilder.string);
                }
                wasmOutputString(file, ";\n");

                {
                    U32 functionIndexIndex = 0;
                    for (; functionIndexIndex < elementSegment.functionIndexCount; functionIndexIndex++) {
                        const U32 functionIndex = elementSegment.functionIndices[functionIndexIndex];
                        if (pretty) {
                            wasmOutputString(file, indentation);
                        }
                        wasmCWriteTableUse(file, module, elementSegment.tableIndex, false);
                        if (pretty) {
                            wasmOutputString(file, ".data[offset + ");
                            wasmOutputU32(file, functionIndexIndex);
                            wasmOutputString(file, "] = (wasmFunc)");
                        } else {
                            wasmOutputString(file, ".data[offset+");
                            wasmOutputU32(file, functionIndexIndex);
                            wasmOutputString(file, "]=(wasmFunc)");
                        }
                        wasmCWriteFunctionUse(file, module, moduleName, functionIndex, true, multipleModules);
                        wasmOutputString(file, ";\n");
                    }
                }
            }
        }

        wasmOutputString(file, "}\n\n");

        result = true;

cleanup:
        stringBuilderFree(&stringBuilder);
        return result;
    }

    return true;
}

static
void
wasmCWriteFreeTables(
    WasmOutput* file,
    const WasmModule* module,
    const bool pretty
) {
    const size_t tableImportCount = module->tableImports.length;
    const U32 tableCount = module->tables.count;
    U32 tableIndex = 0;
    for (; tableIndex < tableCount; tableIndex++) {
        if (pretty) {
            wasmOutputString(file, indentation);
        }
        wasmOutputString(file, "wasmTableFree(");
        wasmCWriteTableUse(file, module, assertSizeU32(tableImportCount) + tableIndex, true);
        wasmOutputString(file, ");\n");
    }
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteFunctionImports(
    WasmOutput* file,
    const WasmModule* module,
    const char* moduleName,
    const bool pretty,
    const bool multipleModules,
    WasmDiagnosticContext* diagnostics
) {
    const size_t functionImportCount = module->functionImports.length;
    U32 functionIndex = 0;
    for (; functionIndex < functionImportCount; functionIndex++) {
        const WasmFunctionImport import = module->functionImports.imports[functionIndex];
        if (pretty) {
            wasmOutputString(file, indentation);
        }
        MUST (wasmCWriteFunctionImport(file, module, moduleName, import, true, pretty, multipleModules, diagnostics))
        wasmOutputString(file, ";\n\n");
    }
    return true;
}

static
W2C2_INLINE
void
wasmCWriteBaseInclude(
    WasmOutput* file
) {
    wasmOutputString(file, "#include \"w2c2_base.h\"\n\n");
}

static
W2C2_INLINE
void
wasmCWriteIncludes(
    WasmOutput* file,
    const char* headerName
) {
    wasmCWriteBaseInclude(file);
    wasmOutputString(file, "#include \"");
    wasmOutputString(file, headerName);
    wasmOutputString(file, "\"\n\n");
}

static
void
wasmCWriteModuleInstanceDeclaration(
    WasmOutput* file,
    const WasmModule* module,
    const char* moduleName,
    const bool pretty
) {
    wasmOutputString(file, "typedef struct ");
    wasmOutputString(file, moduleName);
    wasmOutputString(file, "Instance {\n");

    if (pretty) {
        wasmOutputString(file, indentation);
    }
    wasmOutputString(file, "wasmModuleInstance common;\n");

    wasmCWriteMemoryImports(file, module, pretty);
    wasmCWriteTableImports(file, module, pretty);
    wasmCWriteGlobalImports(file, module, pretty);

    wasmCWriteMemories(file, module, pretty);
    wasmCWriteTables(file, module, pretty);
    wasmCWriteGlobals(file, module, pretty);

    wasmOutputString(file, "} ");
    wasmOutputString(file, moduleName);
    wasmOutputString(file, "Instance;\n\n");
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteModuleDeclarations(
    WasmOutput* file,
    const WasmModule* module,
    const char* moduleName,
    const bool pretty,
    const bool debug,
    const bool multipleModules,
    WasmDiagnosticContext* diagnostics
) {
    wasmCWriteModuleInstanceDeclaration(file, module, moduleName, pretty);
    MUST (wasmCWriteFunctionImports(file, module, moduleName, pretty, multipleModules, diagnostics))
    MUST (wasmCWriteFunctionDeclarations(file, module, moduleName, pretty, debug, multipleModules, diagnostics))
    MUST (wasmCWriteExports(file, module, moduleName, false, pretty, multipleModules, diagnostics))
    return true;
}

static
void
wasmCWriteFreeChildFunction(
    WasmOutput* file,
    const WasmModule* module,
    const char* moduleName,
    const bool pretty
) {
    wasmOutputString(file, "static void ");
    wasmOutputString(file, moduleName);
    wasmOutputString(file, "FreeChild(wasmModuleInstance* child) {\n");

    if (pretty) {
        wasmOutputString(file, indentation);
    }
    wasmOutputString(file, moduleName);
    wasmOutputString(file, "Instance* i = (");
    wasmOutputString(file, moduleName);
    wasmOutputString(file, "Instance*)child;\n");

    wasmCWriteFreeMemories(file, module, pretty, false);
    wasmCWriteFreeTables(file, module, pretty);

    if (pretty) {
        wasmOutputString(file, indentation);
    }
    wasmOutputString(file, "free(i);\n");
    wasmOutputString(file, "}\n\n");
}

/* TODO: verify */
static
void
wasmCWriteNewChildFunction(
    WasmOutput* file,
    const WasmModule* module,
    const char* moduleName,
    const bool pretty,
    const bool multipleModules
) {
    wasmOutputString(file, "static wasmModuleInstance* ");
    wasmOutputString(file, moduleName);
    wasmOutputString(file, "NewChild(wasmModuleInstance* instance) {\n");

    /* TODO: clean up */
    if (pretty) {
        wasmOutputString(file, indentation);
    }
    wasmOutputString(file, moduleName);
    wasmOutputString(file, "Instance* self = (");
    wasmOutputString(file, moduleName);
    wasmOutputString(file, "Instance*)instance;\n");

    if (pretty) {
        wasmOutputString(file, indentation);
    }
    wasmOutputString(file, moduleName);
    wasmOutputString(file, "Instance* child = (");
    wasmOutputString(file, moduleName);
    wasmOutputString(file, "Instance*)calloc(1, sizeof(");
    wasmOutputString(file, moduleName);
    wasmOutputString(file, "Instance));\n");

    if (pretty) {
        wasmOutputString(file, indentation);
    }
    wasmOutputString(file, "child->common.funcExports = self->common.funcExports;\n");

    if (pretty) {
        wasmOutputString(file, indentation);
    }
    wasmOutputString(file, "child->common.resolveImports = self->common.resolveImports;\n");

    if (pretty) {
        wasmOutputString(file, indentation);
    }
    wasmOutputString(file, "child->common.newChild = self->common.newChild;\n");

    if (pretty) {
        wasmOutputString(file, indentation);
    }
    wasmOutputString(file, "child->common.freeChild = self->common.freeChild;\n");

    if (pretty) {
        wasmOutputString(file, indentation);
    }
    wasmOutputString(file, moduleName);
    wasmOutputString(file, "InitImports(child, self->common.resolveImports);\n");

    if (module->memories.count > 0) {
        if (pretty) {
            wasmOutputString(file, indentation);
        }
        wasmOutputString(file, moduleName);
        wasmOutputString(file, "InitMemories(child, self);\n");
    }

    if (module->tables.count > 0
        || module->elementSegments.count > 0
            ) {
        if (pretty) {
            wasmOutputString(file, indentation);
        }
        wasmOutputString(file, moduleName);
        wasmOutputString(file, "InitTables(child);\n");
    }

    if (module->globals.count > 0) {
        if (pretty) {
            wasmOutputString(file, indentation);
        }
        wasmOutputString(file, moduleName);
        wasmOutputString(file, "InitGlobals(child);\n");
    }

    if (module->hasStartFunction) {
        if (pretty) {
            wasmOutputString(file, indentation);
        }
        wasmCWriteFunctionUse(file, module, moduleName, module->startFunctionIndex, false, multipleModules);
        wasmOutputString(file, "(child);\n");
    }

    if (pretty) {
        wasmOutputString(file, indentation);
    }
    wasmOutputString(file, "return &child->common;\n");

    wasmOutputString(file, "}\n\n");
}


static
void
wasmCWriteInstantiateFunction(
    WasmOutput* file,
    const WasmModule* module,
    const char* moduleName,
    const bool pretty,
    const bool multipleModules
) {
    wasmOutputString(file, "void ");
    wasmOutputString(file, moduleName);
    wasmOutputString(file, "Instantiate(");
    wasmOutputString(file, moduleName);
    wasmOutputString(file, "Instance* i, void* resolveImports(const char* module, const char* name)) {\n");

    if (pretty) {
        wasmOutputString(file, indentation);
    }
    wasmOutputString(file, "i->common.funcExports = ");
    wasmOutputString(file, moduleName);
    wasmOutputString(file, "FuncExports;\n");

    if (pretty) {
        wasmOutputString(file, indentation);
    }
    wasmOutputString(file, "i->common.resolveImports = resolveImports;\n");

    if (pretty) {
        wasmOutputString(file, indentation);
    }
    wasmOutputString(file, "i->common.newChild = ");
    wasmOutputString(file, moduleName);
    wasmOutputString(file, "NewChild;\n");

    if (pretty) {
        wasmOutputString(file, indentation);
    }
    wasmOutputString(file, "i->common.freeChild = ");
    wasmOutputString(file, moduleName);
    wasmOutputString(file, "FreeChild;\n");

    if (pretty) {
        wasmOutputString(file, indentation);
    }
    wasmOutputString(file, moduleName);
    wasmOutputString(file, "InitImports(i, resolveImports);\n");

    if (module->memories.count > 0) {
        if (pretty) {
            wasmOutputString(file, indentation);
        }
        wasmOutputString(file, moduleName);
        wasmOutputString(file, "InitMemories(i, NULL);\n");
    }

    if (module->tables.count > 0
        || module->elementSegments.count > 0
    ) {
        if (pretty) {
            wasmOutputString(file, indentation);
        }
        wasmOutputString(file, moduleName);
        wasmOutputString(file, "InitTables(i);\n");
    }

    if (module->globals.count > 0) {
        if (pretty) {
            wasmOutputString(file, indentation);
        }
        wasmOutputString(file, moduleName);
        wasmOutputString(file, "InitGlobals(i);\n");
    }

    if (module->hasStartFunction) {
        if (pretty) {
            wasmOutputString(file, indentation);
        }
        wasmCWriteFunctionUse(file, module, moduleName, module->startFunctionIndex, false, multipleModules);
        wasmOutputString(file, "(i);\n");
    }

    wasmOutputString(file, "}\n\n");
}

static
void
wasmCWriteFreeFunction(
    WasmOutput* file,
    const WasmModule* module,
    const char* moduleName,
    const bool pretty
) {
    wasmOutputString(file, "void ");
    wasmOutputString(file, moduleName);
    wasmOutputString(file, "FreeInstance(");
    wasmOutputString(file, moduleName);
    wasmOutputString(file, "Instance* i) {\n");

    wasmCWriteFreeMemories(file, module, pretty, true);
    wasmCWriteFreeTables(file, module, pretty);

    wasmOutputString(file, "}\n\n");
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
    const bool multipleModules,
    WasmOutputProvider provider,
    WasmDiagnosticContext* diagnostics
) {
    /* Create file */
    WasmOutput output;
    WasmOutput* file = &output;
    bool result = false;

    diagnostics->location.outputName = filename;
    diagnostics->location.hasFunctionIndex = false;
    if (!wasmOutputOpen(file, provider, filename, wasmOutputHeader, diagnostics)) {
        return false;
    }

    wasmOutputString(file, "#ifndef ");
    wasmOutputString(file, moduleName);
    wasmOutputString(file, "_H\n");
    wasmOutputString(file, "#define ");
    wasmOutputString(file, moduleName);
    wasmOutputString(file, "_H\n\n");

    wasmOutputString(file, "#ifdef __cplusplus\nextern \"C\" {\n#endif\n\n");

    wasmCWriteBaseInclude(file);
    MUST_OR_GOTO (cleanup, wasmCWriteModuleDeclarations(file, module, moduleName, pretty, debug, multipleModules, diagnostics))
    wasmOutputString(file, "void ");
    wasmOutputString(file, moduleName);
    wasmOutputString(file, "Instantiate(");
    wasmOutputString(file, moduleName);
    wasmOutputString(file, "Instance* instance, void* resolve(const char* module, const char* name));\n\n");
    wasmOutputString(file, "void ");
    wasmOutputString(file, moduleName);
    wasmOutputString(file, "FreeInstance(");
    wasmOutputString(file, moduleName);
    wasmOutputString(file, "Instance* instance);\n\n");

    wasmOutputString(file, "#ifdef __cplusplus\n}\n#endif\n\n");

    wasmOutputString(file, "#endif /* ");
    wasmOutputString(file, moduleName);
    wasmOutputString(file, "_H */\n\n");

    result = true;

cleanup:
    diagnostics->location.hasFunctionIndex = false;
    diagnostics->location.outputName = filename;
    if (!result) {
        wasmOutputAbort(file);
        return false;
    }
    return wasmOutputClose(file);
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteModuleFunctionExportsArray(
    WasmOutput* file,
    const WasmModule* module,
    const char* moduleName,
    const bool pretty,
    const bool multipleModules
) {
    U32 functionExportCount = 0;
    UNUSED_PARAMETER(pretty);

    {
        U32 exportIndex = 0;
        for (; exportIndex < module->exports.count; exportIndex++) {
            const WasmExport export = module->exports.exports[exportIndex];
            if (export.kind == wasmExportKindFunction) {
                functionExportCount += 1;
            }
        }
    }

    wasmOutputString(file, "wasmFuncExport ");
    wasmOutputString(file, moduleName);
    wasmOutputString(file, "FuncExports[");
    wasmOutputU32(file, functionExportCount + 1);
    wasmOutputString(file, "] = {\n");

    {
        U32 exportIndex = 0;
        for (; exportIndex < module->exports.count; exportIndex++) {
            const WasmExport export = module->exports.exports[exportIndex];
            if (export.kind != wasmExportKindFunction) {
                continue;
            }

            wasmOutputString(file, "{(wasmFunc)");
            wasmCWriteFunctionUse(
                file,
                module,
                moduleName,
                export.index,
                false,
                multipleModules
            );
            wasmOutputString(file, ",\"");
            wasmOutputString(file, export.name);
            wasmOutputString(file, "\"},\n");
        }
    }

    wasmOutputString(file, "{NULL,NULL}\n};\n\n");

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteInits(
    const WasmModule* module,
    const char* moduleName,
    WasmOutput* file,
    const WasmDataSegmentMode dataSegmentMode,
    const bool pretty,
    const bool multipleModules,
    WasmDiagnosticContext* diagnostics
) {
    MUST (wasmCWriteModuleFunctionExportsArray(file, module, moduleName, pretty, multipleModules))

    MUST (wasmCWriteInitMemories(file, module, moduleName, dataSegmentMode, pretty, diagnostics))
    MUST (wasmCWriteInitTables(file, module, moduleName, pretty, multipleModules, diagnostics))
    MUST (wasmCWriteInitGlobals(file, module, moduleName, pretty, diagnostics))
    MUST (wasmCWriteInitImports(file, module, moduleName, pretty))

    MUST (wasmCWriteExports(file, module, moduleName, true, pretty, multipleModules, diagnostics))

    wasmCWriteFreeChildFunction(file, module, moduleName, pretty);
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
    const bool multipleModules,
    WasmOutputProvider provider,
    WasmDiagnosticContext* diagnostics
) {
    WasmOutput output;
    WasmOutput* file = &output;
    char filename[W2C2_IMPL_FILENAME_LENGTH+1];
    const U32 functionCount = (U32)functionIDs.length;
    bool result = false;

    U32 endFunctionIDIndex = startFunctionIDIndex + (U32)functionsPerFile;
    if (endFunctionIDIndex > functionCount) {
        endFunctionIDIndex = functionCount;
    }

    /* Do not create empty files */
    if (startFunctionIDIndex > endFunctionIDIndex) {
        return true;
    }

    sprintf(filename, "%c%010u.c", filePrefix, fileIndex);
    diagnostics->location.outputName = filename;
    diagnostics->location.hasFunctionIndex = false;
    if (!wasmOutputOpen(file, provider, filename, wasmOutputC, diagnostics)) {
        return false;
    }

    wasmCWriteIncludes(file, headerName);

    MUST_OR_GOTO (cleanup, wasmCWriteFunctionImplementations(
        file,
        module,
        moduleName,
        debugLines,
        startFunctionIDIndex,
        endFunctionIDIndex,
        functionIDs,
        pretty,
        debug,
        multipleModules,
        diagnostics
    ))

    result = true;

cleanup:
    diagnostics->location.hasFunctionIndex = false;
    diagnostics->location.outputName = filename;
    if (!result) {
        wasmOutputAbort(file);
        return false;
    }
    return wasmOutputClose(file);
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
    WasmDebugLines debugLines;
} WasmCImplementationWriterTask;

typedef struct WasmCImplementationConcurrentWriter {
    WasmDiagnostics diagnostics;
    WasmOutputProvider output;
    pthread_mutex_t mutex;
    pthread_cond_t consume;
    pthread_cond_t produce;
    WasmCImplementationWriterTask* task;
    bool done;
    bool failed;
} WasmCImplementationConcurrentWriter;

static
bool
WARN_UNUSED_RESULT
wasmCImplementationConcurrentWriterInitialize(
    WasmCImplementationConcurrentWriter* writer,
    WasmDiagnosticContext* diagnostics
) {
    int err = pthread_mutex_init(&writer->mutex, NULL);
    writer->diagnostics = diagnostics->diagnostics;
    if (err != 0) {
        wasmDiagnosticReportThreadFailed(diagnostics, wasmDiagnosticThreadMutexInitialize, err);
        return false;
    }

    err = pthread_cond_init(&writer->consume, NULL);
    if (err != 0) {
        wasmDiagnosticReportThreadFailed(diagnostics, wasmDiagnosticThreadConditionInitialize, err);
        pthread_mutex_destroy(&writer->mutex);
        return false;
    }

    err = pthread_cond_init(&writer->produce, NULL);
    if (err != 0) {
        wasmDiagnosticReportThreadFailed(diagnostics, wasmDiagnosticThreadConditionInitialize, err);
        pthread_cond_destroy(&writer->consume);
        pthread_mutex_destroy(&writer->mutex);
        return false;
    }

    writer->task = NULL;
    writer->done = false;
    writer->failed = false;
    return true;
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
    WasmDiagnosticContext threadDiagnostics = emptyWasmDiagnosticContext;
    WasmDiagnosticContext* diagnostics = &threadDiagnostics;
    diagnostics->diagnostics = writer->diagnostics;

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
            WasmDebugLines debugLines = task->debugLines;

            writer->task = NULL;

            pthread_mutex_unlock(&writer->mutex);

            {
                const bool result = wasmCWriteImplementationFile(
                    module,
                    moduleName,
                    headerName,
                    &debugLines,
                    filePrefix,
                    fileIndex,
                    functionsPerFile,
                    startFunctionIDIndex,
                    functionIDs,
                    pretty,
                    debug,
                    multipleModules,
                    writer->output,
                    diagnostics
                );
                if (!result) {
                    if (!diagnostics->hasError) {
                        wasmDiagnosticReportTranslationFailed(diagnostics);
                    }

                    pthread_mutex_lock(&writer->mutex);
                    writer->failed = true;
                    writer->done = true;
                    pthread_cond_broadcast(&writer->consume);
                    pthread_cond_broadcast(&writer->produce);
                    pthread_mutex_unlock(&writer->mutex);
                    return NULL;
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
    WasmCWriteModuleOptions options,
    WasmDiagnosticContext* diagnostics
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

#if HAS_PTHREAD
    {
        U32 threadCount = options.threadCount;
        pthread_t* threads = NULL;
        U32 createdThreadCount = 0;
        U32 jobIndex = 0;
        bool result = true;
        WasmCImplementationConcurrentWriter writer;
        WasmCImplementationWriterTask task;

        if (threadCount == 0) {
            threadCount = 1;
        }
        if (!wasmCImplementationConcurrentWriterInitialize(&writer, diagnostics)) {
            return false;
        }

        writer.output = options.output;

        threads = calloc(threadCount, sizeof(pthread_t));
        if (threads == NULL) {
            wasmDiagnosticReportAllocationFailed(diagnostics);
            wasmCImplementationConcurrentWriterDestroy(&writer);
            return false;
        }

        task.functionsPerFile = functionsPerFile;
        task.module = module;
        task.moduleName = moduleName;
        task.headerName = headerName;
        task.pretty = options.pretty;
        task.debug = options.debug;
        task.multipleModules = options.multipleModules;

        for (; createdThreadCount < threadCount; createdThreadCount++) {
            int err = pthread_create(
                &threads[createdThreadCount],
                NULL,
                wasmCImplementationWriterThread,
                &writer
            );
            if (err) {
                wasmDiagnosticReportThreadFailed(diagnostics, wasmDiagnosticThreadCreate, err);
                result = false;
                goto finish;
            }
        }

        for (; fileIndex < fileCount; fileIndex++) {
            const U32 startFunctionIDIndex = fileIndex * functionsPerFile;
            pthread_mutex_lock(&writer.mutex);

            while (!writer.failed && writer.task != NULL) {
                pthread_cond_wait(
                    &writer.produce,
                    &writer.mutex
                );
            }

            if (writer.failed) {
                pthread_mutex_unlock(&writer.mutex);
                result = false;
                break;
            }

            task.filePrefix = filePrefix;
            task.fileIndex = fileIndex;
            task.startFunctionIDIndex = startFunctionIDIndex;
            task.functionIDs = functionIDs;
            if (options.debug && debugLines.length > 0) {
                const WasmFunctionID startFunctionID =
                    functionIDs.functionIDs[startFunctionIDIndex];
                const WasmFunction startFunction =
                    module->functions.functions[startFunctionID.functionIndex];
                task.debugLines = wasmCDebugLinesAtAddress(
                    debugLines,
                    startFunction.start
                );
            } else {
                task.debugLines = emptyWasmDebugLines;
            }

            writer.task = &task;

            pthread_cond_signal(&writer.consume);
            pthread_mutex_unlock(&writer.mutex);
        }

finish:
        pthread_mutex_lock(&writer.mutex);

        while (!writer.failed && writer.task != NULL) {
            pthread_cond_wait(
                &writer.produce,
                &writer.mutex
            );
        }

        if (writer.failed) {
            result = false;
        }
        writer.done = true;
        pthread_cond_broadcast(&writer.consume);
        pthread_mutex_unlock(&writer.mutex);

        for (jobIndex = 0; jobIndex < createdThreadCount; jobIndex++) {
            int err = pthread_join(threads[jobIndex], NULL);
            if (err != 0) {
                wasmDiagnosticReportThreadFailed(diagnostics, wasmDiagnosticThreadJoin, err);
                result = false;
            }
        }

        if (writer.failed) {
            diagnostics->hasError = true;
            result = false;
        }

        free(threads);
        wasmCImplementationConcurrentWriterDestroy(&writer);
        return result;
    }
#else
    for (; fileIndex < fileCount; fileIndex++) {
        const U32 startFunctionIDIndex = fileIndex * functionsPerFile;
        if (!wasmCWriteImplementationFile(
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
            options.multipleModules,
            options.output,
            diagnostics
        )) {
            return false;
        }
    }
#endif /* HAS_PTHREAD */

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
    const WasmCWriteModuleOptions options,
    WasmDiagnosticContext* diagnostics
) {
    /* Create file */
    WasmOutput output;
    WasmOutput* file = &output;
    bool result = false;

    diagnostics->location.outputName = filename;
    diagnostics->location.hasFunctionIndex = false;
    if (!wasmOutputOpen(file, options.output, filename, wasmOutputC, diagnostics)) {
        return false;
    }

    wasmCWriteIncludes(file, headerName);

    switch (options.dataSegmentMode) {
        case wasmDataSegmentModeGNULD:
        case wasmDataSegmentModeSectcreate1:
        case wasmDataSegmentModeSectcreate2: {
            MUST_OR_GOTO (cleanup, wasmCWriteDataSegmentsFromSection(
                file,
                module,
                options.dataSegmentMode,
                diagnostics
            ))
            break;
        }
        case wasmDataSegmentModeArrays: {
            /* NO-OP */
            break;
        }
        default: {
            wasmDiagnosticReportInvalidDataSegmentMode(diagnostics, options.dataSegmentMode);
            goto cleanup;
        }
    }

    diagnostics->location.outputName = filename;

    MUST_OR_GOTO (cleanup, wasmCWriteDataSegments(
        file, module,
        options.dataSegmentMode,
        options.pretty,
        diagnostics
    ))

    /* Write implementations */

    if (file->failed) {
        goto cleanup;
    }

    if (options.functionsPerFile >= module->functions.count
        && dynamicFunctionIDs.length == 0)
    {
        WasmDebugLines debugLines = module->debugLines;

        MUST_OR_GOTO (cleanup, wasmCWriteFunctionImplementations(
            file,
            module,
            moduleName,
            &debugLines,
            0,
            (U32)staticFunctionIDs.length,
            staticFunctionIDs,
            options.pretty,
            options.debug,
            options.multipleModules,
            diagnostics
        ))
    } else {

        MUST_OR_GOTO (cleanup, wasmCWriteModuleImplementationFiles(
            module,
            moduleName,
            headerName,
            staticFunctionIDs,
            's',
            options,
            diagnostics
        ))

        MUST_OR_GOTO (cleanup, wasmCWriteModuleImplementationFiles(
            module,
            moduleName,
            headerName,
            dynamicFunctionIDs,
            'd',
            options,
            diagnostics
        ))
    }

    diagnostics->location.outputName = filename;
    diagnostics->location.hasFunctionIndex = false;

    if (file->failed) {
        goto cleanup;
    }

    /* Write initializations code */

    MUST_OR_GOTO (cleanup, wasmCWriteInits(
        module,
        moduleName,
        file,
        options.dataSegmentMode,
        options.pretty,
        options.multipleModules,
        diagnostics
    ))

    result = true;

cleanup:
    diagnostics->location.hasFunctionIndex = false;
    diagnostics->location.outputName = filename;
    if (!result) {
        wasmOutputAbort(file);
        return false;
    }
    return wasmOutputClose(file);
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteModuleInternal(
    const WasmModule* module,
    const char* moduleName,
    const WasmCWriteModuleOptions options,
    const WasmFunctionIDs staticFunctionIDs,
    const WasmFunctionIDs dynamicFunctionIDs,
    WasmDiagnosticContext* diagnostics
) {
    const char* outputName = options.outputName;
    char* headerName;
    size_t nameLength;
    bool result = false;

    if (module == NULL || moduleName == NULL || outputName == NULL
        || outputName[0] == '\0' || options.output.open == NULL
        || strchr(outputName, '/') != NULL || strchr(outputName, '\\') != NULL) {
        wasmDiagnosticReportInvalidWriterArgument(diagnostics);
        return false;
    }

    switch (options.dataSegmentMode) {
        case wasmDataSegmentModeArrays:
        case wasmDataSegmentModeGNULD:
        case wasmDataSegmentModeSectcreate1:
        case wasmDataSegmentModeSectcreate2:
            break;
        default:
            wasmDiagnosticReportInvalidDataSegmentMode(diagnostics, options.dataSegmentMode);
            return false;
    }

    nameLength = strlen(outputName);
    if (nameLength > (size_t)-1 - 3) {
        wasmDiagnosticReportInvalidWriterArgument(diagnostics);
        return false;
    }
    headerName = (char*)malloc(nameLength + 3);
    if (headerName == NULL) {
        wasmDiagnosticReportAllocationFailed(diagnostics);
        return false;
    }
    strcpy(headerName, outputName);

    {
        char* headerExt = strrchr(headerName, '.');
        if (headerExt == NULL) {
            headerExt = headerName + strlen(headerName);
        }
        strcpy(headerExt, ".h");
    }

    MUST_OR_GOTO (cleanup, wasmCWriteModuleHeader(
        module,
        moduleName,
        headerName,
        options.pretty,
        options.debug,
        options.multipleModules,
        options.output,
        diagnostics
    ))

    MUST_OR_GOTO (cleanup, wasmCWriteModuleImplementation(
        module,
        moduleName,
        outputName,
        headerName,
        staticFunctionIDs,
        dynamicFunctionIDs,
        options,
        diagnostics
    ))

    result = true;

cleanup:
    free(headerName);
    diagnostics->location.outputName = NULL;
    return result;
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
    WasmDiagnosticContext diagnostics = emptyWasmDiagnosticContext;
    bool result;
    diagnostics.diagnostics = options.diagnostics;
    result = wasmCWriteModuleInternal(
        module, moduleName, options,
        staticFunctionIDs, dynamicFunctionIDs, &diagnostics
    );
    if (!result && !diagnostics.hasError) {
        memset(&diagnostics.location, 0, sizeof(diagnostics.location));
        wasmDiagnosticReportTranslationFailed(&diagnostics);
    }
    return result;
}
