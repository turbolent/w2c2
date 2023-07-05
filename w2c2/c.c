#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#if HAS_PTHREAD
  #include <pthread.h>
#endif /* HAS_PTHREAD */
#if HAS_UNISTD
#include <unistd.h>
#endif /* HAS_UNISTD */
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
        char c = *p;
        if (c == '_') {
            /*
             * Double underscore is reserved for concatenating module name and import name,
             * so produce triple underscore instead.
             */
            bool wasUnderscore = p != name && *(p-1) == '_';
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
        char c = *p;
        if (c == '_') {
            /*
             * Double underscore is reserved for concatenating module name and import name,
             * so produce triple underscore instead.
             */
            bool wasUnderscore = p != name && *(p-1) == '_';
            if (wasUnderscore) {
                MUST (stringBuilderAppend(builder, "__"))
            } else {
                MUST (stringBuilderAppendChar(builder, c))
            }
        } else if (c != escapeChar && isalnum(c)) {
            MUST (stringBuilderAppendChar(builder, c))
        } else {
            MUST (stringBuilderAppendChar(builder, escapeChar))
            MUST (stringBuilderAppendU8Hex(builder, c))
        }
    }
    return true;
}

static
W2C2_INLINE
void
wasmCWriteFileGlobalNonImportName(
    FILE* file,
    U32 globalIndex
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
    U32 globalIndex,
    bool reference
) {
    if (globalIndex < module->globalImports.length) {
        WasmGlobalImport import = module->globalImports.imports[globalIndex];
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
    U32 globalIndex,
    bool reference
) {
    if (globalIndex < module->globalImports.length) {
        WasmGlobalImport import = module->globalImports.imports[globalIndex];
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
    U32 memoryIndex
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
    U32 memoryIndex,
    bool reference
) {
    if (memoryIndex < module->memoryImports.length) {
        WasmMemoryImport import = module->memoryImports.imports[memoryIndex];
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
        wasmCWriteFileMemoryNonImportName(file, memoryIndex);
    }
}

static
W2C2_INLINE
bool
WARN_UNUSED_RESULT
wasmCWriteStringMemoryUse(
    StringBuilder* builder,
    const WasmModule* module,
    U32 memoryIndex,
    bool reference
) {
    if (memoryIndex < module->memoryImports.length) {
        WasmMemoryImport import = module->memoryImports.imports[memoryIndex];
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
        MUST (stringBuilderAppendChar(builder, memoryNamePrefix))
        MUST (stringBuilderAppendU32(builder, memoryIndex))
    }
    return true;
}

static
void
wasmCWriteFileTableNonImportName(
    FILE* file,
    U32 tableIndex
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
    U32 tableIndex,
    bool reference
) {
    if (tableIndex < module->tableImports.length) {
        WasmTableImport import = module->tableImports.imports[tableIndex];
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
    U32 tableIndex,
    bool reference
) {
    if (tableIndex < module->tableImports.length) {
        WasmTableImport import = module->tableImports.imports[tableIndex];
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

static
W2C2_INLINE
void
wasmCWriteFileFunctionNonImportName(
    FILE* file,
     U32 functionIndex
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
    U32 functionIndex,
    bool reference,
    bool prefix
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
    U32 functionIndex,
    bool reference,
    bool prefix
) {
    if (reference) {
        MUST (stringBuilderAppendChar(builder, '&'))
    }
    if (prefix) {
        MUST (stringBuilderAppend(builder, moduleName))
        MUST (stringBuilderAppendChar(builder, '_'))
    }
    if (functionIndex < module->functionImports.length) {
        WasmFunctionImport import = module->functionImports.imports[functionIndex];
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
    bool pretty
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
    WasmCFunctionWriter* writer
) {
    if (writer->pretty) {
        StringBuilder* builder = writer->builder;
        U32 indent = writer->indent;
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
    WasmCFunctionWriter* writer,
    const char* string
) {
    return stringBuilderAppend(writer->builder, string);
}


static
W2C2_INLINE
bool
WARN_UNUSED_RESULT
wasmCWriteChar(
    WasmCFunctionWriter* writer,
    char c
) {
    return stringBuilderAppendChar(writer->builder, c);
}

static
W2C2_INLINE
bool
WARN_UNUSED_RESULT
wasmCWriteAssign(
    WasmCFunctionWriter* writer
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
    WasmCFunctionWriter* writer
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
    WasmCFunctionWriter* writer
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
    WasmCFunctionWriter* writer
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

                U32 resultStackIndex = writer->typeStack->length;
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
                    U32 paramStackIndex = wasmTypeStackGetTopIndex(
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
    WasmCFunctionWriter* writer,
    WasmFunctionType functionType
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
    WasmCFunctionWriter* writer
) {
    WasmCallIndirectInstruction instruction;
    if (!wasmCallIndirectInstructionRead(writer->code, &instruction)) {
        fprintf(stderr, "w2c2: invalid call_indirect instruction encoding\n");
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
                U32 paramStackIndex = wasmTypeStackGetTopIndex(
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
    WasmCFunctionWriter* writer
) {
    static const WasmOpcode opcode = wasmOpcodeLocalGet;

    WasmLocalInstruction instruction;
    if (!wasmLocalInstructionRead(writer->code, opcode, &instruction)) {
        fprintf(stderr, "w2c2: invalid local.get instruction encoding\n");
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
                "w2c2: invalid local.get instruction: invalid local index: %u\n",
                instruction.localIndex
            );
            return false;
        }
        MUST (wasmTypeStackAppend(writer->typeStack, localType))
        {
            U32 stackIndex0 = wasmTypeStackGetTopIndex(writer->typeStack, 0);
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
    WasmCFunctionWriter* writer,
    const WasmOpcode opcode
) {
    WasmLocalInstruction instruction;
    if (!wasmLocalInstructionRead(writer->code, opcode, &instruction)) {
        fprintf(
            stderr,
            "w2c2: invalid %s instruction encoding\n",
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
                "w2c2: invalid %s instruction: invalid local index: %u\n",
                wasmOpcodeDescription(opcode),
                instruction.localIndex
            );
            return false;
        }
        {
            U32 stackIndex0 = wasmTypeStackGetTopIndex(writer->typeStack, 0);
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
    WasmCFunctionWriter* writer
) {
    static const WasmOpcode opcode = wasmOpcodeGlobalGet;

    WasmGlobalInstruction instruction;
    if (!wasmGlobalInstructionRead(writer->code, opcode, &instruction)) {
        fprintf(
            stderr,
            "w2c2: invalid %s instruction encoding\n",
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
                "w2c2: invalid %s instruction: invalid global index: %u\n",
                wasmOpcodeDescription(opcode),
                instruction.globalIndex
            );
            return false;
        }
        MUST (wasmTypeStackAppend(writer->typeStack, globalType))
        {
            U32 stackIndex0 = wasmTypeStackGetTopIndex(writer->typeStack, 0);
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
    WasmCFunctionWriter* writer
) {
    static const WasmOpcode opcode = wasmOpcodeGlobalSet;

    WasmGlobalInstruction instruction;
    if (!wasmGlobalInstructionRead(writer->code, opcode, &instruction)) {
        fprintf(
            stderr,
            "w2c2: invalid %s instruction encoding\n",
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
                "w2c2: invalid %s instruction: invalid global index: %u\n",
                wasmOpcodeDescription(opcode),
                instruction.globalIndex
            );
            return false;
        }
        {
            U32 stackIndex0 = wasmTypeStackGetTopIndex(writer->typeStack, 0);
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
    WasmValueType valueType,
    WasmValue value
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
            U32 bits = (U32) value.i32;
            if ((bits & 0x7f800000U) == 0x7f800000U) {
                bool is_negative = (bits & 0x80000000U);
                U32 significand = bits & 0x7fffffU;
                if (significand == 0) {
                    if (is_negative) {
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
            U64 bits = (U64) value.i64;
            if ((bits & 0x7ff0000000000000ULL) == 0x7ff0000000000000ULL) {
                bool is_negative = (bits & 0x8000000000000000ULL);
                U64 significand = bits & 0x7fffffULL;
                if (significand == 0) {
                    if (is_negative) {
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
    WasmCFunctionWriter* writer,
    const WasmOpcode opcode
) {
    WasmConstInstruction instruction;
    if (!wasmConstInstructionRead(writer->code, opcode, &instruction)) {
        fprintf(stderr, "w2c2: invalid const instruction encoding\n");
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
wasmCWriteLoadExpr(
    WasmCFunctionWriter* writer,
    const WasmOpcode opcode
) {
    WasmLoadStoreInstruction instruction;
    WasmValueType resultType = 0;

    if (!wasmLoadStoreInstructionRead(writer->code, opcode, &instruction)) {
        fprintf(stderr, "w2c2: invalid load instruction encoding\n");
        return false;
    }

    if (!writer->ignore) {
        const char* functionName = NULL;
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

        {
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
        fprintf(stderr, "w2c2: invalid store instruction encoding\n");
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
                    "w2c2: unsupported store instruction opcode: %s\n",
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
        }
    }

    return true;
}

static
bool
WARN_UNUSED_RESULT
wasmCWriteMemorySize(
    WasmCFunctionWriter* writer
) {
    static const WasmOpcode opcode = wasmOpcodeMemorySize;

    WasmMemoryInstruction instruction;
    if (!wasmMemoryInstructionRead(writer->code, opcode, &instruction)) {
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
wasmCWriteMemoryGrow(
    WasmCFunctionWriter* writer
) {
    static const WasmOpcode opcode = wasmOpcodeMemoryGrow;

    WasmMemoryInstruction instruction;
    if (!wasmMemoryInstructionRead(writer->code, opcode, &instruction)) {
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
wasmCWriteMemoryCopy(
    WasmCFunctionWriter* writer
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
        MUST (wasmCWrite(writer, "wasmMemoryCopy(\n"))
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
wasmCWriteMemoryFill(
    WasmCFunctionWriter* writer,
    WasmMiscOpcode miscOpcode
) {
    WasmMiscMemoryInstruction instruction;
    if (!wasmMiscMemoryInstructionRead(writer->code, miscOpcode, &instruction)) {
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
        MUST (wasmCWrite(writer, "wasmMemoryFill(\n"))
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
    WasmCFunctionWriter* writer,
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
    WasmCFunctionWriter* writer,
    const WasmValueType resultType,
    const char* operator,
    bool assignmentAllowed
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
    WasmCFunctionWriter* writer,
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

    WasmValueType blockValueType = 0;
    WasmValueType* blockType = &blockValueType;
    if (!wasmReadBlockType(writer->code, &blockType)) {
        fprintf(stderr, "w2c2: invalid if instruction: expected block type\n");
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
    bool ignore = writer->ignore;

    size_t typeStackLengthBeforeBranches = 0;
    WasmLabel label = wasmEmptyLabel;

    WasmValueType blockValueType = 0;
    WasmValueType* blockType = &blockValueType;
    if (!wasmReadBlockType(writer->code, &blockType)) {
        fprintf(stderr, "w2c2: invalid block instruction: expected block type\n");
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
    bool ignore = writer->ignore;

    size_t typeStackLengthBeforeBranches = 0;
    WasmLabel label = wasmEmptyLabel;

    WasmValueType blockValueType = 0;
    WasmValueType* blockType = &blockValueType;
    if (!wasmReadBlockType(writer->code, &blockType)) {
        fprintf(stderr, "w2c2: invalid loop instruction: expected block type\n");
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
    WasmCFunctionWriter* writer,
    U32 labelStackIndex
) {
    WasmLabel label = writer->labelStack->labels.labels[labelStackIndex];

    MUST (wasmCWriteIndent(writer))

    if (label.type != NULL) {
        WasmValueType resultType = *label.type;

        const U32 stackIndex0 = wasmTypeStackGetTopIndex(writer->typeStack, 0);
        const U32 destinationStackIndex = label.typeStackLength;

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
    WasmCFunctionWriter* writer
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
    WasmCFunctionWriter* writer
) {
    static const WasmOpcode opcode = wasmOpcodeBr;

    WasmBranchInstruction instruction;
    if (!wasmBranchInstructionRead(writer->code, opcode, &instruction)) {
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
    static const WasmOpcode opcode = wasmOpcodeBrIf;

    WasmBranchInstruction instruction;
    if (!wasmBranchInstructionRead(writer->code, opcode, &instruction)) {
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
    WasmDebugLine* debugLine

) {
    MUST (stringBuilderAppend(builder, "#line "))
    MUST (stringBuilderAppendU32(builder, debugLine->number))
    MUST (stringBuilderAppend(builder, " \""))
    MUST (stringBuilderAppend(builder, debugLine->path))
    MUST (stringBuilderAppend(builder, "\"\n"))
    return true;
}


static
WasmDebugLine*
wasmCGetDebugLine(
    WasmDebugLines* debugLines,
    size_t absoluteAddress
) {
    WasmDebugLine* debugLine = NULL;
    if (debugLines->length == 0) {
        return NULL;
    }

    debugLine = debugLines->debugLines;

    if (debugLines->length > 1) {
        WasmDebugLine* nextDebugLine = debugLine + 1;
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
wasmCWriteFunctionCode(
    WasmCFunctionWriter* writer,
    WasmOpcode* opcode
) {
    while (true) {
        if (writer->debug) {
            size_t relativeAddress = writer->function.code.length - writer->code->length;
            size_t absoluteAddress = writer->function.start + relativeAddress;
            WasmDebugLine* debugLine = wasmCGetDebugLine(
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
                MUST (wasmCWriteMemorySize(writer))
                break;
            }
            case wasmOpcodeMemoryGrow: {
                MUST (wasmCWriteMemoryGrow(writer))
                break;
            }
            case wasmOpcodeMiscPrefix: {
                WasmMiscOpcode miscOpcode = 0;
                MUST (leb128ReadU32(writer->code, &miscOpcode) > 0)

                switch (miscOpcode) {
                    case wasmMiscOpcodeMemoryInit: {
                        /* TODO: refactor into instruction read function */
                        U32 dataIndex = 0;
                        U8 memoryIndex = 0;
                        MUST (leb128ReadU32(writer->code, &dataIndex) > 0)
                        MUST (bufferReadByte(writer->code, &memoryIndex) > 0)
                        break;
                    }
                    case wasmMiscOpcodeDataDrop: {
                        /* TODO: refactor into instruction read function */
                        U32 dataIndex = 0;
                        MUST (leb128ReadU32(writer->code, &dataIndex) > 0)
                        break;
                    }
                    case wasmMiscOpcodeMemoryCopy: {
                        MUST (wasmCWriteMemoryCopy(writer))
                        continue;
                    }
                    case wasmMiscOpcodeMemoryFill: {
                        MUST (wasmCWriteMemoryFill(writer, miscOpcode))
                        continue;
                    }
                    case wasmMiscOpcodeTableInit: {
                        /* TODO: refactor into instruction read function */
                        U32 elemIndex = 0;
                        U32 tableIndex = 0;
                        MUST (leb128ReadU32(writer->code, &elemIndex) > 0)
                        MUST (leb128ReadU32(writer->code, &tableIndex) > 0)
                        break;
                    }
                    case wasmMiscOpcodeElemDrop: {
                        /* TODO: refactor into instruction read function */
                        U32 elemIndex = 0;
                        MUST (leb128ReadU32(writer->code, &elemIndex) > 0)
                        break;
                    }
                    case wasmMiscOpcodeTableCopy: {
                        /* TODO: refactor into instruction read function */
                        U32 tableIndex1 = 0;
                        U32 tableIndex2 = 0;
                        MUST (leb128ReadU32(writer->code, &tableIndex1) > 0)
                        MUST (leb128ReadU32(writer->code, &tableIndex2) > 0)
                        break;
                    }
                    case wasmMiscOpcodeTableGrow: {
                        /* TODO: refactor into instruction read function */
                        U32 tableIndex = 0;
                        MUST (leb128ReadU32(writer->code, &tableIndex) > 0)
                        break;
                    }
                    case wasmMiscOpcodeTableSize: {
                        /* TODO: refactor into instruction read function */
                        U32 tableIndex = 0;
                        MUST (leb128ReadU32(writer->code, &tableIndex) > 0)
                        break;
                    }
                    case wasmMiscOpcodeTableFill: {
                        /* TODO: refactor into instruction read function */
                        U32 tableIndex = 0;
                        MUST (leb128ReadU32(writer->code, &tableIndex) > 0)
                        break;
                    }
                    default:
                        break;
                }

                if (!writer->ignore) {
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
    bool pretty
) {
    WasmValueType testType = 0;
    for (; testType < wasmValueType_count; testType++) {
        U32 written = 0;

        U32 stackDeclarationIndex = 0;
        for (; stackDeclarationIndex < stackDeclarations->length; stackDeclarationIndex++) {
            WasmValueType entry = stackDeclarations->valueTypes[stackDeclarationIndex];
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
    bool pretty,
    bool debug,
    bool multipleModules
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
    WasmFunctionType functionType,
    bool writeParameterNames,
    bool structInstanceType,
    bool pretty
) {
    fputc('(', file);
    if (structInstanceType) {
        fputs("struct ", file);
    }
    fputs(moduleName, file);
    fputs("Instance*", file);
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
    bool writeParameterNames,
    bool pretty,
    bool prefix
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
    wasmCWriteFileParameters(file, moduleName, functionType, writeParameterNames, false, pretty);
}

static
void
wasmCWriteFunctionDeclarations(
    FILE* file,
    const WasmModule* module,
    const char* moduleName,
    bool pretty,
    bool debug,
    bool multipleModules
) {
    const size_t functionImportCount = module->functionImports.length;
    const U32 functionCount = module->functions.count;

    U32 functionIndex = 0;
    for (; functionIndex < functionCount; functionIndex++) {
        const WasmFunction function = module->functions.functions[functionIndex];
        wasmCWriteFileFunctionSignature(
            file,
            module,
            moduleName,
            function,
            functionImportCount + functionIndex,
            false,
            pretty,
            multipleModules
        );
        if (debug && functionIndex < module->functionNames.length) {
            char *functionName = module->functionNames.names[functionIndex];
            if (functionName != NULL) {
                fprintf(file," __asm__(\"%s_%s\")", moduleName, functionName);
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
    const char *moduleName,
    WasmDebugLines* debugLines,
    U32 startIndex,
    U32 endIndex,
    bool pretty,
    bool debug,
    bool multipleModules
) {
    const size_t functionImportCount = module->functionImports.length;

    WasmTypeStack typeStack = wasmEmptyTypeStack;
    WasmTypeStack stackDeclarations = wasmEmptyTypeStack;
    WasmLabelStack labelStack = wasmEmptyLabelStack;

    U32 functionIndex = startIndex;
    for (; functionIndex < endIndex; functionIndex++) {
        const WasmFunction function = module->functions.functions[functionIndex];

        wasmTypeStackClear(&typeStack);
        wasmTypeStackClear(&stackDeclarations);
        wasmLabelStackClear(&labelStack);

        if (debug) {
            WasmDebugLine* debugLine = wasmCGetDebugLine(debugLines, function.start);
            if (debugLine != NULL) {
                fprintf(file, "#line %u \"%s\"\n", (U32)debugLine->number, debugLine->path);
            }
        }

        wasmCWriteFileFunctionSignature(
            file,
            module,
            moduleName,
            function,
            functionImportCount + functionIndex,
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
    WasmGlobalImport import
) {
    fputs(valueTypeNames[import.globalType.valueType], file);
    fputc('*', file);
}

static
void
wasmCWriteGlobalImports(
    FILE* file,
    const WasmModule* module,
    bool pretty
) {
    const size_t globalImportCount = module->globalImports.length;
    U32 globalIndex = 0;
    for (; globalIndex < globalImportCount; globalIndex++) {
        WasmGlobalImport import = module->globalImports.imports[globalIndex];
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
    bool pretty
) {
    const size_t globalImportCount = module->globalImports.length;
    const U32 globalCount = module->globals.count;

    U32 globalIndex = 0;
    for (; globalIndex < globalCount; globalIndex++) {
        WasmGlobal global = module->globals.globals[globalIndex];
        if (pretty) {
            fputs(indentation, file);
        }
        fputs(valueTypeNames[global.type.valueType], file);
        fputc(' ', file);
        wasmCWriteFileGlobalNonImportName(file, globalImportCount + globalIndex);
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
            WasmValueType resultType = wasmOpcodeResultType(opcode);
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
            MUST (wasmGlobalInstructionRead(&code, opcode, &instruction))
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
    bool pretty
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
                WasmGlobal global = module->globals.globals[globalIndex];

                if (pretty) {
                    fputs(indentation, file);
                }
                wasmCWriteFileGlobalUse(file, module, globalImportCount + globalIndex, false);
                if (pretty) {
                    fputs(" = ", file);
                } else {
                    fputc('=', file);
                }
                {
                    Buffer code = global.init;
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
    bool pretty
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
    WasmFunctionImport import,
    bool declaration,
    bool pretty,
    bool prefix
) {
    WasmFunctionType functionType = module->functionTypes.functionTypes[import.functionTypeIndex];
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
wasmCWriteInitFunctionImports(
    FILE* file,
    const WasmModule* module,
    const char* moduleName,
    bool pretty,
    bool multipleModules
) {
    const U32 functionImportCount = module->functionImports.length;
    U32 functionIndex = 0;
    for (; functionIndex < functionImportCount; functionIndex++) {
        const WasmFunctionImport import = module->functionImports.imports[functionIndex];
        wasmCWriteInitImportAssignment(file, import.module, import.name, pretty);
        fputc('(', file);
        wasmCWriteFunctionImport(file, module, moduleName, import, false, pretty, multipleModules);
        fputc(')', file);
        wasmCWriteInitImportValue(file, import.module, import.name);
    }
}

static
void
wasmCWriteInitGlobalImports(
    FILE* file,
    const WasmModule* module,
    bool pretty
) {
    const size_t globalImportCount = module->globalImports.length;
    U32 globalIndex = 0;
    for (; globalIndex < globalImportCount; globalIndex++) {
        WasmGlobalImport import = module->globalImports.imports[globalIndex];
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
    bool pretty
) {
    const size_t memoryImportCount = module->memoryImports.length;

    U32 memoryIndex = 0;
    for (; memoryIndex < memoryImportCount; memoryIndex++) {
        WasmMemoryImport import = module->memoryImports.imports[memoryIndex];
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
    bool pretty
) {
    const size_t tableImportCount = module->tableImports.length;

    U32 tableIndex = 0;
    for (; tableIndex < tableImportCount; tableIndex++) {
        WasmTableImport import = module->tableImports.imports[tableIndex];
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
    bool pretty,
    bool multipleModules
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
    WasmExport export,
    WasmFunctionType functionType,
    bool writeBody,
    bool pretty,
    bool multipleModules
) {
    const U32 parameterCount = functionType.parameterCount;

    fputs(wasmCGetReturnType(functionType), file);
    fputc(' ', file);
    wasmCWriteExportName(file, moduleName, export.name);
    wasmCWriteFileParameters(file, moduleName, functionType, true, false, pretty);
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
    WasmExport export,
    bool writeBody,
    bool pretty
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
        wasmCWriteFileMemoryUse(file, module, export.index, true);
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
    bool writeBody,
    bool pretty,
    bool multipleModules
) {
    const size_t functionImportCount = module->functionImports.length;
    const U32 exportCount = module->exports.count;

    U32 exportIndex = 0;
    for (; exportIndex < exportCount; exportIndex++) {
        WasmExport export = module->exports.exports[exportIndex];
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

static
void
wasmCWriteDataSegmentsAsArrays(
    FILE* file,
    const WasmModule* module,
    bool pretty
) {
    const U32 dataSegmentCount = module->dataSegments.count;

    U32 dataSegmentIndex = 0;
    for (; dataSegmentIndex < dataSegmentCount; dataSegmentIndex++) {
        WasmDataSegment dataSegment = module->dataSegments.dataSegments[dataSegmentIndex];

        if (!dataSegment.bytes.length) {
            continue;
        }

        fputs("const U8 ", file);
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
    }
}

static
void
wasmCWriteDataSegmentsAsSection(
    FILE* file,
    const WasmModule* module,
    WasmDataSegmentMode mode
) {
    static char* const filename = "datasegments";
    const U32 dataSegmentCount = module->dataSegments.count;

    U32 dataSegmentIndex = 0;
    FILE* segmentsFile = NULL;

    switch (mode) {
        case wasmDataSegmentModeGNULD: {
            fputs("extern char _binary_datasegments_start[];\n\n", file);
            break;
        }
        case wasmDataSegmentModeSectcreate1: {
            fputs("extern char datasegments __asm(\"section$start$__DATA$__datasegments\");\n\n", file);
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
        WasmDataSegment dataSegment = module->dataSegments.dataSegments[dataSegmentIndex];
        size_t length = dataSegment.bytes.length;
        size_t written = fwrite(dataSegment.bytes.data, 1, length, segmentsFile);
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
wasmCWriteDataSegments(
    FILE* file,
    const WasmModule* module,
    WasmDataSegmentMode mode,
    bool pretty
) {
    switch (mode) {
        case wasmDataSegmentModeArrays: {
            wasmCWriteDataSegmentsAsArrays(file, module, pretty);
            break;
        }
        case wasmDataSegmentModeGNULD:
        case wasmDataSegmentModeSectcreate1:
        case wasmDataSegmentModeSectcreate2: {
            wasmCWriteDataSegmentsAsSection(file, module, mode);
            break;
        }
        default: {
            fprintf(stderr, "w2c2: unsupported data segment mode: %d\n", mode);
            abort();
        }
    }
}

static
void
wasmCWriteMemoryImports(
    FILE* file,
    const WasmModule* module,
    bool pretty
) {
    const size_t memoryImportCount = module->memoryImports.length;

    U32 memoryIndex = 0;
    for (; memoryIndex < memoryImportCount; memoryIndex++) {
        WasmMemoryImport import = module->memoryImports.imports[memoryIndex];
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
    bool pretty
) {
    const size_t memoryImportCount = module->memoryImports.length;
    const U32 memoryCount = module->memories.count;

    U32 memoryIndex = 0;
    for (; memoryIndex < memoryCount; memoryIndex++) {
        if (pretty) {
            fputs(indentation, file);
        }
        fputs("wasmMemory ", file);
        wasmCWriteFileMemoryNonImportName(file, memoryImportCount + memoryIndex);
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
    WasmDataSegmentMode dataSegmentMode,
    bool pretty
) {
    const size_t memoryImportCount = module->memoryImports.length;
    const U32 memoryCount = module->memories.count;
    if (memoryCount > 0) {

        StringBuilder stringBuilder = emptyStringBuilder;
        MUST (stringBuilderInitialize(&stringBuilder))

        fprintf(file, "static void %sInitMemories(%sInstance* i) {\n", moduleName, moduleName);

        switch (dataSegmentMode) {
            case wasmDataSegmentModeGNULD: {
                fputs("static char* ds = _binary_datasegments_start;\n", file);
                break;
            }
            case wasmDataSegmentModeSectcreate1: {
                fputs("static char* ds = &datasegments;\n", file);
                break;
            }
            case wasmDataSegmentModeSectcreate2: {
                fputs(
                    "SECT_DATA_SIZE_TYPE len = 0;\n"
                    "char* ds = getsectdata(\"__DATA\", \"__datasegments\", &len);\n",
                    file
                );
                break;
            }
            default:
                break;
        }

        {
            U32 memoryIndex = 0;
            for (; memoryIndex < memoryCount; memoryIndex++) {
                WasmMemory memory = module->memories.memories[memoryIndex];

                if (pretty) {
                    fputs(indentation, file);
                }
                fputs("wasmMemoryAllocate(", file);
                wasmCWriteFileMemoryUse(file, module, memoryImportCount + memoryIndex, true);
                fprintf(file, ", %u, %u);\n", memory.min, memory.max);
            }
        }

        {
            const U32 dataSegmentCount = module->dataSegments.count;
            size_t dataSegmentOffset = 0;
            U32 dataSegmentIndex = 0;
            for (; dataSegmentIndex < dataSegmentCount; dataSegmentIndex++) {
                WasmDataSegment dataSegment = module->dataSegments.dataSegments[dataSegmentIndex];

                if (!dataSegment.bytes.length) {
                    continue;
                }

                if (pretty) {
                    fputs(indentation, file);
                }
                fputs("LOAD_DATA(", file);
                wasmCWriteFileMemoryUse(file, module, dataSegment.memoryIndex, false);
                fputs(", ", file);
                {
                    Buffer code = dataSegment.offset;
                    MUST (stringBuilderReset(&stringBuilder))

                    MUST (wasmCWriteConstantExpr(&stringBuilder, module, code))
                    fputs(stringBuilder.string, file);
                }
                fputs(", ", file);

                switch (dataSegmentMode) {
                    case wasmDataSegmentModeArrays: {
                        wasmCWriteFileDataSegmentName(file, dataSegmentIndex);
                        break;
                    }
                    case wasmDataSegmentModeGNULD:
                    case wasmDataSegmentModeSectcreate1:
                    case wasmDataSegmentModeSectcreate2: {
                        fprintf(file, "ds + %lu", (unsigned long) dataSegmentOffset);
                        break;
                    }
                    default: {
                        fprintf(stderr, "w2c2: unsupported data segment mode: %d\n", dataSegmentMode);
                    }

                }

                fprintf(file, ", %lu);\n", (unsigned long) dataSegment.bytes.length);

                dataSegmentOffset += dataSegment.bytes.length;
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
    bool pretty
) {
    const size_t memoryImportCount = module->memoryImports.length;
    const U32 memoryCount = module->memories.count;
    U32 memoryIndex = 0;
    for (; memoryIndex < memoryCount; memoryIndex++) {
        if (pretty) {
            fputs(indentation, file);
        }
        fputs("wasmMemoryFree(", file);
        wasmCWriteFileMemoryUse(file, module, memoryImportCount + memoryIndex, true);
        fputs(");\n", file);
    }
}

static
void
wasmCWriteTableImports(
    FILE* file,
    const WasmModule* module,
    bool pretty
) {
    const size_t tableImportCount = module->tableImports.length;

    U32 tableIndex = 0;
    for (; tableIndex < tableImportCount; tableIndex++) {
        WasmTableImport import = module->tableImports.imports[tableIndex];
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
    bool pretty
) {
    const size_t tableImportCount = module->tableImports.length;
    const U32 tableCount = module->tables.count;

    U32 tableIndex = 0;
    for (; tableIndex < tableCount; tableIndex++) {
        if (pretty) {
            fputs(indentation, file);
        }
        fputs("wasmTable ", file);
        wasmCWriteFileTableNonImportName(file, tableImportCount + tableIndex);
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
    bool pretty,
    bool multipleModules
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
                WasmTable table = module->tables.tables[tableIndex];

                if (pretty) {
                    fputs(indentation, file);
                }
                fputs("wasmTableAllocate(", file);
                wasmCWriteFileTableUse(file, module, tableImportCount + tableIndex, true);
                fprintf(file, ", %u, %u);\n", table.min, table.max);
            }
        }

        {
            U32 elementSegmentIndex = 0;
            for (; elementSegmentIndex < elementSegmentCount; elementSegmentIndex++) {
                WasmElementSegment elementSegment = module->elementSegments.elementSegments[elementSegmentIndex];

                if (pretty) {
                    fputs(indentation, file);
                    fputs("offset = ", file);
                } else {
                    fputs("offset=", file);
                }
                {
                    Buffer code = elementSegment.offset;
                    MUST (stringBuilderReset(&stringBuilder))
                    MUST (wasmCWriteConstantExpr(&stringBuilder, module, code))
                    fputs(stringBuilder.string, file);
                }
                fputs(";\n", file);

                {
                    U32 functionIndexIndex = 0;
                    for (; functionIndexIndex < elementSegment.functionIndexCount; functionIndexIndex++) {
                        U32 functionIndex = elementSegment.functionIndices[functionIndexIndex];
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
    bool pretty
) {
    const size_t tableImportCount = module->tableImports.length;
    const U32 tableCount = module->tables.count;
    U32 tableIndex = 0;
    for (; tableIndex < tableCount; tableIndex++) {
        if (pretty) {
            fputs(indentation, file);
        }
        fputs("wasmTableFree(", file);
        wasmCWriteFileTableUse(file, module, tableImportCount + tableIndex, true);
        fputs(");\n", file);
    }
}

static
void
wasmCWriteFunctionImports(
    FILE* file,
    const WasmModule* module,
    const char* moduleName,
    bool pretty,
    bool multipleModules
) {
    const U32 functionImportCount = module->functionImports.length;
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
    bool pretty
) {
    fprintf(file, "typedef struct %sInstance {\n", moduleName);

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
    bool pretty,
    bool debug,
    bool multipleModules
) {
    wasmCWriteModuleInstanceDeclaration(file, module, moduleName, pretty);
    wasmCWriteFunctionImports(file, module, moduleName, pretty, multipleModules);
    wasmCWriteFunctionDeclarations(file, module, moduleName, pretty, debug, multipleModules);
    wasmCWriteExports(file, module, moduleName, false, pretty, multipleModules);
}

static
void
wasmCWriteInstantiateFunction(
    FILE* file,
    const WasmModule* module,
    const char* moduleName,
    bool pretty,
    bool multipleModules
) {
    fprintf(
        file,
        "void %sInstantiate(%sInstance* i, void* resolve(const char* module, const char* name)) {\n",
        moduleName,
        moduleName
    );

    if (pretty) {
        fputs(indentation, file);
    }
    fprintf(file, "%sInitImports(i, resolve);\n", moduleName);

    if (module->memories.count > 0) {
        if (pretty) {
            fputs(indentation, file);
        }
        fprintf(file, "%sInitMemories(i);\n", moduleName);
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
    bool pretty
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
    bool pretty,
    bool debug,
    bool multipleModules
) {
    /* Create file */
    FILE *file = NULL;

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
wasmCWriteInits(
    const WasmModule* module,
    const char* moduleName,
    FILE* file,
    WasmDataSegmentMode dataSegmentMode,
    bool pretty,
    bool multipleModules
) {
    wasmCWriteDataSegments(file, module, dataSegmentMode, pretty);

    MUST (wasmCWriteInitMemories(file, module, moduleName, dataSegmentMode, pretty))
    MUST (wasmCWriteInitTables(file, module, moduleName, pretty, multipleModules))
    MUST (wasmCWriteInitGlobals(file, module, moduleName, pretty))
    MUST (wasmCWriteInitImports(file, module, moduleName, pretty, multipleModules))

    wasmCWriteExports(file, module, moduleName, true, pretty, multipleModules);

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
    U32 fileIndex,
    U32 functionsPerFile,
    FILE* file,
    U32 startFunctionIndex,
    bool pretty,
    bool debug,
    bool multipleModules
) {
    char filename[13];
    U32 functionCount = module->functions.count;
    bool separate = file == NULL;

    U32 endFunctionIndex = startFunctionIndex + functionsPerFile;
    if (endFunctionIndex > functionCount) {
        endFunctionIndex = functionCount;
    }

    /* Do not create empty files */
    if (startFunctionIndex > endFunctionIndex) {
        return true;
    }

    if (separate) {
        sprintf(filename, "%010u.c", fileIndex);
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
    }

    {
        MUST (wasmCWriteFunctionImplementations(
            file,
            module,
            moduleName,
            debugLines,
            startFunctionIndex,
            endFunctionIndex,
            pretty,
            debug,
            multipleModules
        ))
    }

    if (separate) {
        if (fclose(file) != 0) {
            fprintf(
                stderr,
                "w2c2: failed to close implementation file: %s: %s\n",
                filename,
                strerror(errno)
            );
            return false;
        }
    }

    return true;
}

#if HAS_PTHREAD

typedef struct WasmCImplementationWriterTask {
    U32 fileIndex;
    U32 functionsPerFile;
    const WasmModule* module;
    const char* moduleName;
    const char* headerName;
    U32 startFunctionIndex;
    bool pretty;
    bool debug;
    bool multipleModules;
    bool result;
} WasmCImplementationWriterTask;

typedef struct WasmCImplementationConcurrentWriter {
    pthread_mutex_t mutex;
    pthread_cond_t consume;
    pthread_cond_t produce;
    WasmCImplementationWriterTask *task;
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
            WasmCImplementationWriterTask* task = writer->task;

            const WasmModule* module = task->module;
            const char* moduleName = task->moduleName;
            const char* headerName = task->headerName;
            U32 fileIndex = task->fileIndex;
            U32 functionsPerFile = task->functionsPerFile;
            U32 startFunctionIndex = task->startFunctionIndex;
            bool pretty = task->pretty;
            bool debug = task->debug;
            bool multipleModules = task->multipleModules;

            writer->task = NULL;

            pthread_mutex_unlock(&writer->mutex);

            {
                bool result = wasmCWriteImplementationFile(
                    module,
                    moduleName,
                    headerName,
                    NULL,
                    fileIndex,
                    functionsPerFile,
                    NULL,
                    startFunctionIndex,
                    pretty,
                    debug,
                    multipleModules
                );
                if (!result) {
                    fprintf(
                        stderr,
                        "w2c2: failed to write implementation file %d, start func %d\n",
                        fileIndex,
                        startFunctionIndex
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
    FILE* mainFile,
    WasmCWriteModuleOptions options
) {
    WasmDebugLines debugLines = module->debugLines;

    U32 fileIndex = 0;
    U32 functionCount = module->functions.count;
    U32 functionsPerFile = options.functionsPerFile;
    U32 fileCount = 0;
    if (functionCount > 0) {
        fileCount = 1 + (functionCount - 1) / functionsPerFile;
    }

    MUST (wasmCWriteImplementationFile(
        module,
        moduleName,
        headerName,
        &debugLines,
        fileIndex++,
        functionsPerFile,
        mainFile,
        0,
        options.pretty,
        options.debug,
        options.multipleModules
    ))

    {
#if HAS_PTHREAD
        U32 threadCount = options.threadCount;
        pthread_t* threads = calloc(threadCount * sizeof(pthread_t), 1);
        U32 jobIndex = 0;

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
            U32 startFunctionIndex = fileIndex * functionsPerFile;
#if HAS_PTHREAD
            pthread_mutex_lock(&writer.mutex);

            while (writer.task != NULL) {
                pthread_cond_wait(
                    &writer.produce,
                    &writer.mutex
                );
            }

            task.fileIndex = fileIndex;
            task.startFunctionIndex = startFunctionIndex;

            writer.task = &task;

            pthread_cond_signal(&writer.consume);
            pthread_mutex_unlock(&writer.mutex);

#else
            MUST (wasmCWriteImplementationFile(
                module,
                moduleName,
                headerName,
                &debugLines,
                fileIndex,
                functionsPerFile,
                NULL,
                startFunctionIndex,
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
    WasmCWriteModuleOptions options
) {
    /* Create file */
    FILE *file = NULL;

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

    /* Write implementations */

    MUST (wasmCWriteModuleImplementationFiles(
        module,
        moduleName,
        headerName,
        file,
        options
    ))

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
    WasmCWriteModuleOptions options
) {
    char outputDir[PATH_MAX];
    char outputName[PATH_MAX];
    char headerName[PATH_MAX];

    const char* outputPath = options.outputPath;

    strcpy(outputDir, outputPath);
    strcpy(outputName, outputPath);

    strcpy(outputDir, dirname(outputDir));
    strcpy(outputName, basename(outputName));

    strcpy(headerName, outputName);

    {
        char* headerExt = strrchr(headerName, '.');
        if (headerExt == NULL) {
            headerExt = headerName + strlen(headerName);
        }
        strcpy(headerExt, ".h");
    }

    /* Change to output directory */
    if (chdir(outputDir) < 0) {
        fprintf(stderr, "w2c2: failed to change to output directory %s\n", outputDir);
        return false;
    }

    MUST (wasmCWriteModuleHeader(module, moduleName, headerName, options.pretty, options.debug, options.multipleModules))
    MUST (wasmCWriteModuleImplementation(module, moduleName, outputName, headerName, options))

    return true;
}
