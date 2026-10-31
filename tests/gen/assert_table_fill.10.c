#include "test.h"
#include "test_table_fill.10.h"

void test(void) {
    static m13_tableX5FfillX2E10Instance instance;
    m13_tableX5FfillX2E10Instantiate(&instance, resolveTestImports);
    printStart("table_fill.10.wasm");
    (void)(m13_tableX5FfillX2E10Export4_fill(&instance, 1u, 2u));
    assertEqualU32((m13_tableX5FfillX2E10Export3_get(&instance, 0u)).func == NULL, 1u, "get(0u)");
    assertEqualU32(
        m13_tableX5FfillX2E10Export4_call(&instance, 1u),
        42u,
        "call(1u)"
    );
    assertEqualU32(
        m13_tableX5FfillX2E10Export4_call(&instance, 2u),
        42u,
        "call(2u)"
    );
    assertEqualU32((m13_tableX5FfillX2E10Export3_get(&instance, 3u)).func == NULL, 1u, "get(3u)");
    (void)(m13_tableX5FfillX2E10Export4_fill(&instance, 4u, 0u));
    (void)(m13_tableX5FfillX2E10Export5_clear(&instance, 1u, 2u));
    assertEqualU32((m13_tableX5FfillX2E10Export3_get(&instance, 1u)).func == NULL, 1u, "get(1u)");
    m13_tableX5FfillX2E10FreeInstance(&instance);
}
