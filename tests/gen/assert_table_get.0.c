#include "test.h"
#include "test_table_get.0.h"

void test(void) {
    static m11_tableX5FgetX2E0Instance instance;
    m11_tableX5FgetX2E0Instantiate(&instance, resolveTestImports);
    printStart("table_get.0.wasm");
    (void)(m11_tableX5FgetX2E0Export4_init(&instance, testExternRef(1u)));
    printOK("init(testExternRef(1u))");
    assertEqualU32((m11_tableX5FgetX2E0Export13_getX2Dexternref(&instance, 0u)) == wasmNullExternRef, 1u, "get-externref(0u)");
    assertEqualU32((m11_tableX5FgetX2E0Export13_getX2Dexternref(&instance, 1u)) == testExternRef(1u), 1u, "get-externref(1u)");
    assertEqualU32((m11_tableX5FgetX2E0Export11_getX2Dfuncref(&instance, 0u)).func == NULL, 1u, "get-funcref(0u)");
    assertEqualU32(
        m11_tableX5FgetX2E0Export15_isX5FnullX2Dfuncref(&instance, 1u),
        0u,
        "is_null-funcref(1u)"
    );
    assertEqualU32(
        m11_tableX5FgetX2E0Export15_isX5FnullX2Dfuncref(&instance, 2u),
        0u,
        "is_null-funcref(2u)"
    );
#if W2C2_RUNTIME_CHECKS
    assertTrap(m11_tableX5FgetX2E0Export13_getX2Dexternref(&instance, 2u), trapTableOutOfBounds, "get-externref(2u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m11_tableX5FgetX2E0Export11_getX2Dfuncref(&instance, 3u), trapTableOutOfBounds, "get-funcref(3u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m11_tableX5FgetX2E0Export13_getX2Dexternref(&instance, 4294967295u), trapTableOutOfBounds, "get-externref(4294967295u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m11_tableX5FgetX2E0Export11_getX2Dfuncref(&instance, 4294967295u), trapTableOutOfBounds, "get-funcref(4294967295u)");
#endif
    m11_tableX5FgetX2E0FreeInstance(&instance);
}
