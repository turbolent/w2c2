#include "test.h"
#include "test_ref_null.1.h"

void test(void) {
    static m10_refX5FnullX2E1Instance instance;
    m10_refX5FnullX2E1Instantiate(&instance, resolveTestImports);
    printStart("ref_null.1.wasm");
    assertEqualU32((m10_refX5FnullX2E1Export8_constant(&instance)) == wasmNullExternRef, 1u, "constant()");
    assertEqualU32((m10_refX5FnullX2E1Export5_local(&instance)) == wasmNullExternRef, 1u, "local()");
    assertEqualU32((m10_refX5FnullX2E1Export6_global(&instance)) == wasmNullExternRef, 1u, "global()");
    assertEqualU32((m10_refX5FnullX2E1Export9_parameter(&instance, wasmNullExternRef)) == wasmNullExternRef, 1u, "parameter(wasmNullExternRef)");
    m10_refX5FnullX2E1FreeInstance(&instance);
}
