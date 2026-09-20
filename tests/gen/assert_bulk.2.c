
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_bulk.2.h"

void test() {
    m6_bulkX2E2Instance instance;
    m6_bulkX2E2Instantiate(&instance, resolveTestImports);
    printStart("bulk.2.wasm");
    m6_bulkX2E2Export4_copy(&instance, 10u, 0u, 4u);
    printOK("copy(10u, 0u, 4u)");
    assertEqualU32(
        m6_bulkX2E2Export7_load8X5Fu(&instance, 9u),
        0u,
        "load8_u(9u)"
    );
    assertEqualU32(
        m6_bulkX2E2Export7_load8X5Fu(&instance, 10u),
        170u,
        "load8_u(10u)"
    );
    assertEqualU32(
        m6_bulkX2E2Export7_load8X5Fu(&instance, 11u),
        187u,
        "load8_u(11u)"
    );
    assertEqualU32(
        m6_bulkX2E2Export7_load8X5Fu(&instance, 12u),
        204u,
        "load8_u(12u)"
    );
    assertEqualU32(
        m6_bulkX2E2Export7_load8X5Fu(&instance, 13u),
        221u,
        "load8_u(13u)"
    );
    assertEqualU32(
        m6_bulkX2E2Export7_load8X5Fu(&instance, 14u),
        0u,
        "load8_u(14u)"
    );
    m6_bulkX2E2Export4_copy(&instance, 8u, 10u, 4u);
    printOK("copy(8u, 10u, 4u)");
    assertEqualU32(
        m6_bulkX2E2Export7_load8X5Fu(&instance, 8u),
        170u,
        "load8_u(8u)"
    );
    assertEqualU32(
        m6_bulkX2E2Export7_load8X5Fu(&instance, 9u),
        187u,
        "load8_u(9u)"
    );
    assertEqualU32(
        m6_bulkX2E2Export7_load8X5Fu(&instance, 10u),
        204u,
        "load8_u(10u)"
    );
    assertEqualU32(
        m6_bulkX2E2Export7_load8X5Fu(&instance, 11u),
        221u,
        "load8_u(11u)"
    );
    assertEqualU32(
        m6_bulkX2E2Export7_load8X5Fu(&instance, 12u),
        204u,
        "load8_u(12u)"
    );
    assertEqualU32(
        m6_bulkX2E2Export7_load8X5Fu(&instance, 13u),
        221u,
        "load8_u(13u)"
    );
    m6_bulkX2E2Export4_copy(&instance, 10u, 7u, 6u);
    printOK("copy(10u, 7u, 6u)");
    assertEqualU32(
        m6_bulkX2E2Export7_load8X5Fu(&instance, 10u),
        0u,
        "load8_u(10u)"
    );
    assertEqualU32(
        m6_bulkX2E2Export7_load8X5Fu(&instance, 11u),
        170u,
        "load8_u(11u)"
    );
    assertEqualU32(
        m6_bulkX2E2Export7_load8X5Fu(&instance, 12u),
        187u,
        "load8_u(12u)"
    );
    assertEqualU32(
        m6_bulkX2E2Export7_load8X5Fu(&instance, 13u),
        204u,
        "load8_u(13u)"
    );
    assertEqualU32(
        m6_bulkX2E2Export7_load8X5Fu(&instance, 14u),
        221u,
        "load8_u(14u)"
    );
    assertEqualU32(
        m6_bulkX2E2Export7_load8X5Fu(&instance, 15u),
        204u,
        "load8_u(15u)"
    );
    assertEqualU32(
        m6_bulkX2E2Export7_load8X5Fu(&instance, 16u),
        0u,
        "load8_u(16u)"
    );
    m6_bulkX2E2Export4_copy(&instance, 65280u, 0u, 256u);
    printOK("copy(65280u, 0u, 256u)");
    m6_bulkX2E2Export4_copy(&instance, 65024u, 65280u, 256u);
    printOK("copy(65024u, 65280u, 256u)");
    m6_bulkX2E2Export4_copy(&instance, 65536u, 0u, 0u);
    printOK("copy(65536u, 0u, 0u)");
    m6_bulkX2E2Export4_copy(&instance, 0u, 65536u, 0u);
    printOK("copy(0u, 65536u, 0u)");
}
