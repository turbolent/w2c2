
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_fill.3.h"

void test() {
    m13_memoryX5FfillX2E3Instance instance;
    m13_memoryX5FfillX2E3Instantiate(&instance, resolveTestImports);
    printStart("memory_fill.3.wasm");
    m13_memoryX5FfillX2E3Export4_test(&instance);
    printOK("test()");
    assertEqualU32(
        m13_memoryX5FfillX2E3Export10_checkRange(&instance, 0u, 65536u, 0u),
        4294967295u,
        "checkRange(0u, 65536u, 0u)"
    );
}
