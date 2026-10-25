
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_fill.6.h"

void test() {
    m13_memoryX5FfillX2E6Instance instance;
    m13_memoryX5FfillX2E6Instantiate(&instance, resolveTestImports);
    printStart("memory_fill.6.wasm");
    m13_memoryX5FfillX2E6Export4_test(&instance);
    printOK("test()");
    assertEqualU32(
        m13_memoryX5FfillX2E6Export10_checkRange(&instance, 0u, 1u, 0u),
        4294967295u,
        "checkRange(0u, 1u, 0u)"
    );
    assertEqualU32(
        m13_memoryX5FfillX2E6Export10_checkRange(&instance, 1u, 65535u, 170u),
        4294967295u,
        "checkRange(1u, 65535u, 170u)"
    );
    assertEqualU32(
        m13_memoryX5FfillX2E6Export10_checkRange(&instance, 65535u, 65536u, 0u),
        4294967295u,
        "checkRange(65535u, 65536u, 0u)"
    );
}
