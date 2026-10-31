#include "test.h"
#include "test_bulk.4.h"

void test(void) {
    static m6_bulkX2E4Instance instance;
    m6_bulkX2E4Instantiate(&instance, resolveTestImports);
    printStart("bulk.4.wasm");
    (void)(m6_bulkX2E4Export4_init(&instance, 0u, 1u, 2u));
    printOK("init(0u, 1u, 2u)");
    assertEqualU32(
        m6_bulkX2E4Export7_load8X5Fu(&instance, 0u),
        187u,
        "load8_u(0u)"
    );
    assertEqualU32(
        m6_bulkX2E4Export7_load8X5Fu(&instance, 1u),
        204u,
        "load8_u(1u)"
    );
    assertEqualU32(
        m6_bulkX2E4Export7_load8X5Fu(&instance, 2u),
        0u,
        "load8_u(2u)"
    );
    (void)(m6_bulkX2E4Export4_init(&instance, 65532u, 0u, 4u));
    printOK("init(65532u, 0u, 4u)");
    assertEqualU32(
        m6_bulkX2E4Export7_load8X5Fu(&instance, 65534u),
        204u,
        "load8_u(65534u)"
    );
    assertEqualU32(
        m6_bulkX2E4Export7_load8X5Fu(&instance, 65535u),
        221u,
        "load8_u(65535u)"
    );
    (void)(m6_bulkX2E4Export4_init(&instance, 65536u, 0u, 0u));
    printOK("init(65536u, 0u, 0u)");
    (void)(m6_bulkX2E4Export4_init(&instance, 0u, 4u, 0u));
    printOK("init(0u, 4u, 0u)");
    m6_bulkX2E4FreeInstance(&instance);
}
