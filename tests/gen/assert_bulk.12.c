#include "test.h"
#include "test_bulk.12.h"

void test(void) {
    static m7_bulkX2E12Instance instance;
    m7_bulkX2E12Instantiate(&instance, resolveTestImports);
    printStart("bulk.12.wasm");
    (void)(m7_bulkX2E12Export4_copy(&instance, 3u, 0u, 3u));
    printOK("copy(3u, 0u, 3u)");
    assertEqualU32(
        m7_bulkX2E12Export4_call(&instance, 3u),
        0u,
        "call(3u)"
    );
    assertEqualU32(
        m7_bulkX2E12Export4_call(&instance, 4u),
        1u,
        "call(4u)"
    );
    assertEqualU32(
        m7_bulkX2E12Export4_call(&instance, 5u),
        2u,
        "call(5u)"
    );
    (void)(m7_bulkX2E12Export4_copy(&instance, 0u, 1u, 3u));
    printOK("copy(0u, 1u, 3u)");
    assertEqualU32(
        m7_bulkX2E12Export4_call(&instance, 0u),
        1u,
        "call(0u)"
    );
    assertEqualU32(
        m7_bulkX2E12Export4_call(&instance, 1u),
        2u,
        "call(1u)"
    );
    assertEqualU32(
        m7_bulkX2E12Export4_call(&instance, 2u),
        0u,
        "call(2u)"
    );
    (void)(m7_bulkX2E12Export4_copy(&instance, 2u, 0u, 3u));
    printOK("copy(2u, 0u, 3u)");
    assertEqualU32(
        m7_bulkX2E12Export4_call(&instance, 2u),
        1u,
        "call(2u)"
    );
    assertEqualU32(
        m7_bulkX2E12Export4_call(&instance, 3u),
        2u,
        "call(3u)"
    );
    assertEqualU32(
        m7_bulkX2E12Export4_call(&instance, 4u),
        0u,
        "call(4u)"
    );
    (void)(m7_bulkX2E12Export4_copy(&instance, 6u, 8u, 2u));
    printOK("copy(6u, 8u, 2u)");
    (void)(m7_bulkX2E12Export4_copy(&instance, 8u, 6u, 2u));
    printOK("copy(8u, 6u, 2u)");
    (void)(m7_bulkX2E12Export4_copy(&instance, 10u, 0u, 0u));
    printOK("copy(10u, 0u, 0u)");
    (void)(m7_bulkX2E12Export4_copy(&instance, 0u, 10u, 0u));
    printOK("copy(0u, 10u, 0u)");
    m7_bulkX2E12FreeInstance(&instance);
}
