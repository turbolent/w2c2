#include "test.h"
#include "test_ref_null.0.h"

void test(void) {
    static m10_refX5FnullX2E0Instance instance;
    m10_refX5FnullX2E0Instantiate(&instance, resolveTestImports);
    printStart("ref_null.0.wasm");
    assertEqualU32((m10_refX5FnullX2E0Export8_constant(&instance)).func == NULL, 1u, "constant()");
    assertEqualU32((m10_refX5FnullX2E0Export5_local(&instance)).func == NULL, 1u, "local()");
    assertEqualU32((m10_refX5FnullX2E0Export6_global(&instance)).func == NULL, 1u, "global()");
    assertEqualU32((m10_refX5FnullX2E0Export9_parameter(&instance, wasmNullFuncRef)).func == NULL, 1u, "parameter(wasmNullFuncRef)");
    m10_refX5FnullX2E0FreeInstance(&instance);
}
