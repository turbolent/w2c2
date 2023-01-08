#ifndef W2C2_SECTION_H
#define W2C2_SECTION_H

/*
 * WasmSectionID is the ID of a section in the WASM binary.
 *
 * See https://webassembly.github.io/spec/core/binary/modules.html#sections:
 */
typedef enum WasmSectionID {
    wasmSectionIDCustom = 0,
    wasmSectionIDType = 1,
    wasmSectionIDImport = 2,
    wasmSectionIDFunction = 3,
    wasmSectionIDTable = 4,
    wasmSectionIDMemory = 5,
    wasmSectionIDGlobal = 6,
    wasmSectionIDExport = 7,
    wasmSectionIDStart = 8,
    wasmSectionIDElement = 9,
    wasmSectionIDCode = 10,
    wasmSectionIDData = 11
} WasmSectionID;

const char*
wasmSectionIDDescription(
    WasmSectionID sectionID
);

/*
 * WasmNameSubsectionID is the subsection ID of a name section in the WASM binary.
 *
 * See https://webassembly.github.io/spec/core/appendix/custom.html#subsections:
 */
typedef enum WasmNameSubsectionID {
    wasmNameSubsectionIDModuleName = 0,
    wasmNameSubsectionIDFunctionNames = 1,
    wasmNameSubsectionIDLocalNames = 2,
    wasmNameSubsection_count = 3
} WasmNameSubsectionID;

#endif /* W2C2_SECTION_H */
