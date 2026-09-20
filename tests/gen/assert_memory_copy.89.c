
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_copy.89.h"

void test() {
    m14_memoryX5FcopyX2E89Instance instance;
    m14_memoryX5FcopyX2E89Instantiate(&instance, resolveTestImports);
    printStart("memory_copy.89.wasm");
    m14_memoryX5FcopyX2E89Export4_test(&instance);
    printOK("test()");
    assertEqualU32(
        m14_memoryX5FcopyX2E89Export10_checkRange(&instance, 0u, 32768u, 85u),
        4294967295u,
        "checkRange(0u, 32768u, 85u)"
    );
    assertEqualU32(
        m14_memoryX5FcopyX2E89Export10_checkRange(&instance, 32768u, 65536u, 170u),
        4294967295u,
        "checkRange(32768u, 65536u, 170u)"
    );
}
