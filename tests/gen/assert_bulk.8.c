#include "test.h"
#include "test_bulk.8.h"

void test(void) {
    static m6_bulkX2E8Instance instance;
    m6_bulkX2E8Instantiate(&instance, resolveTestImports);
    printStart("bulk.8.wasm");
    (void)(m6_bulkX2E8Export4_init(&instance, 0u, 1u, 2u));
    printOK("init(0u, 1u, 2u)");
    assertEqualU32(
        m6_bulkX2E8Export4_call(&instance, 0u),
        1u,
        "call(0u)"
    );
    assertEqualU32(
        m6_bulkX2E8Export4_call(&instance, 1u),
        0u,
        "call(1u)"
    );
    (void)(m6_bulkX2E8Export4_init(&instance, 1u, 2u, 2u));
    printOK("init(1u, 2u, 2u)");
    (void)(m6_bulkX2E8Export4_init(&instance, 3u, 0u, 0u));
    printOK("init(3u, 0u, 0u)");
    (void)(m6_bulkX2E8Export4_init(&instance, 0u, 4u, 0u));
    printOK("init(0u, 4u, 0u)");
    m6_bulkX2E8FreeInstance(&instance);
}
