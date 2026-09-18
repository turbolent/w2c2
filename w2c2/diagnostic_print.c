#include "diagnostic_print.h"
#include "reader.h"

static
const char*
wasmDiagnosticOpcodeDescription(
    const WasmDiagnosticOpcodeFamily family,
    const U32 opcode
) {
    switch (family) {
        case wasmDiagnosticOpcodeUnprefixed:
            return wasmOpcodeDescription((WasmOpcode)opcode);
        case wasmDiagnosticOpcodeMisc:
            return wasmMiscOpcodeDescription((WasmMiscOpcode)opcode);
        case wasmDiagnosticOpcodeThreads:
            return wasmThreadsOpcodeDescription((WasmThreadsOpcode)opcode);
    }
    return "unknown";
}

static
const char*
threadOperationDescription(
    const WasmDiagnosticThreadOperation operation
) {
    switch (operation) {
        case wasmDiagnosticThreadMutexInitialize:
            return "initialize writer mutex";
        case wasmDiagnosticThreadConditionInitialize:
            return "initialize writer condition";
        case wasmDiagnosticThreadCreate:
            return "create writer thread";
        case wasmDiagnosticThreadJoin:
            return "join writer thread";
    }
    return "unknown operation";
}

static
const char*
dwarfOperationDescription(
    const WasmDiagnosticDwarfOperation operation
) {
    switch (operation) {
        case wasmDiagnosticDwarfAllocate:
            return "allocate debug storage";
        case wasmDiagnosticDwarfInitialize:
            return "initialize DWARF reader";
        case wasmDiagnosticDwarfChild:
            return "get child DIE";
        case wasmDiagnosticDwarfSibling:
            return "get sibling DIE";
        case wasmDiagnosticDwarfTag:
            return "get DIE tag";
        case wasmDiagnosticDwarfFiles:
            return "get CU DIE files";
        case wasmDiagnosticDwarfLines:
            return "get lines";
        case wasmDiagnosticDwarfLineContext:
            return "get line context";
        case wasmDiagnosticDwarfLineAddress:
            return "get line address";
        case wasmDiagnosticDwarfLineSource:
            return "get line source";
        case wasmDiagnosticDwarfLineNumber:
            return "get line number";
        case wasmDiagnosticDwarfFinish:
            return "finish DWARF reader";
        case wasmDiagnosticDwarfNextUnit:
            return "read next compilation unit";
        case wasmDiagnosticDwarfAttribute:
            return "read DIE attribute";
    }
    return "unknown operation";
}

