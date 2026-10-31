#include "test.h"
#include "test_table_set.0.h"

void test(void) {
    static m11_tableX5FsetX2E0Instance instance;
    m11_tableX5FsetX2E0Instantiate(&instance, resolveTestImports);
    printStart("table_set.0.wasm");
    assertEqualU32((m11_tableX5FsetX2E0Export13_getX2Dexternref(&instance, 0u)) == wasmNullExternRef, 1u, "get-externref(0u)");
    (void)(m11_tableX5FsetX2E0Export13_setX2Dexternref(&instance, 0u, testExternRef(1u)));
    assertEqualU32((m11_tableX5FsetX2E0Export13_getX2Dexternref(&instance, 0u)) == testExternRef(1u), 1u, "get-externref(0u)");
    (void)(m11_tableX5FsetX2E0Export13_setX2Dexternref(&instance, 0u, wasmNullExternRef));
    assertEqualU32((m11_tableX5FsetX2E0Export13_getX2Dexternref(&instance, 0u)) == wasmNullExternRef, 1u, "get-externref(0u)");
    assertEqualU32((m11_tableX5FsetX2E0Export11_getX2Dfuncref(&instance, 0u)).func == NULL, 1u, "get-funcref(0u)");
    (void)(m11_tableX5FsetX2E0Export16_setX2DfuncrefX2Dfrom(&instance, 0u, 1u));
    assertEqualU32(
        m11_tableX5FsetX2E0Export15_isX5FnullX2Dfuncref(&instance, 0u),
        0u,
        "is_null-funcref(0u)"
    );
    (void)(m11_tableX5FsetX2E0Export11_setX2Dfuncref(&instance, 0u, wasmNullFuncRef));
    assertEqualU32((m11_tableX5FsetX2E0Export11_getX2Dfuncref(&instance, 0u)).func == NULL, 1u, "get-funcref(0u)");
    m11_tableX5FsetX2E0FreeInstance(&instance);
}
