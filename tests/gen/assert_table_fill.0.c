#include "test.h"
#include "test_table_fill.0.h"

void test(void) {
    static m12_tableX5FfillX2E0Instance instance;
    m12_tableX5FfillX2E0Instantiate(&instance, resolveTestImports);
    printStart("table_fill.0.wasm");
    assertEqualU32((m12_tableX5FfillX2E0Export3_get(&instance, 1u)) == wasmNullExternRef, 1u, "get(1u)");
    assertEqualU32((m12_tableX5FfillX2E0Export3_get(&instance, 2u)) == wasmNullExternRef, 1u, "get(2u)");
    assertEqualU32((m12_tableX5FfillX2E0Export3_get(&instance, 3u)) == wasmNullExternRef, 1u, "get(3u)");
    assertEqualU32((m12_tableX5FfillX2E0Export3_get(&instance, 4u)) == wasmNullExternRef, 1u, "get(4u)");
    assertEqualU32((m12_tableX5FfillX2E0Export3_get(&instance, 5u)) == wasmNullExternRef, 1u, "get(5u)");
    (void)(m12_tableX5FfillX2E0Export4_fill(&instance, 2u, testExternRef(1u), 3u));
    assertEqualU32((m12_tableX5FfillX2E0Export3_get(&instance, 1u)) == wasmNullExternRef, 1u, "get(1u)");
    assertEqualU32((m12_tableX5FfillX2E0Export3_get(&instance, 2u)) == testExternRef(1u), 1u, "get(2u)");
    assertEqualU32((m12_tableX5FfillX2E0Export3_get(&instance, 3u)) == testExternRef(1u), 1u, "get(3u)");
    assertEqualU32((m12_tableX5FfillX2E0Export3_get(&instance, 4u)) == testExternRef(1u), 1u, "get(4u)");
    assertEqualU32((m12_tableX5FfillX2E0Export3_get(&instance, 5u)) == wasmNullExternRef, 1u, "get(5u)");
    (void)(m12_tableX5FfillX2E0Export4_fill(&instance, 4u, testExternRef(2u), 2u));
    assertEqualU32((m12_tableX5FfillX2E0Export3_get(&instance, 3u)) == testExternRef(1u), 1u, "get(3u)");
    assertEqualU32((m12_tableX5FfillX2E0Export3_get(&instance, 4u)) == testExternRef(2u), 1u, "get(4u)");
    assertEqualU32((m12_tableX5FfillX2E0Export3_get(&instance, 5u)) == testExternRef(2u), 1u, "get(5u)");
    assertEqualU32((m12_tableX5FfillX2E0Export3_get(&instance, 6u)) == wasmNullExternRef, 1u, "get(6u)");
    (void)(m12_tableX5FfillX2E0Export4_fill(&instance, 4u, testExternRef(3u), 0u));
    assertEqualU32((m12_tableX5FfillX2E0Export3_get(&instance, 3u)) == testExternRef(1u), 1u, "get(3u)");
    assertEqualU32((m12_tableX5FfillX2E0Export3_get(&instance, 4u)) == testExternRef(2u), 1u, "get(4u)");
    assertEqualU32((m12_tableX5FfillX2E0Export3_get(&instance, 5u)) == testExternRef(2u), 1u, "get(5u)");
    (void)(m12_tableX5FfillX2E0Export4_fill(&instance, 8u, testExternRef(4u), 2u));
    assertEqualU32((m12_tableX5FfillX2E0Export3_get(&instance, 7u)) == wasmNullExternRef, 1u, "get(7u)");
    assertEqualU32((m12_tableX5FfillX2E0Export3_get(&instance, 8u)) == testExternRef(4u), 1u, "get(8u)");
    assertEqualU32((m12_tableX5FfillX2E0Export3_get(&instance, 9u)) == testExternRef(4u), 1u, "get(9u)");
    (void)(m12_tableX5FfillX2E0Export11_fillX2Dabbrev(&instance, 9u, wasmNullExternRef, 1u));
    assertEqualU32((m12_tableX5FfillX2E0Export3_get(&instance, 8u)) == testExternRef(4u), 1u, "get(8u)");
    assertEqualU32((m12_tableX5FfillX2E0Export3_get(&instance, 9u)) == wasmNullExternRef, 1u, "get(9u)");
    (void)(m12_tableX5FfillX2E0Export4_fill(&instance, 10u, testExternRef(5u), 0u));
    assertEqualU32((m12_tableX5FfillX2E0Export3_get(&instance, 9u)) == wasmNullExternRef, 1u, "get(9u)");
    assertEqualU32((m12_tableX5FfillX2E0Export3_get(&instance, 7u)) == wasmNullExternRef, 1u, "get(7u)");
    assertEqualU32((m12_tableX5FfillX2E0Export3_get(&instance, 8u)) == testExternRef(4u), 1u, "get(8u)");
    assertEqualU32((m12_tableX5FfillX2E0Export3_get(&instance, 9u)) == wasmNullExternRef, 1u, "get(9u)");
    m12_tableX5FfillX2E0FreeInstance(&instance);
}
