#include "test.h"
#include "test_ref_null.2.h"

void test(void) {
    static m10_refX5FnullX2E2Instance instance;
    m10_refX5FnullX2E2Instantiate(&instance, resolveTestImports);
    printStart("ref_null.2.wasm");
    assertEqualU32((m10_refX5FnullX2E2Export7_funcref(&instance)).func == NULL, 1u, "funcref()");
    assertEqualU32((m10_refX5FnullX2E2Export9_externref(&instance)) == wasmNullExternRef, 1u, "externref()");
    m10_refX5FnullX2E2FreeInstance(&instance);
}
