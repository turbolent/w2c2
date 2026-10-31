#include "test.h"
#include "test_table_fill.0.h"

void test(void) {
    static m12_tableX5FfillX2E0Instance instance;
    m12_tableX5FfillX2E0Instantiate(&instance, resolveTestImports);
    printStart("table_fill.0.wasm");
    (void)(m12_tableX5FfillX2E0Export4_fill(&instance, 1u, 2u));
    assertEqualU32((m12_tableX5FfillX2E0Export3_get(&instance, 0u)).func == NULL, 1u, "get(0u)");
    assertEqualU32(
        m12_tableX5FfillX2E0Export4_call(&instance, 1u),
        42u,
        "call(1u)"
    );
    assertEqualU32(
        m12_tableX5FfillX2E0Export4_call(&instance, 2u),
        42u,
        "call(2u)"
    );
    assertEqualU32((m12_tableX5FfillX2E0Export3_get(&instance, 3u)).func == NULL, 1u, "get(3u)");
    (void)(m12_tableX5FfillX2E0Export4_fill(&instance, 4u, 0u));
    (void)(m12_tableX5FfillX2E0Export5_clear(&instance, 1u, 2u));
    assertEqualU32((m12_tableX5FfillX2E0Export3_get(&instance, 1u)).func == NULL, 1u, "get(1u)");
    m12_tableX5FfillX2E0FreeInstance(&instance);
}
