#include "section.h"

const char*
wasmSectionIDDescription(
    WasmSectionID sectionID
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
        default:
            return "unknown section";
    }
}