void
wasmDiagnosticPrint(
    FILE* file,
    const WasmDiagnostic* diagnostic,
    const char* inputName
) {
    switch (diagnostic->code) {
        case wasmDiagnosticReaderFailed: {
            fprintf(
                file,
                "w2c2: failed to read module %s: %s\n",
                inputName == NULL ? "" : inputName,
                wasmModuleReaderErrorMessage(diagnostic->info.readerFailed.error)
            );
            break;
        }
        case wasmDiagnosticInvalidInstruction: {
            const WasmDiagnosticInvalidInstructionInfo info = diagnostic->info.invalidInstruction;
            fprintf(
                file,
                "w2c2: invalid %s instruction encoding\n",
                wasmDiagnosticOpcodeDescription(info.family, info.opcode)
            );
            break;
        }
        case wasmDiagnosticInvalidLocalIndex: {
            const WasmDiagnosticInvalidLocalIndexInfo info = diagnostic->info.invalidLocalIndex;
            fprintf(
                file,
                "w2c2: invalid %s instruction: invalid local index: %u\n",
                wasmDiagnosticOpcodeDescription(info.family, info.opcode),
                info.index
            );
            break;
        }
        case wasmDiagnosticInvalidGlobalIndex: {
            const WasmDiagnosticInvalidGlobalIndexInfo info = diagnostic->info.invalidGlobalIndex;
            fprintf(
                file,
                "w2c2: invalid %s instruction: invalid global index: %u\n",
                wasmDiagnosticOpcodeDescription(info.family, info.opcode),
                info.index
            );
            break;
        }
        case wasmDiagnosticUnexpectedMemoryIndex: {
            const WasmDiagnosticUnexpectedMemoryIndexInfo info = diagnostic->info.unexpectedMemoryIndex;
            fprintf(
                file,
                "w2c2: invalid %s instruction: expected memory index %u to be %u, got %u\n",
                wasmDiagnosticOpcodeDescription(info.family, info.opcode),
                info.operand,
                info.expected,
                info.actual
            );
            break;
        }
        case wasmDiagnosticInvalidBlockType: {
            const WasmDiagnosticInvalidBlockTypeInfo info = diagnostic->info.invalidBlockType;
            fprintf(
                file,
                "w2c2: invalid %s instruction: expected block type\n",
                wasmOpcodeDescription((WasmOpcode)info.opcode)
            );
            break;
        }
        case wasmDiagnosticInvalidAlignment: {
            const WasmDiagnosticInvalidAlignmentInfo info = diagnostic->info.invalidAlignment;
            fprintf(
                file,
                "w2c2: invalid %s instruction: expected alignment %u, got %u\n",
                wasmDiagnosticOpcodeDescription(info.family, info.opcode),
                info.expected,
                info.actual
            );
            break;
        }
        case wasmDiagnosticUnsupportedOpcode: {
            const WasmDiagnosticUnsupportedOpcodeInfo info = diagnostic->info.unsupportedOpcode;
            fprintf(
                file,
                "w2c2: unsupported opcode %s (0x%X)\n",
                wasmDiagnosticOpcodeDescription(info.family, info.opcode),
                info.opcode
            );
            break;
        }
        case wasmDiagnosticUnsupportedValueType: {
            const WasmDiagnosticUnsupportedValueTypeInfo info = diagnostic->info.unsupportedValueType;
            fprintf(
                file,
                "w2c2: unsupported const type %s\n",
                wasmValueTypeDescription(info.valueType)
            );
            break;
        }
        case wasmDiagnosticUnsupportedFunctionResults: {
            const WasmDiagnosticUnsupportedFunctionResultsInfo info = diagnostic->info.unsupportedFunctionResults;
            fprintf(
                file,
                "w2c2: unsupported function type %u with %u result values\n",
                info.typeIndex,
                info.resultCount
            );
            break;
        }
        case wasmDiagnosticUnsupportedExport: {
            const WasmDiagnosticUnsupportedExportInfo info = diagnostic->info.unsupportedExport;
            fprintf(
                file,
                "w2c2: unsupported export: %s (%s)\n",
                info.name,
                wasmExportKindDescription(info.kind)
            );
            break;
        }
        case wasmDiagnosticInvalidDataSegmentMode: {
            const WasmDiagnosticInvalidDataSegmentModeInfo info = diagnostic->info.invalidDataSegmentMode;
            fprintf(file, "w2c2: unsupported data segment mode: %d\n", info.mode);
            break;
        }
        case wasmDiagnosticInvalidWriterArgument: {
            fprintf(file, "w2c2: invalid module writer argument\n");
            break;
        }
        case wasmDiagnosticOutputOpenFailed:
        case wasmDiagnosticOutputWriteFailed:
        case wasmDiagnosticOutputCloseFailed: {
            const WasmDiagnosticOutputFailedInfo info = diagnostic->info.outputFailed;
            const char* operation = "close";
            if (diagnostic->code == wasmDiagnosticOutputOpenFailed) {
                operation = "open";
            } else if (diagnostic->code == wasmDiagnosticOutputWriteFailed) {
                operation = "write";
            }
            fprintf(
                file,
                "w2c2: failed to %s output %s (system error %d)\n",
                operation,
                info.name,
                info.systemError
            );
            break;
        }
        case wasmDiagnosticAllocationFailed: {
            fprintf(file, "w2c2: allocation failed\n");
            break;
        }
        case wasmDiagnosticThreadFailed: {
            const WasmDiagnosticThreadFailedInfo info = diagnostic->info.threadFailed;
            fprintf(
                file,
                "w2c2: failed to %s (system error %d)\n",
                threadOperationDescription(info.operation),
                info.systemError
            );
            break;
        }
        case wasmDiagnosticDuplicateFunctionName: {
            const WasmDiagnosticDuplicateFunctionNameInfo info = diagnostic->info.duplicateFunctionName;
            fprintf(
                file,
                "w2c2: ignoring duplicate function name %s used by functions %u and %u\n",
                info.name,
                info.previousIndex,
                info.currentIndex
            );
            break;
        }
        case wasmDiagnosticSkippedNameSubsection: {
            const WasmDiagnosticSkippedNameSubsectionInfo info = diagnostic->info.skippedNameSubsection;
            fprintf(
                file,
                "w2c2: skipping unsupported name subsection %u (size %u)\n",
                info.id,
                info.size
            );
            break;
        }
        case wasmDiagnosticSkippedCustomSection: {
            const WasmDiagnosticSkippedCustomSectionInfo info = diagnostic->info.skippedCustomSection;
            fprintf(file, "w2c2: skipping custom section '%s' (size %u)\n", info.name, info.size);
            break;
        }
        case wasmDiagnosticSkippedSection: {
            const WasmDiagnosticSkippedSectionInfo info = diagnostic->info.skippedSection;
            fprintf(file, "w2c2: skipping unsupported section %u\n", info.id);
            break;
        }
        case wasmDiagnosticDwarfFailure: {
            const WasmDiagnosticDwarfFailureInfo info = diagnostic->info.dwarfFailure;
            fprintf(file, "w2c2: failed to %s\n", dwarfOperationDescription(info.operation));
            break;
        }
        case wasmDiagnosticDwarfVersionUnsupported: {
            const WasmDiagnosticDwarfVersionUnsupportedInfo info = diagnostic->info.dwarfVersionUnsupported;
            fprintf(
                file,
                "w2c2: libdwarf 20201020 or newer is required for the old libdwarf API; found %s\n",
                info.version == NULL ? "unknown" : info.version
            );
            break;
        }
        case wasmDiagnosticDwarfUnexpectedTag: {
            const WasmDiagnosticDwarfUnexpectedTagInfo info = diagnostic->info.dwarfUnexpectedTag;
            fprintf(file, "w2c2: unexpected non-compile unit DIE tag: %u\n", info.tag);
            break;
        }
        case wasmDiagnosticTranslationFailed: {
            fprintf(file, "w2c2: translation failed\n");
            break;
        }
    }
}
