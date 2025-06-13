#include "section.h"

const char*
wasmSectionIDDescription(
    const WasmSectionID sectionID
) {
    switch (sectionID) {
        case wasmSectionIDCustom:
            return "custom section";
        case wasmSectionIDType:
            return "type section";
        case wasmSectionIDImport:
            return "import section";
        case wasmSectionIDFunction:
            return "function section";
        case wasmSectionIDTable:
            return "table section";
        case wasmSectionIDMemory:
            return "memory section";
        case wasmSectionIDGlobal:
            return "global section";
        case wasmSectionIDExport:
            return "export section";
        case wasmSectionIDStart:
            return "start section";
        case wasmSectionIDElement:
            return "element section";
        case wasmSectionIDCode:
            return "code section";
        case wasmSectionIDData:
            return "data section";
        case wasmSectionIDDataCount:
            return "data count section";
        default:
            return "unknown section";
    }
}

const char*
wasmNameSubsectionIDDescription(
    const WasmNameSubsectionID subsectionID
) {
    switch (subsectionID) {
        case wasmNameSubsectionIDModuleName:
            return "module name subsection";
        case wasmNameSubsectionIDFunctionNames:
            return "function names subsection";
        case wasmNameSubsectionIDLocalNames:
            return "local names subsection";
        case wasmNameSubsectionIDLabelNames:
            return "label names subsection";
        case wasmNameSubsectionIDTypeNames:
            return "type names subsection";
        case wasmNameSubsectionIDTableNames:
            return "table names subsection";
        case wasmNameSubsectionIDMemoryNames:
            return "memory names subsection";
        case wasmNameSubsectionIDGlobalNames:
            return "global names subsection";
        case wasmNameSubsectionIDElemSegmentNames:
            return "elem segment names subsection";
        case wasmNameSubsectionIDDataSegmentNames:
            return "data segment names subsection";
        default:
            return "unknown name subsection";
    }
}
