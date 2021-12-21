#include <stdio.h>
#include "c.h"
#include "stringbuilder.h"
#include "instruction.h"
#include "typestack.h"
#include "labelstack.h"
#include <ctype.h>
#include <stdlib.h>

static const char* functionNamePrefix = "f";
static const char* localNamePrefix = "l";
static const char* globalNamePrefix = "g";
static const char* memoryNamePrefix = "m";
static const char* dataSegmentNamePrefix = "d";
static const char* tableNamePrefix = "t";
static const char* stackNamePrefix = "s";
static const char* labelNamePrefix = "L";

static const char* valueTypeNames[wasmValueType_count] = {
    "U32", "U64", "F32", "F64"
};

static const char* signedTypeNames[2] = {
    "I32", "I64"
};

static const char* shiftMaskStrings[2] = {
    "31", "63"
};

static const char* valueTypeStackNames[wasmValueType_count] = {
    "i", "j", "f", "d"
};

__inline__
static
void
wasmCWriteFileLocalName(
    FILE* file,
    const U32 localIndex
) {
    fprintf(file, "%s%u", localNamePrefix, localIndex);
}

__inline__
static
void
wasmCWriteFileEscaped(
    FILE* file,
    const char* name
) {
    static const char escapeChar = 'X';
    const char* p = name;
    for (; *p != '\0'; p++) {
        char c = *p;
        if (isalnum(c) && c != escapeChar) {
            fputc(c, file);
        } else {
            fprintf(file, "%c%02X", escapeChar, c);
        }
    }
}

__inline__
static
bool
WARN_UNUSED_RESULT
wasmCWriteStringEscaped(
    StringBuilder* builder,
    const char* name
) {
    static const char escapeChar = 'X';
    const char* p = name;
    for (; *p != '\0'; p++) {
        char c = *p;
        if (isalnum(c) && c != escapeChar) {
            MUST (stringBuilderAppendChar(builder, c))
        } else {
            MUST (stringBuilderAppendChar(builder, escapeChar))
            MUST (stringBuilderAppendCharHex(builder, c))
        }
    }
    return true;
}

__inline__
static
void
wasmCWriteFileGlobalName(
    FILE* file,
    const WasmModule* module,
    U32 globalIndex,
    bool reference
) {
    if (globalIndex < module->globalImports.length) {
        WasmGlobalImport globalImport = module->globalImports.imports[globalIndex];
        if (!reference) {
            fputs("(*", file);
        }
        fputs(globalNamePrefix, file);
        fputc('_', file);
        wasmCWriteFileEscaped(file, globalImport.module);
        fputc('_', file);
        wasmCWriteFileEscaped(file, globalImport.name);
        if (!reference) {
            fputc(')', file);
        }
    } else {
        if (reference) {
            fputc('&', file);
        }
        fputs(globalNamePrefix, file);
        fprintf(file, "%u", globalIndex);
    }
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteStringGlobalName(
    StringBuilder* builder,
    const WasmModule* module,
    U32 globalIndex,
    bool reference
) {
    if (globalIndex < module->globalImports.length) {
        WasmGlobalImport globalImport = module->globalImports.imports[globalIndex];
        if (!reference) {
            MUST (stringBuilderAppend(builder, "(*"))
        }
        MUST (stringBuilderAppend(builder, globalNamePrefix))
        MUST (stringBuilderAppendChar(builder, '_'))
        MUST (wasmCWriteStringEscaped(builder, globalImport.module))
        MUST (stringBuilderAppendChar(builder, '_'))
        MUST (wasmCWriteStringEscaped(builder, globalImport.name))
        if (!reference) {
            MUST (stringBuilderAppendChar(builder, ')'))
        }
    } else {
        if (reference) {
            MUST (stringBuilderAppendChar(builder, '&'))
        }
        MUST (stringBuilderAppend(builder, globalNamePrefix))
        MUST (stringBuilderAppendI64(builder, globalIndex))
    }
    return true;
}

__inline__
static
void
wasmCWriteFileMemoryName(
    FILE* file,
    const WasmModule* module,
    U32 memoryIndex,
    bool reference
) {
    if (memoryIndex < module->memoryImports.length) {
        WasmMemoryImport memoryImport = module->memoryImports.imports[memoryIndex];
        if (!reference) {
            fputs("(*", file);
        }
        fputs(memoryNamePrefix, file);
        fputc('_', file);
        wasmCWriteFileEscaped(file, memoryImport.module);
        fputc('_', file);
        wasmCWriteFileEscaped(file, memoryImport.name);
        if (!reference) {
            fputc(')', file);
        }
    } else {
        if (reference) {
            fputc('&', file);
        }
        fputs(memoryNamePrefix, file);
        fprintf(file, "%u", memoryIndex);
    }
}

static
__inline__
bool
WARN_UNUSED_RESULT
wasmCWriteStringMemoryName(
    StringBuilder* builder,
    const WasmModule* module,
    U32 memoryIndex,
    bool reference
) {
    if (memoryIndex < module->memoryImports.length) {
        WasmMemoryImport memoryImport = module->memoryImports.imports[memoryIndex];
        if (!reference) {
            MUST (stringBuilderAppend(builder, "(*"))
        }
        MUST (stringBuilderAppend(builder, memoryNamePrefix))
        MUST (stringBuilderAppendChar(builder, '_'))
        MUST (wasmCWriteStringEscaped(builder, memoryImport.module))
        MUST (stringBuilderAppendChar(builder, '_'))
        MUST (wasmCWriteStringEscaped(builder, memoryImport.name))
        if (!reference) {
            MUST (stringBuilderAppendChar(builder, ')'))
        }
    } else {
        if (reference) {
            MUST (stringBuilderAppendChar(builder, '&'))
        }
        MUST (stringBuilderAppend(builder, memoryNamePrefix))
        MUST (stringBuilderAppendI64(builder, (I64) memoryIndex))
    }
    return true;
}

__inline__
static
void
wasmCWriteFileTableName(
    FILE* file,
    const WasmModule* module,
    U32 tableIndex,
    bool reference
) {
    if (tableIndex < module->tableImports.length) {
        WasmTableImport tableImport = module->tableImports.imports[tableIndex];
        if (!reference) {
            fputs("(*", file);
        }
        fputs(tableNamePrefix, file);
        fputc('_', file);
        wasmCWriteFileEscaped(file, tableImport.module);
        fputc('_', file);
        wasmCWriteFileEscaped(file, tableImport.name);
        if (!reference) {
            fputc(')', file);
        }
    } else {
        if (reference) {
            fputc('&', file);
        }
        fputs(tableNamePrefix, file);
        fprintf(file, "%u", tableIndex);
    }
}

static
__inline__
bool
WARN_UNUSED_RESULT
wasmCWriteStringTableName(
    StringBuilder* builder,
    const WasmModule* module,
    U32 tableIndex,
    bool reference
) {
    if (tableIndex < module->tableImports.length) {
        WasmTableImport tableImport = module->tableImports.imports[tableIndex];
        if (!reference) {
            MUST (stringBuilderAppend(builder, "(*"))
        }
        MUST (stringBuilderAppend(builder, tableNamePrefix))
        MUST (stringBuilderAppendChar(builder, '_'))
        MUST (wasmCWriteStringEscaped(builder, tableImport.module))
        MUST (stringBuilderAppendChar(builder, '_'))
        MUST (wasmCWriteStringEscaped(builder, tableImport.name))
        if (!reference) {
            MUST (stringBuilderAppendChar(builder, ')'))
        }
    } else {
        if (reference) {
            MUST (stringBuilderAppendChar(builder, '&'))
        }
        MUST (stringBuilderAppend(builder, tableNamePrefix))
        MUST (stringBuilderAppendI64(builder, (I64) tableIndex))
    }
    return true;
}

__inline__
static
void
wasmCWriteFileDataSegmentName(
    FILE* file,
    const U32 dataSegmentIndex
) {
    fputs(dataSegmentNamePrefix, file);
    fprintf(file, "%u", dataSegmentIndex);
}

static
__inline__
void
wasmCWriteFileFunctionName(
    FILE* file,
    const WasmModule* module,
    U32 functionIndex,
    bool reference
) {
    if (functionIndex < module->functionImports.length) {
        const WasmFunctionImport functionImport = module->functionImports.imports[functionIndex];
        if (!reference) {
            fputs("(*", file);
        }
        fputs(functionNamePrefix, file);
        fputc('_', file);
        wasmCWriteFileEscaped(file, functionImport.module);
        fputc('_', file);
        wasmCWriteFileEscaped(file, functionImport.name);
        if (!reference) {
            fputc(')', file);
        }
    } else {
        if (reference) {
            fputc('&', file);
        }
        fputs(functionNamePrefix, file);
        fprintf(file, "%u", functionIndex);
    }
}

static
__inline__
bool
WARN_UNUSED_RESULT
wasmCWriteStringFunctionName(
    StringBuilder* builder,
    const WasmModule* module,
    U32 functionIndex,
    bool reference
) {
    if (functionIndex < module->functionImports.length) {
        WasmFunctionImport functionImport = module->functionImports.imports[functionIndex];
        if (!reference) {
            MUST (stringBuilderAppend(builder, "(*"))
        }
        MUST (stringBuilderAppend(builder, functionNamePrefix))
        MUST (stringBuilderAppendChar(builder, '_'))
        MUST (wasmCWriteStringEscaped(builder, functionImport.module))
        MUST (stringBuilderAppendChar(builder, '_'))
        MUST (wasmCWriteStringEscaped(builder, functionImport.name))
        if (!reference) {
            MUST (stringBuilderAppendChar(builder, ')'))
        }
    } else {
        if (reference) {
            MUST (stringBuilderAppendChar(builder, '&'))
        }
        MUST (stringBuilderAppend(builder, functionNamePrefix))
        MUST (stringBuilderAppendI64(builder, (I64) functionIndex))
    }
    return true;
}

static
__inline__
void
wasmCWriteFileStackName(
    FILE* file,
    const U32 stackIndex,
    const WasmValueType valueType
) {
    fprintf(
        file,
        "%s%s%u",
        stackNamePrefix,
        valueTypeStackNames[valueType],
        stackIndex
    );
}

static
__inline__
bool
WARN_UNUSED_RESULT
wasmCWriteStringStackName(
    StringBuilder* builder,
    const U32 stackIndex,
    const WasmValueType localType
) {
    MUST (stringBuilderAppend(builder, stackNamePrefix))
    MUST (stringBuilderAppend(builder, valueTypeStackNames[localType]))
    MUST (stringBuilderAppendI64(builder, (I64) stackIndex))
    return true;
}

static
__inline__
bool
WARN_UNUSED_RESULT
wasmCWriteStringLocalName(
    StringBuilder* builder,
    const U32 localIndex
) {
    MUST (stringBuilderAppend(builder, localNamePrefix))
    MUST (stringBuilderAppendI64(builder, localIndex))
    return true;
}

static
__inline__
bool
WARN_UNUSED_RESULT
wasmCWriteStringLabelName(
    StringBuilder* builder,
    const U32 labelIndex
) {
    MUST (stringBuilderAppend(builder, labelNamePrefix))
    MUST (stringBuilderAppendI64(builder, (I64) labelIndex))
    return true;
}

static
__inline__
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
            fprintf(stderr, "ERROR: function with multiple result values\n");
            abort();
    }
}

