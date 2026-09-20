#include <stdio.h>

#include "c_name.h"
#include "c_name_test.h"

#define CHECK(condition) \
    do { \
        if (!(condition)) { \
            fprintf(stderr, "FAIL testCNames: line %d: %s\n", __LINE__, #condition); \
            exit(1); \
        } \
    } while (0)

static
void
expectName(
    WasmOutput* output,
    OutputBuffer* buffer,
    const char* expected
) {
    CHECK(wasmOutputClose(output));
    if (buffer->length != strlen(expected)
        || strcmp((const char*)buffer->data, expected) != 0) {
        fprintf(stderr, "FAIL testCNames: %s != %s\n", buffer->data, expected);
        exit(1);
    }
    buffer->length = 0;
    buffer->data[0] = 0;
}

typedef enum NameKind {
    moduleName,
    dataName,
    dataSegmentName,
    functionName,
    exportName,
    debugName
} NameKind;

void
testCNames(void) {
    static char unterminated[] = {'a', 'b', 'c'};
    static const struct {
        WasmName name;
        const char* expected;
    } components[] = {
        {{NULL, 0}, "0_"},
        {{"", 0}, "0_"},
        {{unterminated, 3}, "3_abc"},
        {{"abc", 2}, "2_ab"},
        {{"AZaz09x", 7}, "7_AZaz09x"},
        {{"_", 1}, "1_X5F"},
        {{"__", 2}, "2_X5FX5F"},
        {{"X", 1}, "1_X58"},
        {{"X00", 3}, "3_X5800"},
        {{"\0", 1}, "1_X00"},
        {{"\303\251", 2}, "2_XC3XA9"},
        {{"\360\237\230\200", 4}, "4_XF0X9FX98X80"},
        {{"9", 1}, "1_9"},
        {{"0123456789", 10}, "10_0123456789"},
        {{"a_b", 3}, "3_aX5Fb"},
        {{"a__b", 4}, "4_aX5FX5Fb"},
        {{"aX5Fb", 5}, "5_aX585Fb"},
        {{"X00\0", 4}, "4_X5800X00"},
        {{"\0X00", 4}, "4_X00X5800"},
        {{"\"\\\n\t\0\303\251_[]:\?.", 13}, "13_X22X5CX0AX09X00XC3XA9X5FX5BX5DX3AX3FX2E"}
    };
    static const struct {
        const char* moduleName;
        WasmName module;
        WasmName name;
        const char* expected;
    } imports[] = {
        {NULL, {"a_", 2}, {"b", 1}, "i2_aX5F1_b"},
        {NULL, {"a", 1}, {"_b", 2}, "i1_a2_X5Fb"},
        {NULL, {"", 0}, {"", 0}, "i0_0_"},
        {NULL, {"9", 1}, {"return", 6}, "i1_96_return"},
        {NULL, {"\303\251", 2}, {"\360\237\230\200", 4}, "i2_XC3XA94_XF0X9FX98X80"},
        {NULL, {"X00", 3}, {"X", 1}, "i3_X58001_X58"},
        {NULL, {"\0", 1}, {"\0", 1}, "i1_X001_X00"},
        {NULL, {"1", 1}, {"23", 2}, "i1_12_23"},
        {NULL, {"12", 2}, {"3", 1}, "i2_121_3"},
        {NULL, {"1", 1}, {"aaaaaaaaa2bb", 12}, "i1_112_aaaaaaaaa2bb"},
        {NULL, {"12aaaaaaaaa", 11}, {"bb", 2}, "i11_12aaaaaaaaa2_bb"},
        {"fac", {"a_", 2}, {"b", 1}, "m3_facImport2_aX5F1_b"},
        {"fac", {"a", 1}, {"_b", 2}, "m3_facImport1_a2_X5Fb"},
        {"fac", {"", 0}, {"", 0}, "m3_facImport0_0_"},
        {"9-\303\251_X", {"env", 3}, {"print", 5}, "m6_9X2DXC3XA9X5FX58Import3_env5_print"}
    };
    static const struct {
        NameKind kind;
        const char* module;
        WasmName name;
        U32 functionIndex;
        const char* expected;
    } symbols[] = {
        {moduleName, "fac", {NULL, 0}, 0, "m3_fac"},
        {moduleName, "9-\303\251_X", {NULL, 0}, 0, "m6_9X2DXC3XA9X5FX58"},
        {moduleName, "9_\303\251-X", {NULL, 0}, 0, "m6_9X5FXC3XA9X2DX58"},
        {dataName, "fac", {NULL, 0}, 0, "m3_facData"},
        {dataSegmentName, "fac", {NULL, 0}, 0, "m3_facData0"},
        {dataSegmentName, "fac", {NULL, 0}, UINT32_MAX, "m3_facData4294967295"},
        {dataSegmentName, "facData", {NULL, 0}, 0, "m7_facDataData0"},
        {dataSegmentName, "9-\303\251_X", {NULL, 0}, 12, "m6_9X2DXC3XA9X5FX58Data12"},
        {exportName, "fac", {"Data0", 5}, 0, "m3_facExport5_Data0"},
        {functionName, NULL, {NULL, 0}, 9, "f9"},
        {functionName, "fac", {NULL, 0}, 9, "m3_facFunction9"},
        {functionName, "fac", {NULL, 0}, UINT32_MAX, "m3_facFunction4294967295"},
        {exportName, "fac", {"f9", 2}, 0, "m3_facExport2_f9"},
        {exportName, "fac", {"Instance", 8}, 0, "m3_facExport8_Instance"},
        {exportName, "fac", {"Instantiate", 11}, 0, "m3_facExport11_Instantiate"},
        {exportName, "fac", {"", 0}, 0, "m3_facExport0_"},
        {exportName, "fac", {"\0", 1}, 0, "m3_facExport1_X00"},
        {exportName, "fac", {"a__b", 4}, 0, "m3_facExport4_aX5FX5Fb"},
        {debugName, "fac", {"f9", 2}, 9, "m3_facDebug9Name2_f9"},
        {debugName, "fac", {"f9", 2}, 10, "m3_facDebug10Name2_f9"},
        {debugName, "fac", {"", 0}, 9, "m3_facDebug9Name0_"},
        {debugName, "fac", {"\"\\\n\t\0\303\251_[]:\?.", 13}, 9,
            "m3_facDebug9Name13_X22X5CX0AX09X00XC3XA9X5FX5BX5DX3AX3FX2E"}
    };
    OutputBuffer buffer = emptyOutputBuffer;
    WasmDiagnosticContext diagnostics = emptyWasmDiagnosticContext;
    size_t index;
    CHECK(outputBufferInitialize(&buffer));
    for (index = 0; index < sizeof(components) / sizeof(components[0]); index++) {
        WasmOutput output = wasmOutputForBuffer(&buffer, &diagnostics);
        wasmCWriteNameComponent(&output, components[index].name);
        expectName(&output, &buffer, components[index].expected);
    }
    for (index = 0; index < sizeof(imports) / sizeof(imports[0]); index++) {
        WasmOutput output = wasmOutputForBuffer(&buffer, &diagnostics);
        wasmCWriteFunctionImportName(&output,
            imports[index].moduleName, imports[index].module, imports[index].name);
        expectName(&output, &buffer, imports[index].expected);
    }
    for (index = 0; index < sizeof(symbols) / sizeof(symbols[0]); index++) {
        WasmOutput output = wasmOutputForBuffer(&buffer, &diagnostics);
        switch (symbols[index].kind) {
            case moduleName:
                wasmCWriteModuleName(&output, symbols[index].module);
                break;
            case functionName:
                wasmCWriteFunctionName(&output, symbols[index].module, symbols[index].functionIndex);
                break;
            case dataName:
                wasmCWriteDataName(&output, symbols[index].module);
                break;
            case dataSegmentName:
                wasmCWriteDataSegmentName(&output, symbols[index].module, symbols[index].functionIndex);
                break;
            case exportName:
                wasmCWriteExportName(&output, symbols[index].module, symbols[index].name);
                break;
            case debugName:
                wasmCWriteDebugName(&output,
                    symbols[index].module, symbols[index].functionIndex, symbols[index].name);
                break;
        }
        expectName(&output, &buffer, symbols[index].expected);
    }
    outputBufferFree(&buffer);
    fprintf(stderr, "PASS testCNames\n");
}
