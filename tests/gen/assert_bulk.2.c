#include "test.h"
#include "test_bulk.2.h"

void test(void) {
    static m6_bulkX2E2Instance instance;
    m6_bulkX2E2Instantiate(&instance, resolveTestImports);
    printStart("bulk.2.wasm");
    (void)(m6_bulkX2E2Export4_fill(&instance, 1u, 255u, 3u));
    printOK("fill(1u, 255u, 3u)");
    assertEqualU32(
        m6_bulkX2E2Export7_load8X5Fu(&instance, 0u),
        0u,
        "load8_u(0u)"
    );
    assertEqualU32(
        m6_bulkX2E2Export7_load8X5Fu(&instance, 1u),
        255u,
        "load8_u(1u)"
    );
    assertEqualU32(
        m6_bulkX2E2Export7_load8X5Fu(&instance, 2u),
        255u,
        "load8_u(2u)"
    );
    assertEqualU32(
        m6_bulkX2E2Export7_load8X5Fu(&instance, 3u),
        255u,
        "load8_u(3u)"
    );
    assertEqualU32(
        m6_bulkX2E2Export7_load8X5Fu(&instance, 4u),
        0u,
        "load8_u(4u)"
    );
    (void)(m6_bulkX2E2Export4_fill(&instance, 0u, 48042u, 2u));
    printOK("fill(0u, 48042u, 2u)");
    assertEqualU32(
        m6_bulkX2E2Export7_load8X5Fu(&instance, 0u),
        170u,
        "load8_u(0u)"
    );
    assertEqualU32(
        m6_bulkX2E2Export7_load8X5Fu(&instance, 1u),
        170u,
        "load8_u(1u)"
    );
    (void)(m6_bulkX2E2Export4_fill(&instance, 0u, 0u, 65536u));
    printOK("fill(0u, 0u, 65536u)");
    assertEqualU32(
        m6_bulkX2E2Export7_load8X5Fu(&instance, 65280u),
        0u,
        "load8_u(65280u)"
    );
    assertEqualU32(
        m6_bulkX2E2Export7_load8X5Fu(&instance, 65535u),
        0u,
        "load8_u(65535u)"
    );
    (void)(m6_bulkX2E2Export4_fill(&instance, 65536u, 0u, 0u));
    printOK("fill(65536u, 0u, 0u)");
    m6_bulkX2E2FreeInstance(&instance);
}
