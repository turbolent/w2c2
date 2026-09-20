
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_copy.84.h"

void test() {
    m14_memoryX5FcopyX2E84Instance instance;
    m14_memoryX5FcopyX2E84Instantiate(&instance, resolveTestImports);
    printStart("memory_copy.84.wasm");
    m14_memoryX5FcopyX2E84Export4_test(&instance);
    printOK("test()");
    assertEqualU32(
        m14_memoryX5FcopyX2E84Export10_checkRange(&instance, 0u, 10u, 0u),
        4294967295u,
        "checkRange(0u, 10u, 0u)"
    );
    assertEqualU32(
        m14_memoryX5FcopyX2E84Export10_checkRange(&instance, 10u, 21u, 85u),
        4294967295u,
        "checkRange(10u, 21u, 85u)"
    );
    assertEqualU32(
        m14_memoryX5FcopyX2E84Export10_checkRange(&instance, 21u, 65536u, 0u),
        4294967295u,
        "checkRange(21u, 65536u, 0u)"
    );
}
