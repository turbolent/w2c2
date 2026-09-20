
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_init.87.h"

void test() {
    m14_memoryX5FinitX2E87Instance instance;
    m14_memoryX5FinitX2E87Instantiate(&instance, resolveTestImports);
    printStart("memory_init.87.wasm");
    assertEqualU32(
        m14_memoryX5FinitX2E87Export10_checkRange(&instance, 0u, 1u, 0u),
        4294967295u,
        "checkRange(0u, 1u, 0u)"
    );
}
