
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_fill.0.h"

void test() {
    m13_memoryX5FfillX2E0Instance instance;
    m13_memoryX5FfillX2E0Instantiate(&instance, resolveTestImports);
    printStart("memory_fill.0.wasm");
    m13_memoryX5FfillX2E0Export4_test(&instance);
    printOK("test()");
    assertEqualU32(
        m13_memoryX5FfillX2E0Export10_checkRange(&instance, 0u, 65280u, 0u),
        4294967295u,
        "checkRange(0u, 65280u, 0u)"
    );
    assertEqualU32(
        m13_memoryX5FfillX2E0Export10_checkRange(&instance, 65280u, 65536u, 85u),
        4294967295u,
        "checkRange(65280u, 65536u, 85u)"
    );
}