static
void
wasmCWriteFileFunctionSignature(
    FILE* file,
    const WasmModule* module,
    const WasmFunction function,
    const U32 functionIndex
) {
    const WasmFunctionType functionType =
        module->functionTypes.functionTypes[function.functionTypeIndex];

    fputs("static ", file);
    fputs(wasmCGetReturnType(functionType), file);
    fputs(" ", file);
    wasmCWriteFileFunctionName(file, module, functionIndex, false);
    fputs("(", file);
    {
        U32 parameterIndex = 0;
        for (; parameterIndex < functionType.parameterCount; parameterIndex++) {
            const WasmValueType parameterType = functionType.parameterTypes[parameterIndex];
            if (parameterIndex > 0) {
                fputs(", ", file);
            }
            {
                const char* parameterTypeName = valueTypeNames[parameterType];
                fputs(parameterTypeName, file);
            }
            fputs(" ", file);
            wasmCWriteFileLocalName(file, parameterIndex);
        }
    }
    fputs(")", file);
}

static
void
wasmCWriteFileLocalsDeclarations(
    FILE* file,
    const WasmModule* module,
    const WasmFunction function
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
            fputs("    ", file);
            fputs(valueTypeNames[localsDeclaration.type], file);
            fputs(" ", file);
            wasmCWriteFileLocalName(file, parameterCount + localIndex);
            fputs(" = 0;\n", file);
        }
    }
}

typedef struct WasmCFunctionWriter {
    StringBuilder* builder;
    WasmTypeStack* typeStack;
    WasmTypeStack* stackDeclarations;
    WasmLabelStack* labelStack;
    const WasmModule* module;
    WasmFunction function;
    Buffer* code;
    U32 indent;
    bool ignore;
} WasmCFunctionWriter;

static
__inline__
bool
WARN_UNUSED_RESULT
wasmCWriteIndent(
    WasmCFunctionWriter* writer
) {
    StringBuilder* builder = writer->builder;
    const U32 indent = writer->indent;
    U32 index = 0;
    for (; index <= indent; index++) {
        MUST (stringBuilderAppend(builder, "    "))
    }
    return true;
}

