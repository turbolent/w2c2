
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_init.86.h"

void test() {
    m14_memoryX5FinitX2E86Instance instance;
    m14_memoryX5FinitX2E86Instantiate(&instance, resolveTestImports);
    printStart("memory_init.86.wasm");
    assertEqualU32(
        m14_memoryX5FinitX2E86Export10_checkRange(&instance, 0u, 1u, 0u),
        4294967295u,
        "checkRange(0u, 1u, 0u)"
    );
}
