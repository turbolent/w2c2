
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_fill.73.h"

void test() {
    m14_memoryX5FfillX2E73Instance instance;
    m14_memoryX5FfillX2E73Instantiate(&instance, resolveTestImports);
    printStart("memory_fill.73.wasm");
    assertEqualU32(
        m14_memoryX5FfillX2E73Export10_checkRange(&instance, 0u, 1u, 0u),
        4294967295u,
        "checkRange(0u, 1u, 0u)"
    );
}