static
__inline__
bool
WARN_UNUSED_RESULT
wasmCWrite(
    WasmCFunctionWriter* writer,
    const char* string
) {
    return stringBuilderAppend(writer->builder, string);
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
    WasmCFunctionWriter* writer
) {
    static const WasmOpcode opcode = wasmOpcodeCall;
    WasmCallInstruction instruction;
    if (!wasmCallInstructionRead(writer->code, opcode, &instruction)) {
        fprintf(
            stderr,
            "ERROR: invalid %s instruction encoding\n",
            wasmOpcodeDescription(opcode)
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

                U32 resultStackIndex = writer->typeStack->length;
                if (parameterCount > 0) {
                    resultStackIndex -= parameterCount;
                }

                MUST (wasmTypeStackSet(writer->stackDeclarations, resultStackIndex, resultType))
                MUST (wasmCWriteStringStackName(writer->builder, resultStackIndex, resultType))
                MUST (wasmCWrite(writer, " = "))
            }

            MUST (wasmCWriteStringFunctionName(writer->builder, writer->module, instruction.funcIndex, false))

            MUST (wasmCWrite(writer, "("))
            {
                U32 parameterIndex = 0;
                for (; parameterIndex < parameterCount; parameterIndex++) {
                    const WasmValueType parameterType = functionType.parameterTypes[parameterIndex];
                    U32 paramStackIndex = wasmTypeStackGetTopIndex(
                        writer->typeStack,
                        parameterCount - parameterIndex - 1
                    );
                    if (parameterIndex > 0) {
                        MUST (wasmCWrite(writer, ", "))
                    }
                    MUST (wasmCWriteStringStackName(writer->builder, paramStackIndex, parameterType))
                }
            }
            MUST (wasmCWrite(writer, ");\n"))

            wasmTypeStackDrop(writer->typeStack, parameterCount);
            {
                U32 resultIndex = 0;
                for (; resultIndex < resultCount; resultIndex++) {
                    const WasmValueType resultType = functionType.resultTypes[resultIndex];
                    MUST (wasmTypeStackPush(writer->typeStack, resultType))
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
    WasmCFunctionWriter* writer,
    WasmFunctionType functionType
) {
    MUST (wasmCWrite(writer, "("))
    {
        U32 parameterIndex = 0;
        for (; parameterIndex < functionType.parameterCount; parameterIndex++) {
            const WasmValueType parameterType = functionType.parameterTypes[parameterIndex];
            if (parameterIndex > 0) {
                MUST (wasmCWrite(writer, ", "))
            }
            MUST (wasmCWrite(writer, valueTypeNames[parameterType]))
        }
    }
    MUST (wasmCWrite(writer, ")"))

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteCallIndirectExpr(
    WasmCFunctionWriter* writer
) {
    static const WasmOpcode opcode = wasmOpcodeCallIndirect;
    WasmCallIndirectInstruction instruction;
    if (!wasmCallIndirectInstructionRead(writer->code, opcode, &instruction)) {
        fprintf(
            stderr,
            "ERROR: invalid %s instruction encoding\n",
            wasmOpcodeDescription(opcode)
        );
        return false;
    }

    if (!writer->ignore) {
        WasmFunctionType functionType = writer->module->functionTypes.functionTypes[instruction.functionTypeIndex];

        const U32 parameterCount = functionType.parameterCount;
        const U32 resultCount = functionType.resultCount;

        MUST (wasmCWriteIndent(writer))

        if (resultCount > 0) {
            /* TODO: add support for multiple result values */
            const WasmValueType resultType = functionType.resultTypes[0];

            U32 resultStackIndex = writer->typeStack->length - 1;
            if (parameterCount > 0) {
                resultStackIndex -= parameterCount;
            }

            MUST (wasmTypeStackSet(writer->stackDeclarations, resultStackIndex, resultType))
            MUST (wasmCWriteStringStackName(writer->builder, resultStackIndex, resultType))
            MUST (wasmCWrite(writer, " = "))
        }

        MUST (wasmCWrite(writer, "TF("))
        MUST (wasmCWriteStringTableName(writer->builder, writer->module, instruction.tableIndex, false))
        MUST (wasmCWrite(writer, ", "))

        {
            const U32 stackIndex0 = wasmTypeStackGetTopIndex(writer->typeStack, 0);
            MUST (wasmCWriteStringStackName(
                writer->builder,
                stackIndex0,
                writer->typeStack->valueTypes[stackIndex0]
            ))
        }

        MUST (wasmCWrite(writer, ", "))
        MUST (wasmCWrite(writer, wasmCGetReturnType(functionType)))
        MUST (wasmCWrite(writer, " (*)"))

        MUST (wasmCWriteParameters(writer, functionType))

        MUST (wasmCWrite(writer, ")("))

        {
            U32 parameterIndex = 0;
            for (; parameterIndex < parameterCount; parameterIndex++) {
                const WasmValueType parameterType = functionType.parameterTypes[parameterIndex];
                U32 paramStackIndex = wasmTypeStackGetTopIndex(
                    writer->typeStack,
                    parameterCount - parameterIndex
                );
                if (parameterIndex > 0) {
                    MUST (wasmCWrite(writer, ", "))
                }
                MUST (wasmCWriteStringStackName(writer->builder, paramStackIndex, parameterType))
            }
        }
        MUST (wasmCWrite(writer, ");\n"))

        wasmTypeStackDrop(writer->typeStack, parameterCount + 1);
        {
            U32 resultIndex = 0;
            for (; resultIndex < resultCount; resultIndex++) {
                const WasmValueType resultType = functionType.resultTypes[resultIndex];
                MUST (wasmTypeStackPush(writer->typeStack, resultType))
            }
        }
    }

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteLocalGetExpr(
    WasmCFunctionWriter* writer
) {
    static const WasmOpcode opcode = wasmOpcodeLocalGet;
    WasmLocalInstruction instruction;
    if (!wasmLocalInstructionRead(writer->code, opcode, &instruction)) {
        fprintf(
            stderr,
            "ERROR: invalid %s instruction encoding\n",
            wasmOpcodeDescription(opcode)
        );
        return false;
    }

    if (!writer->ignore) {
        WasmValueType localType = 0;
        bool gotType = wasmModuleFunctionGetLocalType(
            writer->module,
            writer->function,
            instruction.localIndex,
            &localType
        );
        if (!gotType) {
            fprintf(
                stderr,
                "ERROR: invalid %s instruction: invalid local index: %u\n",
                wasmOpcodeDescription(opcode),
                instruction.localIndex
            );
            return false;
        }
        MUST (wasmTypeStackPush(writer->typeStack, localType))
        {
            U32 stackIndex0 = wasmTypeStackGetTopIndex(writer->typeStack, 0);
            MUST (wasmTypeStackSet(writer->stackDeclarations, stackIndex0, localType))

            MUST (wasmCWriteIndent(writer))
            MUST (wasmCWriteStringStackName(writer->builder, stackIndex0, localType))
            MUST (wasmCWrite(writer, " = "))
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
    WasmCFunctionWriter* writer,
    const WasmOpcode opcode
) {
    WasmLocalInstruction instruction;
    if (!wasmLocalInstructionRead(writer->code, opcode, &instruction)) {
        fprintf(
            stderr,
            "ERROR: invalid %s instruction encoding\n",
            wasmOpcodeDescription(opcode)
        );
        return false;
    }

    if (!writer->ignore) {
        WasmValueType localType = 0;
        bool gotType = wasmModuleFunctionGetLocalType(
            writer->module,
            writer->function,
            instruction.localIndex,
            &localType
        );
        if (!gotType) {
            fprintf(
                stderr,
                "ERROR: invalid %s instruction: invalid local index: %u\n",
                wasmOpcodeDescription(opcode),
                instruction.localIndex
            );
            return false;
        }
        {
            U32 stackIndex0 = wasmTypeStackGetTopIndex(writer->typeStack, 0);
            MUST (wasmTypeStackSet(writer->stackDeclarations, stackIndex0, localType))

            MUST(wasmCWriteIndent(writer))
            MUST(wasmCWriteStringLocalName(writer->builder, instruction.localIndex))
            MUST(wasmCWrite(writer, " = "))
            MUST(wasmCWriteStringStackName(writer->builder, stackIndex0, localType))
            MUST(wasmCWrite(writer, ";\n"))
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
    WasmCFunctionWriter* writer
) {
    static const WasmOpcode opcode = wasmOpcodeGlobalGet;
    WasmGlobalInstruction instruction;
    if (!wasmGlobalInstructionRead(writer->code, opcode, &instruction)) {
        fprintf(
            stderr,
            "ERROR: invalid %s instruction encoding\n",
            wasmOpcodeDescription(opcode)
        );
        return false;
    }

    if (!writer->ignore) {
        WasmValueType globalType = 0;
        bool gotType = wasmModuleGetGlobalType(
            writer->module,
            instruction.globalIndex,
            &globalType
        );
        if (!gotType) {
            fprintf(
                stderr,
                "ERROR: invalid %s instruction: invalid global index: %u\n",
                wasmOpcodeDescription(opcode),
                instruction.globalIndex
            );
            return false;
        }
        MUST (wasmTypeStackPush(writer->typeStack, globalType))
        {
            U32 stackIndex0 = wasmTypeStackGetTopIndex(writer->typeStack, 0);
            MUST (wasmTypeStackSet(writer->stackDeclarations, stackIndex0, globalType))

            MUST (wasmCWriteIndent(writer))
            MUST (wasmCWriteStringStackName(writer->builder, stackIndex0, globalType))
            MUST (wasmCWrite(writer, " = "))
            MUST (wasmCWriteStringGlobalName(writer->builder, writer->module, instruction.globalIndex, false))
            MUST (wasmCWrite(writer, ";\n"))
        }
    }

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteGlobalSetExpr(
    WasmCFunctionWriter* writer
) {
    static const WasmOpcode opcode = wasmOpcodeGlobalSet;
    WasmGlobalInstruction instruction;
    if (!wasmGlobalInstructionRead(writer->code, opcode, &instruction)) {
        fprintf(
            stderr,
            "ERROR: invalid %s instruction encoding\n",
            wasmOpcodeDescription(opcode)
        );
        return false;
    }

    if (!writer->ignore) {
        WasmValueType globalType = 0;
        bool gotType = wasmModuleGetGlobalType(
            writer->module,
            instruction.globalIndex,
            &globalType
        );
        if (!gotType) {
            fprintf(
                stderr,
                "ERROR: invalid %s instruction: invalid global index: %u\n",
                wasmOpcodeDescription(opcode),
                instruction.globalIndex
            );
            return false;
        }
        {
            U32 stackIndex0 = wasmTypeStackGetTopIndex(writer->typeStack, 0);
            MUST (wasmTypeStackSet(writer->stackDeclarations, stackIndex0, globalType))

            MUST(wasmCWriteIndent(writer))
            MUST(wasmCWriteStringGlobalName(writer->builder, writer->module, instruction.globalIndex, false))
            MUST(wasmCWrite(writer, " = "))
            MUST(wasmCWriteStringStackName(writer->builder, stackIndex0, globalType))
            MUST(wasmCWrite(writer, ";\n"))
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
    WasmValueType valueType,
    WasmValue value
) {
    switch (valueType) {
        case wasmValueTypeI32: {
            MUST (stringBuilderAppendI64(builder, value.i32))
            MUST (stringBuilderAppend(builder, "u"))
            break;
        }
        case wasmValueTypeI64: {
            MUST (stringBuilderAppendI64(builder, value.i64))
            MUST (stringBuilderAppend(builder, "ull"))
            break;
        }
        case wasmValueTypeF32: {
            U32 bits = (U32) value.i32;
            if ((bits & 0x7f800000u) == 0x7f800000u) {
                const char* sign = (bits & 0x80000000) ? "-" : "";
                U32 significand = bits & 0x7fffffu;
                if (significand == 0) {
                    MUST (stringBuilderAppend(builder, sign))
                    MUST (stringBuilderAppend(builder, "INFINITY"))
                } else {
                    MUST (stringBuilderAppend(builder, "f32_reinterpret_i32(0x"))
                    MUST (stringBuilderAppendU32Hex(builder, bits))
                    MUST (stringBuilderAppend(builder, ")"))
                }
            } else if (bits == 0x80000000) {
                MUST (stringBuilderAppend(builder, "-0.f"))
            } else {
                MUST (stringBuilderAppendF32(builder, value.f32))
            }
            break;
        }
        case wasmValueTypeF64: {
            U64 bits = (U64) value.i64;
            if ((bits & 0x7ff0000000000000ull) == 0x7ff0000000000000ull) {
                const char* sign = (bits & 0x8000000000000000ull) ? "-" : "";
                U64 significand = bits & 0x7fffffu;
                if (significand == 0) {
                    MUST (stringBuilderAppend(builder, sign))
                    MUST (stringBuilderAppend(builder, "INFINITY"))
                } else {
                    MUST (stringBuilderAppend(builder, "f64_reinterpret_i64(0x"))
                    MUST (stringBuilderAppendU64Hex(builder, bits))
                    MUST (stringBuilderAppend(builder, ")"))
                }
            } else if (bits == 0x8000000000000000ull) {
                MUST (stringBuilderAppend(builder, "-0.f"))
            } else {
                MUST (stringBuilderAppendF64(builder, value.f64))
            }
            break;
        }
        default:
            fprintf(stderr, "ERROR: unsupported const type %s\n", wasmValueTypeDescription(valueType));
            return false;
    }

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteConstExpr(
    WasmCFunctionWriter* writer,
    const WasmOpcode opcode
) {
    WasmConstInstruction instruction;
    if (!wasmConstInstructionRead(writer->code, opcode, &instruction)) {
        fprintf(stderr, "ERROR: invalid const instruction\n");
        return false;
    }

    if (!writer->ignore) {
        const WasmValueType resultType = wasmOpcodeResultType(opcode);
        MUST (wasmTypeStackPush(writer->typeStack, resultType))
        {
            const U32 stackIndex0 = wasmTypeStackGetTopIndex(writer->typeStack, 0);
            MUST (wasmTypeStackSet(writer->stackDeclarations, stackIndex0, resultType))
            MUST (wasmCWriteIndent(writer))
            MUST (wasmCWriteStringStackName(writer->builder, stackIndex0, resultType))
            MUST (wasmCWrite(writer, " = "))
            MUST (wasmCWriteLiteral(writer->builder, resultType, instruction.value))
            MUST (wasmCWrite(writer, ";\n"))
        }
    }

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteLoadExpr(
    WasmCFunctionWriter* writer,
    const WasmOpcode opcode
) {
    WasmLoadStoreInstruction instruction;
    if (!wasmLoadStoreInstructionRead(writer->code, opcode, &instruction)) {
        fprintf(stderr, "ERROR: invalid load instruction\n");
        return false;
    }

    if (!writer->ignore) {

        const char* functionName = NULL;
        switch (opcode) {
            case wasmOpcodeI32Load: {
                functionName = "i32_load";
                break;
            }
            case wasmOpcodeI64Load: {
                functionName = "i64_load";
                break;
            }
            case wasmOpcodeF32Load: {
                functionName = "f32_load";
                break;
            }
            case wasmOpcodeF64Load: {
                functionName = "f64_load";
                break;
            }
            case wasmOpcodeI32Load8S: {
                functionName = "i32_load8_s";
                break;
            }
            case wasmOpcodeI64Load8S: {
                functionName = "i64_load8_s";
                break;
            }
            case wasmOpcodeI32Load8U: {
                functionName = "i32_load8_u";
                break;
            }
            case wasmOpcodeI64Load8U: {
                functionName = "i64_load8_u";
                break;
            }
            case wasmOpcodeI32Load16S: {
                functionName = "i32_load16_s";
                break;
            }
            case wasmOpcodeI64Load16S: {
                functionName = "i64_load16_s";
                break;
            }
            case wasmOpcodeI32Load16U: {
                functionName = "i32_load16_u";
                break;
            }
            case wasmOpcodeI64Load16U: {
                functionName = "i64_load16_u";
                break;
            }
            case wasmOpcodeI64Load32S: {
                functionName = "i64_load32_s";
                break;
            }
            case wasmOpcodeI64Load32U: {
                functionName = "i64_load32_u";
                break;
            }
            default: {
                fprintf(
                    stderr,
                    "ERROR: unsupported load instruction opcode: %s\n",
                    wasmOpcodeDescription(opcode)
                );
                return false;
            }
        }

        {
            const WasmValueType resultType = wasmOpcodeResultType(opcode);
            const U32 stackIndex0 = wasmTypeStackGetTopIndex(writer->typeStack, 0);
            MUST (wasmTypeStackSet(writer->stackDeclarations, stackIndex0, resultType))
            MUST (wasmCWriteIndent(writer))
            MUST (wasmCWriteStringStackName(writer->builder, stackIndex0, resultType))
            MUST (wasmCWrite(writer, " = "))
            MUST (wasmCWrite(writer, functionName))
            MUST (wasmCWrite(writer, "("))
            MUST (wasmCWriteStringMemoryName(writer->builder, writer->module, 0, true))
            MUST (wasmCWrite(writer, ", (U64)("))
            MUST (wasmCWriteStringStackName(
                writer->builder,
                stackIndex0,
                writer->typeStack->valueTypes[stackIndex0]
            ))
            MUST (wasmCWrite(writer, ")"))
            if (instruction.offset != 0) {
                MUST (wasmCWrite(writer, " + "))
                MUST (stringBuilderAppendI64(writer->builder, (I64) instruction.offset))
                MUST (wasmCWrite(writer, "u"))
            }
            MUST (wasmCWrite(writer, ");\n"))

            wasmTypeStackDrop(writer->typeStack, 1);

            MUST (wasmTypeStackPush(writer->typeStack, resultType))
        }
    }

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteStoreExpr(
    WasmCFunctionWriter* writer,
    const WasmOpcode opcode
) {
    WasmLoadStoreInstruction instruction;
    if (!wasmLoadStoreInstructionRead(writer->code, opcode, &instruction)) {
        fprintf(stderr, "ERROR: invalid store instruction\n");
        return false;
    }

    if (!writer->ignore) {

        const char* functionName = NULL;
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
                    "ERROR: unsupported store instruction opcode: %s\n",
                    wasmOpcodeDescription(opcode)
                );
                return false;
            }
        }

        {
            const U32 stackIndex0 = wasmTypeStackGetTopIndex(writer->typeStack, 0);
            const U32 stackIndex1 = wasmTypeStackGetTopIndex(writer->typeStack, 1);

            MUST (wasmCWriteIndent(writer))
            MUST (wasmCWrite(writer, functionName))
            MUST (wasmCWrite(writer, "("))
            MUST (wasmCWriteStringMemoryName(writer->builder, writer->module, 0, true))
            MUST (wasmCWrite(writer, ", (U64)("))
            MUST (wasmCWriteStringStackName(
                writer->builder,
                stackIndex1,
                writer->typeStack->valueTypes[stackIndex1]
            ))
            MUST (wasmCWrite(writer, ")"))
            if (instruction.offset != 0) {
                MUST (wasmCWrite(writer, " + "))
                MUST (stringBuilderAppendI64(writer->builder, (I64) instruction.offset))
                MUST (wasmCWrite(writer, "u"))
            }
            MUST (wasmCWrite(writer, ", "))
            MUST (wasmCWriteStringStackName(
                writer->builder,
                stackIndex0,
                writer->typeStack->valueTypes[stackIndex0]
            ))
            MUST (wasmCWrite(writer, ");\n"))

            wasmTypeStackDrop(writer->typeStack, 2);
        }
    }

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteMemorySize(
    WasmCFunctionWriter* writer,
    const WasmOpcode opcode
) {
    WasmMemoryInstruction instruction;
    if (!wasmMemoryInstructionRead(writer->code, opcode, &instruction)) {
        fprintf(stderr, "ERROR: invalid memory instruction\n");
        return false;
    }

    {
        static const U32 expectedMemoryIndex = 0;
        if (instruction.memoryIndex != expectedMemoryIndex) {
            fprintf(
                stderr,
                "ERROR: invalid memory instruction: expected memory index %u, got %u\n",
                expectedMemoryIndex,
                instruction.memoryIndex
            );
            return false;
        }
    }

    if (!writer->ignore) {
        static const WasmValueType resultType = wasmValueTypeI32;

        MUST (wasmTypeStackPush(writer->typeStack, resultType))
        {
            const U32 stackIndex0 = wasmTypeStackGetTopIndex(writer->typeStack, 0);
            MUST (wasmTypeStackSet(writer->stackDeclarations, stackIndex0, resultType))

            MUST (wasmCWriteIndent(writer))
            MUST (wasmCWriteStringStackName(writer->builder, stackIndex0, resultType))
            MUST (wasmCWrite(writer, " = "))
            MUST (wasmCWriteStringMemoryName(writer->builder, writer->module, 0, false))
            MUST (wasmCWrite(writer, ".pages;\n"))
        }
    }

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteMemoryGrow(
    WasmCFunctionWriter* writer,
    const WasmOpcode opcode
) {
    WasmMemoryInstruction instruction;
    if (!wasmMemoryInstructionRead(writer->code, opcode, &instruction)) {
        fprintf(stderr, "ERROR: invalid memory instruction\n");
        return false;
    }

    {
        static const U32 expectedMemoryIndex = 0;
        if (instruction.memoryIndex != expectedMemoryIndex) {
            fprintf(
                stderr,
                "ERROR: invalid memory instruction: expected memory index %u, got %u\n",
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
            MUST (wasmCWrite(writer, " = wasmGrowMemory("))
            MUST (wasmCWriteStringMemoryName(writer->builder, writer->module, 0, true))
            MUST (wasmCWrite(writer, ", "))
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
wasmCWriteUnaryExpr(
    WasmCFunctionWriter* writer,
    const WasmOpcode opcode,
    const char* operator
) {
    const WasmValueType resultType = wasmOpcodeResultType(opcode);
    const U32 stackIndex0 = wasmTypeStackGetTopIndex(writer->typeStack, 0);

    MUST (wasmTypeStackSet(writer->stackDeclarations, stackIndex0, resultType))

    MUST (wasmCWriteIndent(writer))
    MUST (wasmCWriteStringStackName(writer->builder, stackIndex0, resultType))
    MUST (wasmCWrite(writer, " = "))
    MUST (wasmCWrite(writer, operator))
    MUST (wasmCWrite(writer, "("))
    MUST (wasmCWriteStringStackName(
        writer->builder,
        stackIndex0,
        writer->typeStack->valueTypes[stackIndex0]
    ))
    MUST (wasmCWrite(writer, ");\n"))

    wasmTypeStackDrop(writer->typeStack, 1);
    MUST (wasmTypeStackPush(writer->typeStack, resultType))

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteInfixBinaryExpr(
    WasmCFunctionWriter* writer,
    const WasmOpcode opcode,
    const char* operator,
    bool assignmentAllowed
) {
    const WasmValueType resultType = wasmOpcodeResultType(opcode);

    const U32 stackIndex1 = wasmTypeStackGetTopIndex(writer->typeStack, 1);
    const U32 stackIndex0 = wasmTypeStackGetTopIndex(writer->typeStack, 0);

    MUST (wasmTypeStackSet(writer->stackDeclarations, stackIndex1, resultType))

    MUST (wasmCWriteIndent(writer))
    MUST (wasmCWriteStringStackName(writer->builder, stackIndex1, resultType))

    if (assignmentAllowed) {
        MUST (wasmCWrite(writer, " "))
        MUST (wasmCWrite(writer, operator))
        MUST (wasmCWrite(writer, "= "))
    } else {
        MUST (wasmCWrite(writer, " = "))
        MUST (wasmCWriteStringStackName(
            writer->builder,
            stackIndex1,
            writer->typeStack->valueTypes[stackIndex1]
        ))
        MUST (wasmCWrite(writer, " "))
        MUST (wasmCWrite(writer, operator))
        MUST (wasmCWrite(writer, " "))
    }
    MUST (wasmCWriteStringStackName(
        writer->builder,
        stackIndex0,
        writer->typeStack->valueTypes[stackIndex0]
    ))
    MUST (wasmCWrite(writer, ";\n"))

    wasmTypeStackDrop(writer->typeStack, 2);

    MUST (wasmTypeStackPush(writer->typeStack, resultType))

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteSignedInfixBinaryExpr(
    WasmCFunctionWriter* writer,
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
    MUST (wasmCWrite(writer, " = ("))
    MUST (wasmCWrite(writer, valueTypeNames[parameter1Type]))
    MUST (wasmCWrite(writer, ")(("))
    MUST (wasmCWrite(writer, signedTypeNames[parameter1Type]))
    MUST (wasmCWrite(writer, ")"))
    MUST (wasmCWriteStringStackName(
        writer->builder,
        stackIndex1,
        writer->typeStack->valueTypes[stackIndex1]
    ))
    MUST (wasmCWrite(writer, " "))
    MUST (wasmCWrite(writer, operator))
    MUST (wasmCWrite(writer, " ("))
    MUST (wasmCWrite(writer, signedTypeNames[parameter1Type]))
    MUST (wasmCWrite(writer, ")"))
    MUST (wasmCWriteStringStackName(
        writer->builder,
        stackIndex0,
        writer->typeStack->valueTypes[stackIndex0]
    ))
    MUST (wasmCWrite(writer, ");\n"))

    wasmTypeStackDrop(writer->typeStack, 2);
    MUST (wasmTypeStackPush(writer->typeStack, resultType))

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWritePrefixBinaryExpr(
    WasmCFunctionWriter* writer,
    const WasmOpcode opcode,
    const char* operator
) {
    const WasmValueType resultType = wasmOpcodeResultType(opcode);

    const U32 stackIndex1 = wasmTypeStackGetTopIndex(writer->typeStack, 1);
    const U32 stackIndex0 = wasmTypeStackGetTopIndex(writer->typeStack, 0);

    MUST (wasmTypeStackSet(writer->stackDeclarations, stackIndex1, resultType))

    MUST (wasmCWriteIndent(writer))
    MUST (wasmCWriteStringStackName(writer->builder, stackIndex1, resultType))
    MUST (wasmCWrite(writer, " = "))
    MUST (wasmCWrite(writer, operator))
    MUST (wasmCWrite(writer, "("))
    MUST (wasmCWriteStringStackName(
        writer->builder,
        stackIndex1,
        writer->typeStack->valueTypes[stackIndex1]
    ))
    MUST (wasmCWrite(writer, ", "))
    MUST (wasmCWriteStringStackName(
        writer->builder,
        stackIndex0,
        writer->typeStack->valueTypes[stackIndex0]
    ))
    MUST (wasmCWrite(writer, ");\n"))

    wasmTypeStackDrop(writer->typeStack, 2);
    MUST (wasmTypeStackPush(writer->typeStack, resultType))

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteSignedShiftRightExpr(
    WasmCFunctionWriter* writer,
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
    MUST (wasmCWrite(writer, " = ("))
    MUST (wasmCWrite(writer, valueTypeNames[resultType]))
    MUST (wasmCWrite(writer, ")(("))
    MUST (wasmCWrite(writer, signedTypeNames[resultType]))
    MUST (wasmCWrite(writer, ")"))
    MUST (wasmCWriteStringStackName(
        writer->builder,
        stackIndex1,
        writer->typeStack->valueTypes[stackIndex1]
    ))
    MUST (wasmCWrite(writer, " >> ("))
    MUST (wasmCWriteStringStackName(
        writer->builder,
        stackIndex0,
        writer->typeStack->valueTypes[stackIndex0]
    ))
    MUST (wasmCWrite(writer, " & "))
    MUST (wasmCWrite(writer, shiftMaskStrings[resultType]))
    MUST (wasmCWrite(writer, "));\n"))

    wasmTypeStackDrop(writer->typeStack, 1);

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteUnsignedShiftRightExpr(
    WasmCFunctionWriter* writer,
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
    MUST (wasmCWrite(writer, " >>= ("))
    MUST (wasmCWriteStringStackName(
        writer->builder,
        stackIndex0,
        writer->typeStack->valueTypes[stackIndex0]
    ))
    MUST (wasmCWrite(writer, " & "))
    MUST (wasmCWrite(writer, shiftMaskStrings[resultType]))
    MUST (wasmCWrite(writer, ");\n"))

    wasmTypeStackDrop(writer->typeStack, 1);

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteShiftLeftExpr(
    WasmCFunctionWriter* writer,
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
    MUST (wasmCWrite(writer, " <<= ("))
    MUST (wasmCWriteStringStackName(
        writer->builder,
        stackIndex0,
        writer->typeStack->valueTypes[stackIndex0]
    ))
    MUST (wasmCWrite(writer, " & "))
    MUST (wasmCWrite(writer, shiftMaskStrings[resultType]))
    MUST (wasmCWrite(writer, ");\n"))

    wasmTypeStackDrop(writer->typeStack, 1);

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteLabel(
    WasmCFunctionWriter* writer,
    U32 labelIndex
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
    bool ignore = writer->ignore;

    size_t typeStackLengthBeforeBranches = 0;
    WasmLabel label = wasmEmptyLabel;

    WasmValueType blockValueType;
    WasmValueType* blockType = &blockValueType;
    if (!wasmReadBlockType(writer->code, &blockType)) {
        fprintf(stderr, "ERROR: invalid if instruction: expected block type\n");
        return false;
    }

    if (!ignore) {
        MUST (wasmCWriteIndent(writer))
        MUST (wasmCWrite(writer, "if ("))
        {
            const U32 stackIndex0 = wasmTypeStackGetTopIndex(writer->typeStack, 0);
            MUST (wasmCWriteStringStackName(
                writer->builder,
                stackIndex0,
                writer->typeStack->valueTypes[stackIndex0]
            ))
        }
        MUST (wasmCWrite(writer, ") {\n"))

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
        MUST (wasmCWrite(writer, "}"))
    }

    if (*opcode == wasmOpcodeElse) {
        if (!ignore) {
            writer->typeStack->length = typeStackLengthBeforeBranches;

            MUST (wasmCWrite(writer, " else {\n"))

            writer->indent++;
        }

        MUST (wasmCWriteFunctionCode(writer, opcode))

        if (!ignore) {
            writer->ignore = false;

            writer->indent--;

            MUST (wasmCWriteIndent(writer))
            MUST (wasmCWrite(writer, "}"))
        }
    }

    if (!ignore) {
        MUST (wasmCWrite(writer, "\n"))

        MUST (wasmCWriteLabel(writer, label.index))

        writer->typeStack->length = typeStackLengthBeforeBranches;

        wasmLabelStackPop(writer->labelStack);

        if (blockType != NULL) {
            MUST (wasmTypeStackPush(writer->typeStack, blockValueType))
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
    bool ignore = writer->ignore;

    size_t typeStackLengthBeforeBranches = 0;
    WasmLabel label = wasmEmptyLabel;

    WasmValueType blockValueType;
    WasmValueType* blockType = &blockValueType;
    if (!wasmReadBlockType(writer->code, &blockType)) {
        fprintf(stderr, "ERROR: invalid block instruction: expected block type\n");
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

        MUST (wasmCWriteLabel(writer, label.index))

        writer->typeStack->length = typeStackLengthBeforeBranches;

        wasmLabelStackPop(writer->labelStack);

        if (blockType != NULL) {
            MUST (wasmTypeStackPush(writer->typeStack, blockValueType))
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
    bool ignore = writer->ignore;

    size_t typeStackLengthBeforeBranches = 0;
    WasmLabel label = wasmEmptyLabel;

    WasmValueType blockValueType;
    WasmValueType* blockType = &blockValueType;
    if (!wasmReadBlockType(writer->code, &blockType)) {
        fprintf(stderr, "ERROR: invalid loop instruction: expected block type\n");
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
            MUST (wasmTypeStackPush(writer->typeStack, blockValueType))
        }
    }

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteGoto(
    WasmCFunctionWriter* writer,
    U32 labelStackIndex
) {
    WasmLabel label = writer->labelStack->labels[labelStackIndex];

    MUST(wasmCWriteIndent(writer))

    if (label.type != NULL) {
        WasmValueType resultType = *label.type;

        const U32 stackIndex0 = wasmTypeStackGetTopIndex(writer->typeStack, 0);
        const U32 destinationStackIndex = label.typeStackLength;

        if (destinationStackIndex != stackIndex0) {

            MUST (wasmTypeStackSet(writer->stackDeclarations, destinationStackIndex, resultType))

            MUST(wasmCWriteStringStackName(writer->builder, destinationStackIndex, resultType))
            MUST(wasmCWrite(writer, " = "))
            MUST(wasmCWriteStringStackName(
                writer->builder,
                stackIndex0,
                writer->typeStack->valueTypes[stackIndex0]
            ))
            MUST(wasmCWrite(writer, "; "))
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
    WasmCFunctionWriter* writer
) {
    const U32 stackIndex0 = wasmTypeStackGetTopIndex(writer->typeStack, 0);
    const U32 stackIndex1 = wasmTypeStackGetTopIndex(writer->typeStack, 1);
    const U32 stackIndex2 = wasmTypeStackGetTopIndex(writer->typeStack, 2);

    /* same as 2 */
    const WasmValueType resultType = writer->typeStack->valueTypes[stackIndex1];

    MUST (wasmTypeStackSet(writer->stackDeclarations, stackIndex2, resultType))

    MUST(wasmCWriteIndent(writer))
    MUST (wasmCWriteStringStackName(
        writer->builder,
        stackIndex2,
        resultType
    ))
    MUST (wasmCWrite(writer, " = "))
    MUST (wasmCWriteStringStackName(
        writer->builder,
        stackIndex0,
        writer->typeStack->valueTypes[stackIndex0]
    ))
    MUST (wasmCWrite(writer, " ? "))
    MUST (wasmCWriteStringStackName(
        writer->builder,
        stackIndex2,
        writer->typeStack->valueTypes[stackIndex2]
    ))
    MUST (wasmCWrite(writer, " : "))
    MUST (wasmCWriteStringStackName(
        writer->builder,
        stackIndex1,
        writer->typeStack->valueTypes[stackIndex1]
    ))
    MUST (wasmCWrite(writer, ";\n"))

    wasmTypeStackDrop(writer->typeStack, 3);

    MUST (wasmTypeStackPush(writer->typeStack, resultType))

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteBranchExpr(
    WasmCFunctionWriter* writer,
    const WasmOpcode opcode
) {
    WasmBranchInstruction instruction;
    if (!wasmBranchInstructionRead(writer->code, opcode, &instruction)) {
        fprintf(
            stderr,
            "ERROR: invalid %s instruction encoding\n",
            wasmOpcodeDescription(opcode)
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
    WasmCFunctionWriter* writer,
    const WasmOpcode opcode
) {
    WasmBranchInstruction instruction;
    if (!wasmBranchInstructionRead(writer->code, opcode, &instruction)) {
        fprintf(
            stderr,
            "ERROR: invalid %s instruction encoding\n",
            wasmOpcodeDescription(opcode)
        );
        return false;
    }

    if (!writer->ignore) {

        const U32 stackIndex0 = wasmTypeStackGetTopIndex(writer->typeStack, 0);

        MUST (wasmCWriteIndent(writer))
        MUST (wasmCWrite(writer, "if ("))
        MUST (wasmCWriteStringStackName(
            writer->builder,
            stackIndex0,
            writer->typeStack->valueTypes[stackIndex0]
        ))
        MUST (wasmCWrite(writer, ") {\n"))
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
    WasmCFunctionWriter* writer,
    const WasmOpcode opcode
) {
    WasmBranchTableInstruction instruction;
    if (!wasmBranchTableInstructionRead(writer->code, opcode, &instruction)) {
        fprintf(
            stderr,
            "ERROR: invalid %s instruction encoding\n",
            wasmOpcodeDescription(opcode)
        );
        return false;
    }

    if (!writer->ignore) {
        const U32 stackIndex0 = wasmTypeStackGetTopIndex(writer->typeStack, 0);

        MUST (wasmCWriteIndent(writer))
        MUST (wasmCWrite(writer, "switch ("))
        MUST (wasmCWriteStringStackName(
            writer->builder,
            stackIndex0,
            writer->typeStack->valueTypes[stackIndex0]
        ))
        MUST (wasmCWrite(writer, ") {\n"))

        wasmTypeStackDrop(writer->typeStack, 1);

        {
            U32 index = 0;
            for (; index < instruction.labelIndexCount; index++) {
                MUST (wasmCWriteIndent(writer))
                MUST (wasmCWrite(writer, "case "))
                MUST (stringBuilderAppendI64(writer->builder, index))
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
wasmCWriteFunctionCode(
    WasmCFunctionWriter* writer,
    WasmOpcode* opcode
) {
    while (wasmOpcodeRead(writer->code, opcode)) {
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
                MUST (wasmCWriteBranchExpr(writer, *opcode))
                writer->ignore = true;
                break;
            }
            case wasmOpcodeBrIf: {
                MUST (wasmCWriteBranchIfExpr(writer, *opcode))
                break;
            }
            case wasmOpcodeBrTable: {
                MUST (wasmCWriteBranchTableExpr(writer, *opcode))
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
                MUST (wasmCWriteMemorySize(writer, *opcode))
                break;
            }
            case wasmOpcodeMemoryGrow: {
                MUST (wasmCWriteMemoryGrow(writer, *opcode))
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
                        MUST (wasmCWriteInfixBinaryExpr(writer, *opcode, "==", false))
                        break;
                    }
                    case wasmOpcodeI32Ne:
                    case wasmOpcodeI64Ne:
                    case wasmOpcodeF32Ne:
                    case wasmOpcodeF64Ne: {
                        MUST (wasmCWriteInfixBinaryExpr(writer, *opcode, "!=", false))
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
                        MUST (wasmCWriteInfixBinaryExpr(writer, *opcode, "<", false))
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
                        MUST (wasmCWriteInfixBinaryExpr(writer, *opcode, "<=", false))
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
                        MUST (wasmCWriteInfixBinaryExpr(writer, *opcode, ">", false))
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
                        MUST (wasmCWriteInfixBinaryExpr(writer, *opcode, ">=", false))
                        break;
                    }
                    case wasmOpcodeI32Add:
                    case wasmOpcodeI64Add:
                    case wasmOpcodeF32Add:
                    case wasmOpcodeF64Add: {
                        MUST (wasmCWriteInfixBinaryExpr(writer, *opcode, "+", true))
                        break;
                    }
                    case wasmOpcodeI32Sub:
                    case wasmOpcodeI64Sub:
                    case wasmOpcodeF32Sub:
                    case wasmOpcodeF64Sub: {
                        if (!writer->ignore) {
                            MUST (wasmCWriteInfixBinaryExpr(writer, *opcode, "-", true))
                        }
                        break;
                    }
                    case wasmOpcodeI32Mul:
                    case wasmOpcodeI64Mul:
                    case wasmOpcodeF32Mul:
                    case wasmOpcodeF64Mul: {
                        MUST (wasmCWriteInfixBinaryExpr(writer, *opcode, "*", true))
                        break;
                    }
                    case wasmOpcodeI32DivS: {
                        MUST (wasmCWritePrefixBinaryExpr(writer, *opcode, "I32_DIV_S"))
                        break;
                    }
                    case wasmOpcodeI64DivS: {
                        MUST (wasmCWritePrefixBinaryExpr(writer, *opcode, "I64_DIV_S"))
                        break;
                    }
                    case wasmOpcodeI32DivU:
                    case wasmOpcodeI64DivU: {
                        MUST (wasmCWritePrefixBinaryExpr(writer, *opcode, "DIV_U"))
                        break;
                    }
                    case wasmOpcodeF32Div:
                    case wasmOpcodeF64Div: {
                        MUST (wasmCWriteInfixBinaryExpr(writer, *opcode, "/", true))
                        break;
                    }
                    case wasmOpcodeI32Eqz:
                    case wasmOpcodeI64Eqz: {
                        MUST (wasmCWriteUnaryExpr(writer, *opcode, "!"))
                        break;
                    }
                    case wasmOpcodeI32And:
                    case wasmOpcodeI64And: {
                        MUST (wasmCWriteInfixBinaryExpr(writer, *opcode, "&", true))
                        break;
                    }
                    case wasmOpcodeI32Or:
                    case wasmOpcodeI64Or: {
                        MUST (wasmCWriteInfixBinaryExpr(writer, *opcode, "|", true))
                        break;
                    }
                    case wasmOpcodeI32Xor:
                    case wasmOpcodeI64Xor: {
                        MUST (wasmCWriteInfixBinaryExpr(writer, *opcode, "^", true))
                        break;
                    }
                    case wasmOpcodeI32RemS: {
                        MUST (wasmCWritePrefixBinaryExpr(writer, *opcode, "I32_REM_S"))
                        break;
                    }
                    case wasmOpcodeI64RemS: {
                        MUST (wasmCWritePrefixBinaryExpr(writer, *opcode, "I64_REM_S"))
                        break;
                    }
                    case wasmOpcodeI32RemU:
                    case wasmOpcodeI64RemU: {
                        MUST (wasmCWritePrefixBinaryExpr(writer, *opcode, "REM_U"))
                        break;
                    }
                    case wasmOpcodeI32Clz: {
                        MUST (wasmCWriteUnaryExpr(writer, *opcode, "I32_CLZ"))
                        break;
                    }
                    case wasmOpcodeI64Clz: {
                        MUST (wasmCWriteUnaryExpr(writer, *opcode, "I64_CLZ"))
                        break;
                    }
                    case wasmOpcodeI32Ctz: {
                        MUST (wasmCWriteUnaryExpr(writer, *opcode, "I32_CTZ"))
                        break;
                    }
                    case wasmOpcodeI64Ctz: {
                        MUST (wasmCWriteUnaryExpr(writer, *opcode, "I64_CTZ"))
                        break;
                    }
                    case wasmOpcodeI32PopCnt: {
                        MUST (wasmCWriteUnaryExpr(writer, *opcode, "I32_POPCNT"))
                        break;
                    }
                    case wasmOpcodeI64PopCnt: {
                        MUST (wasmCWriteUnaryExpr(writer, *opcode, "I64_POPCNT"))
                        break;
                    }
                    case wasmOpcodeF32Neg:
                    case wasmOpcodeF64Neg: {
                        MUST (wasmCWriteUnaryExpr(writer, *opcode, "-"))
                        break;
                    }
                    case wasmOpcodeF32Abs: {
                        MUST (wasmCWriteUnaryExpr(writer, *opcode, "fabsf"))
                        break;
                    }
                    case wasmOpcodeF64Abs: {
                        MUST (wasmCWriteUnaryExpr(writer, *opcode, "fabs"))
                        break;
                    }
                    case wasmOpcodeF32Sqrt: {
                        MUST (wasmCWriteUnaryExpr(writer, *opcode, "sqrtf"))
                        break;
                    }
                    case wasmOpcodeF64Sqrt: {
                        MUST (wasmCWriteUnaryExpr(writer, *opcode, "sqrt"))
                        break;
                    }
                    case wasmOpcodeF32Ceil: {
                        MUST (wasmCWriteUnaryExpr(writer, *opcode, "ceilf"))
                        break;
                    }
                    case wasmOpcodeF64Ceil: {
                        MUST (wasmCWriteUnaryExpr(writer, *opcode, "ceil"))
                        break;
                    }
                    case wasmOpcodeF32Floor: {
                        MUST (wasmCWriteUnaryExpr(writer, *opcode, "floorf"))
                        break;
                    }
                    case wasmOpcodeF64Floor: {
                        MUST (wasmCWriteUnaryExpr(writer, *opcode, "floor"))
                        break;
                    }
                    case wasmOpcodeF32Trunc: {
                        MUST (wasmCWriteUnaryExpr(writer, *opcode, "truncf"))
                        break;
                    }
                    case wasmOpcodeF64Trunc: {
                        MUST (wasmCWriteUnaryExpr(writer, *opcode, "trunc"))
                        break;
                    }
                    case wasmOpcodeF32Nearest: {
                        MUST (wasmCWriteUnaryExpr(writer, *opcode, "nearbyintf"))
                        break;
                    }
                    case wasmOpcodeF64Nearest: {
                        MUST (wasmCWriteUnaryExpr(writer, *opcode, "nearbyint"))
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
                        MUST (wasmCWritePrefixBinaryExpr(writer, *opcode, "I32_ROTL"))
                        break;
                    }
                    case wasmOpcodeI64Rotl: {
                        MUST (wasmCWritePrefixBinaryExpr(writer, *opcode, "I64_ROTL"))
                        break;
                    }
                    case wasmOpcodeI32Rotr: {
                        MUST (wasmCWritePrefixBinaryExpr(writer, *opcode, "I32_ROTR"))
                        break;
                    }
                    case wasmOpcodeI64Rotr: {
                        MUST (wasmCWritePrefixBinaryExpr(writer, *opcode, "I64_ROTR"))
                        break;
                    }
                    case wasmOpcodeF32Min:
                    case wasmOpcodeF64Min: {
                        MUST (wasmCWritePrefixBinaryExpr(writer, *opcode, "FMIN"))
                        break;
                    }
                    case wasmOpcodeF32Max:
                    case wasmOpcodeF64Max: {
                        MUST (wasmCWritePrefixBinaryExpr(writer, *opcode, "FMAX"))
                        break;
                    }
                    case wasmOpcodeF32CopySign: {
                        MUST (wasmCWritePrefixBinaryExpr(writer, *opcode, "copysignf"))
                        break;
                    }
                    case wasmOpcodeF64CopySign: {
                        MUST (wasmCWritePrefixBinaryExpr(writer, *opcode, "copysign"))
                        break;
                    }
                    case wasmOpcodeI64ExtendI32S: {
                        MUST (wasmCWriteUnaryExpr(writer, *opcode, "(U64)(I64)(I32)"))
                        break;
                    }
                    case wasmOpcodeI64ExtendI32U: {
                        MUST (wasmCWriteUnaryExpr(writer, *opcode, "(U64)"))
                        break;
                    }
                    case wasmOpcodeI32WrapI64: {
                        MUST (wasmCWriteUnaryExpr(writer, *opcode, "(U32)"))
                        break;
                    }
                    case wasmOpcodeI32TruncF32S: {
                        MUST (wasmCWriteUnaryExpr(writer, *opcode, "I32_TRUNC_S_F32"))
                        break;
                    }
                    case wasmOpcodeI64TruncF32S: {
                        MUST (wasmCWriteUnaryExpr(writer, *opcode, "I64_TRUNC_S_F32"))
                        break;
                    }
                    case wasmOpcodeI32TruncF64S: {
                        MUST (wasmCWriteUnaryExpr(writer, *opcode, "I32_TRUNC_S_F64"))
                        break;
                    }
                    case wasmOpcodeI64TruncF64S: {
                        MUST (wasmCWriteUnaryExpr(writer, *opcode, "I64_TRUNC_S_F64"))
                        break;
                    }
                    case wasmOpcodeI32TruncF32U: {
                        MUST (wasmCWriteUnaryExpr(writer, *opcode, "I32_TRUNC_U_F32"))
                        break;
                    }
                    case wasmOpcodeI64TruncF32U: {
                        MUST (wasmCWriteUnaryExpr(writer, *opcode, "I64_TRUNC_U_F32"))
                        break;
                    }
                    case wasmOpcodeI32TruncF64U: {
                        MUST (wasmCWriteUnaryExpr(writer, *opcode, "I32_TRUNC_U_F64"))
                        break;
                    }
                    case wasmOpcodeI64TruncF64U: {
                        MUST (wasmCWriteUnaryExpr(writer, *opcode, "I64_TRUNC_U_F64"))
                        break;
                    }
                    case wasmOpcodeF32ConvertI32S: {
                        MUST (wasmCWriteUnaryExpr(writer, *opcode, "(F32)(I32)"))
                        break;
                    }
                    case wasmOpcodeF32ConvertI64S: {
                        MUST (wasmCWriteUnaryExpr(writer, *opcode, "(F32)(I64)"))
                        break;
                    }
                    case wasmOpcodeF32ConvertI32U:
                    case wasmOpcodeF32DemoteF64: {
                        MUST (wasmCWriteUnaryExpr(writer, *opcode, "(F32)"))
                        break;
                    }
                    case wasmOpcodeF32ConvertI64U: {
                        /* TODO */
                        MUST (wasmCWriteUnaryExpr(writer, *opcode, "(F32)"))
                        break;
                    }
                    case wasmOpcodeF64ConvertI32S: {
                        MUST (wasmCWriteUnaryExpr(writer, *opcode, "(F64)(I32)"))
                        break;
                    }
                    case wasmOpcodeF64ConvertI64S: {
                        MUST (wasmCWriteUnaryExpr(writer, *opcode, "(F64)(I64)"))
                        break;
                    }
                    case wasmOpcodeF64ConvertI32U:
                    case wasmOpcodeF64PromoteF32: {
                        MUST (wasmCWriteUnaryExpr(writer, *opcode, "(F64)"))
                        break;
                    }
                    case wasmOpcodeF64ConvertI64U: {
                        /* TODO */
                        MUST (wasmCWriteUnaryExpr(writer, *opcode, "(F64)"))
                        break;
                    }
                    case wasmOpcodeF32ReinterpretI32: {
                        MUST (wasmCWriteUnaryExpr(writer, *opcode, "f32_reinterpret_i32"))
                        break;
                    }
                    case wasmOpcodeI32ReinterpretF32: {
                        MUST (wasmCWriteUnaryExpr(writer, *opcode, "i32_reinterpret_f32"))
                        break;
                    }
                    case wasmOpcodeF64ReinterpretI64: {
                        MUST (wasmCWriteUnaryExpr(writer, *opcode, "f64_reinterpret_i64"))
                        break;
                    }
                    case wasmOpcodeI64ReinterpretF64: {
                        MUST (wasmCWriteUnaryExpr(writer, *opcode, "i64_reinterpret_f64"))
                        break;
                    }
                    default:
                        fprintf(stderr, "ERROR: unsupported opcode %s\n", wasmOpcodeDescription(*opcode));
                        return false;
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
    const WasmTypeStack* stackDeclarations
) {
    U32 stackDeclarationIndex = 0;
    for (; stackDeclarationIndex < stackDeclarations->length; stackDeclarationIndex++) {
        WasmValueType entry = stackDeclarations->valueTypes[stackDeclarationIndex];
        if (entry) {
            WasmValueType testType = 0;
            for (; testType < wasmValueType_count; testType++) {
                if (!wasmTypeStackIsSet(stackDeclarations, stackDeclarationIndex, testType)) {
                    continue;
                }
                fputs("    ", file);
                fputs(valueTypeNames[testType], file);
                fputs(" ", file);
                wasmCWriteFileStackName(file, stackDeclarationIndex, testType);
                fputs(";\n", file);
            }
        }
    }
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteFunctionReturn(
    WasmCFunctionWriter* writer,
    WasmFunctionType functionType
) {
    if (!functionType.resultCount) {
        return true;
    }

    if (writer->stackDeclarations->length > 0) {
        /* TODO: add support for multiple result values */
        const WasmValueType returnType = functionType.resultTypes[0];
        wasmTypeStackClear(writer->typeStack);
        MUST (wasmTypeStackPush(writer->typeStack, returnType))

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
    const WasmFunction function
) {
    Buffer code = function.code;
    StringBuilder stringBuilder = emptyStringBuilder;
    WasmOpcode opcode = wasmOpcodeUnreachable;
    WasmLabel label = wasmEmptyLabel;
    WasmValueType* resultType = NULL;

    WasmFunctionType functionType =
        module->functionTypes.functionTypes[function.functionTypeIndex];

    if (functionType.resultCount) {
        resultType = &functionType.resultTypes[0];
        /* TODO: add support for multiple result values */
        if (functionType.resultCount > 1) {
            fprintf(stderr, "ERROR: function with multiple return values\n");
            return false;
        }
    } else {
        resultType = NULL;
    }

    MUST (stringBuilderInitialize(&stringBuilder))

    wasmTypeStackClear(typeStack);
    wasmTypeStackClear(stackDeclarations);
    wasmLabelStackClear(labelStack);

    {
        WasmCFunctionWriter writer;
        writer.builder = &stringBuilder;
        writer.typeStack = typeStack;
        writer.stackDeclarations = stackDeclarations;
        writer.labelStack = labelStack;
        writer.module = module;
        writer.function = function;
        writer.code = &code;
        writer.indent = 0;
        writer.ignore = false;

        MUST (wasmLabelStackPush(writer.labelStack, 0, resultType, &label))
        MUST (wasmCWriteFunctionCode(&writer, &opcode))
        MUST (wasmCWriteLabel(&writer, label.index))
        MUST (wasmCWriteFunctionReturn(&writer, functionType))
    }

    fputs("{\n", file);
    wasmCWriteFileLocalsDeclarations(file, module, function);
    wasmCWriteStackDeclarations(file, stackDeclarations);
    fputs(stringBuilder.string, file);
    fputs("}\n", file);

    stringBuilderFree(&stringBuilder);

    return true;
}

static
void
wasmCWriteFileParameters(
    FILE* file,
    WasmFunctionType functionType
) {
    fputs("(", file);
    {
        U32 parameterIndex = 0;
        for (; parameterIndex < functionType.parameterCount; parameterIndex++) {
            const WasmValueType parameterType = functionType.parameterTypes[parameterIndex];
            if (parameterIndex > 0) {
                fputs(", ", file);
            }
            {
                const char* parameterTypeName = valueTypeNames[parameterType];
                fputs(parameterTypeName, file);
            }
        }
    }
    fputs(")", file);
}

static
void
wasmCWriteFunctionImports(
    FILE* file,
    const WasmModule* module
) {
    U32 functionIndex = 0;
    U32 functionImportCount = module->functionImports.length;
    for (; functionIndex < functionImportCount; functionIndex++) {
        const WasmFunctionImport import = module->functionImports.imports[functionIndex];
        const WasmFunctionType functionType =
            module->functionTypes.functionTypes[import.functionTypeIndex];

        fputs("extern ", file);
        fputs(wasmCGetReturnType(functionType), file);
        fputc(' ', file);
        wasmCWriteFileFunctionName(file, module, functionIndex, false);
        wasmCWriteFileParameters(file, functionType);
        fputs(";\n\n", file);
    }
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteFunctionDeclarations(
    FILE* file,
    const WasmModule* module
) {
    U32 functionImportCount = module->functionImports.length;

    U32 functionIndex = 0;
    for (; functionIndex < module->functions.count; functionIndex++) {
        const WasmFunction function = module->functions.functions[functionIndex];
        wasmCWriteFileFunctionSignature(file, module, function, functionImportCount + functionIndex);
        fputs(";\n\n", file);
    }

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteFunctionImplementations(
    FILE* file,
    const WasmModule* module
) {
    U32 functionImportCount = module->functionImports.length;

    WasmTypeStack typeStack = wasmEmptyTypeStack;
    WasmTypeStack valueStack = wasmEmptyTypeStack;
    WasmLabelStack labelStack = wasmEmptyLabelStack;

    U32 functionIndex = 0;
    for (; functionIndex < module->functions.count; functionIndex++) {
        const WasmFunction function = module->functions.functions[functionIndex];

        wasmCWriteFileFunctionSignature(file, module, function, functionImportCount + functionIndex);
        fputs(" ", file);
        MUST (wasmCWriteFunctionBody(file, &typeStack, &valueStack, &labelStack, module, function))
        fputs("\n", file);
    }

    wasmTypeStackFree(typeStack);
    wasmTypeStackFree(valueStack);
    wasmLabelStackFree(labelStack);

    return true;
}

static
void
wasmCWriteGlobalImports(
    FILE* file,
    const WasmModule* module
) {
    U32 globalIndex = 0;
    for (; globalIndex < module->globalImports.length; globalIndex++) {
        WasmGlobalImport import = module->globalImports.imports[globalIndex];
        fputs("extern ", file);
        fputs(valueTypeNames[import.globalType.valueType], file);
        wasmCWriteFileGlobalName(file, module, globalIndex, false);
        fputs(";\n\n", file);
    }
}

static
void
wasmCWriteGlobals(
    FILE* file,
    const WasmModule* module
) {
    U32 globalIndex = 0;
    for (; globalIndex < module->globals.count; globalIndex++) {
        WasmGlobal global = module->globals.globals[globalIndex];
        fputs("static ", file);
        fputs(valueTypeNames[global.type.valueType], file);
        fputs(" ", file);
        wasmCWriteFileGlobalName(file, module, module->globalImports.length + globalIndex, false);
        fputs(";\n\n", file);
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
            WasmValueType resultType = wasmOpcodeResultType(opcode);
            WasmConstInstruction instruction;
            if (!wasmConstInstructionRead(&code, opcode, &instruction)) {
                fprintf(stderr, "ERROR: invalid const instruction\n");
                return false;
            }
            MUST (wasmCWriteLiteral(builder, resultType, instruction.value))
            break;
        }
        case wasmOpcodeGlobalGet: {
            WasmGlobalInstruction instruction;
            MUST (wasmGlobalInstructionRead(&code, opcode, &instruction))
            MUST (wasmCWriteStringGlobalName(builder, module, instruction.globalIndex, false))
            break;
        }
        default: {
            fprintf(stderr, "ERROR: invalid init expression instruction %s\n", wasmOpcodeDescription(opcode));
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
    const WasmModule* module
) {
    U32 globalIndex = 0;

    fputs("static void initGlobals(void) {\n", file);

    for (; globalIndex < module->globals.count; globalIndex++) {
        WasmGlobal global = module->globals.globals[globalIndex];

        fputs("    ", file);
        wasmCWriteFileGlobalName(file, module, module->globalImports.length + globalIndex, false);
        fputs(" = ", file);
        {
            Buffer code = global.init;
            StringBuilder stringBuilder = emptyStringBuilder;

            MUST (stringBuilderInitialize(&stringBuilder))
            MUST (wasmCWriteConstantExpr(&stringBuilder, module, code))
            fputs(stringBuilder.string, file);
            stringBuilderFree(&stringBuilder);
        }
        fputs(";\n", file);
    }

    fputs("}\n\n", file);

    return true;
}

static
void
wasmCWriteExportName(
    FILE* file,
    const char* name
) {
    fputs("e_", file);
    wasmCWriteFileEscaped(file, name);
}

static
void
wasmCWriteFunctionExport(
    FILE* file,
    const WasmModule* module,
    WasmExport export,
    WasmFunction function
) {
    const WasmFunctionType functionType =
        module->functionTypes.functionTypes[function.functionTypeIndex];

    fputs(wasmCGetReturnType(functionType), file);
    fputs(" (*", file);
    wasmCWriteExportName(file, export.name);
    fputs(")", file);
    wasmCWriteFileParameters(file, functionType);
    fputs(";\n\n", file);
}

static
void
wasmCWriteMemoryExport(
    FILE* file,
    WasmExport export
) {
    fputs("wasmMemory (*", file);
    wasmCWriteExportName(file, export.name);
    fputs(");\n\n", file);
}

static
void
wasmCWriteExports(
    FILE* file,
    const WasmModule* module
) {
    U32 exportIndex = 0;
    for (; exportIndex < module->exports.count; exportIndex++) {
        WasmExport export = module->exports.exports[exportIndex];
        switch (export.kind) {
            case wasmExportKindFunction: {
                U32 functionImportCount = module->functionImports.length;
                U32 functionIndex = export.index - functionImportCount;
                const WasmFunction function = module->functions.functions[functionIndex];
                wasmCWriteFunctionExport(file, module, export, function);
                break;
            }
            case wasmExportKindMemory: {
                wasmCWriteMemoryExport(file, export);
                break;
            }

            /* TODO: other export kinds */
        }
    }
}

static
void
wasmCWriteInitExports(
    FILE* file,
    const WasmModule* module
) {
    U32 exportIndex = 0;

    fputs("static void initExports(void) {\n", file);

    for (; exportIndex < module->exports.count; exportIndex++) {
        const WasmExport export = module->exports.exports[exportIndex];
        switch (export.kind) {
            case wasmExportKindFunction: {
                fputs("    ", file);
                wasmCWriteExportName(file, export.name);
                fputs(" = ", file);
                wasmCWriteFileFunctionName(file, module, export.index, true);
                fputs(";\n", file);
                break;
            }
            case wasmExportKindMemory: {
                fputs("    ", file);
                wasmCWriteExportName(file, export.name);
                fputs(" = ", file);
                wasmCWriteFileMemoryName(file, module, export.index, true);
                fputs(";\n", file);
                break;
            }

            /* TODO: other export kinds */
        }
    }

    fputs("}\n\n", file);
}

static
void
wasmCWriteDataSegments(
    FILE* file,
    const WasmModule* module
) {
    U32 dataSegmentIndex = 0;
    for (; dataSegmentIndex < module->dataSegments.count; dataSegmentIndex++) {
        WasmDataSegment dataSegment = module->dataSegments.dataSegments[dataSegmentIndex];
        fputs("static const U8 ", file);
        wasmCWriteFileDataSegmentName(file, dataSegmentIndex);
        fputs("[] = {\n    ", file);
        {
            U32 byteIndex = 0;
            for (; byteIndex < dataSegment.bytes.length; byteIndex++) {
                fprintf(file, "0x%x, ", dataSegment.bytes.data[byteIndex]);
            }
        }
        fputs("\n};\n\n", file);
    }
}

static
void
wasmCWriteMemoryImports(
    FILE* file,
    const WasmModule* module
) {
    U32 memoryIndex = 0;
    for (; memoryIndex < module->memoryImports.length; memoryIndex++) {
        fputs("extern wasmMemory ", file);
        wasmCWriteFileMemoryName(file, module, memoryIndex, false);
        fputs(";\n\n", file);
    }
}

static
void
wasmCWriteMemories(
    FILE* file,
    const WasmModule* module
) {
    U32 memoryIndex = 0;
    for (; memoryIndex < module->memories.count; memoryIndex++) {
        fputs("static wasmMemory ", file);
        wasmCWriteFileMemoryName(file, module, module->memoryImports.length + memoryIndex, false);
        fputs(";\n\n", file);
    }
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteInitMemories(
    FILE* file,
    const WasmModule* module
) {
    fputs("static void initMemories(void) {\n", file);

    {
        U32 memoryIndex = 0;
        for (; memoryIndex < module->memories.count; memoryIndex++) {
            WasmMemory memory = module->memories.memories[memoryIndex];

            fputs("    wasmAllocateMemory(", file);
            wasmCWriteFileMemoryName(file, module, module->memoryImports.length + memoryIndex, true);
            fprintf(file, ", %u, %u);\n", memory.min, memory.max);
        }
    }

    {
        U32 dataSegmentIndex = 0;
        for (; dataSegmentIndex < module->dataSegments.count; dataSegmentIndex++) {
            WasmDataSegment dataSegment = module->dataSegments.dataSegments[dataSegmentIndex];

            fputs("    LOAD_DATA(", file);
            wasmCWriteFileMemoryName(file, module, dataSegment.memoryIndex, false);
            fputs(", ", file);
            {
                Buffer code = dataSegment.offset;
                StringBuilder stringBuilder = emptyStringBuilder;

                MUST (stringBuilderInitialize(&stringBuilder))
                MUST (wasmCWriteConstantExpr(&stringBuilder, module, code))
                fputs(stringBuilder.string, file);
                stringBuilderFree(&stringBuilder);
            }
            fputs(", ", file);
            wasmCWriteFileDataSegmentName(file, dataSegmentIndex);
            fprintf(file, ", %lu);\n", dataSegment.bytes.length);
        }
    }

    fputs("}\n\n", file);

    return true;
}

static
void
wasmCWriteTableImports(
    FILE* file,
    const WasmModule* module
) {
    U32 tableIndex = 0;
    for (; tableIndex < module->tableImports.length; tableIndex++) {
        fputs("extern wasmTable ", file);
        wasmCWriteFileTableName(file, module, tableIndex, false);
        fputs(";\n\n", file);
    }
}

static
void
wasmCWriteTables(
    FILE* file,
    const WasmModule* module
) {
    U32 tableIndex = 0;
    for (; tableIndex < module->tables.count; tableIndex++) {
        fputs("static wasmTable ", file);
        wasmCWriteFileTableName(file, module, module->tableImports.length + tableIndex, false);
        fputs(";\n\n", file);
    }
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteInitTables(
    FILE* file,
    const WasmModule* module
) {
    fputs("static void initTables(void) {\n", file);

    if (module->elementSegments.count > 0) {
        fputs("    U32 offset;\n", file);
    }

    {
        U32 tableIndex = 0;
        for (; tableIndex < module->tables.count; tableIndex++) {
            WasmTable table = module->tables.tables[tableIndex];

            fputs("    wasmAllocateTable(", file);
            wasmCWriteFileTableName(file, module, module->tableImports.length + tableIndex, true);
            fprintf(file, ", %u, %u);\n", table.min, table.max);
        }
    }


    {
        U32 elementSegmentIndex = 0;
        for (; elementSegmentIndex < module->elementSegments.count; elementSegmentIndex++) {
            WasmElementSegment elementSegment = module->elementSegments.elementSegments[elementSegmentIndex];

            fputs("    offset = ", file);
            {
                Buffer code = elementSegment.offset;
                StringBuilder stringBuilder = emptyStringBuilder;

                MUST (stringBuilderInitialize(&stringBuilder))
                MUST (wasmCWriteConstantExpr(&stringBuilder, module, code))
                fputs(stringBuilder.string, file);
                stringBuilderFree(&stringBuilder);
            }
            fputs(";\n", file);

            {
                U32 functionIndexIndex = 0;
                for (; functionIndexIndex < elementSegment.functionIndexCount; functionIndexIndex++) {
                    U32 functionIndex = elementSegment.functionIndices[functionIndexIndex];
                    fputs("    ", file);
                    wasmCWriteFileTableName(file, module, elementSegment.tableIndex, false);
                    fprintf(file, ".data[offset + %u] = (wasmFunc)(", functionIndexIndex);
                    wasmCWriteFileFunctionName(file, module, functionIndex, true);
                    fputs(");\n", file);
                }
            }
        }
    }

    fputs("}\n\n", file);

    return true;
}

bool
WARN_UNUSED_RESULT
wasmCWriteModule(
    FILE* file,
    const WasmModule* module
) {
    fputs("#include \"w2c2_base.h\"\n\n", file);

    /* Functions */

    wasmCWriteFunctionImports(file, module);

    MUST (wasmCWriteFunctionDeclarations(file, module))

    /* Memories */

    wasmCWriteDataSegments(file, module);

    wasmCWriteMemoryImports(file, module);

    wasmCWriteMemories(file, module);
    MUST (wasmCWriteInitMemories(file, module))

    /* Tables */

    wasmCWriteTableImports(file, module);

    wasmCWriteTables(file, module);
    MUST (wasmCWriteInitTables(file, module))

    /* Globals */

    wasmCWriteGlobalImports(file, module);

    wasmCWriteGlobals(file, module);
    MUST (wasmCWriteInitGlobals(file, module))

    /* Exports */

    wasmCWriteExports(file, module);
    wasmCWriteInitExports(file, module);

    /* Code */

    MUST (wasmCWriteFunctionImplementations(file, module))

    fputs("void init(void) {\n", file);
    fputs("    initMemories();\n", file);
    fputs("    initTables();\n", file);
    fputs("    initGlobals();\n", file);
    fputs("    initExports();\n", file);
    if (module->hasStartFunction) {
        fputs("    ", file);
        wasmCWriteFileFunctionName(file, module, module->startFunctionIndex, false);
        fputs("();\n", file);
    }
    fputs("}\n", file);

    return true;
}
