
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_init.85.h"

void test() {
    m14_memoryX5FinitX2E85Instance instance;
    m14_memoryX5FinitX2E85Instantiate(&instance, resolveTestImports);
    printStart("memory_init.85.wasm");
    assertEqualU32(
        m14_memoryX5FinitX2E85Export10_checkRange(&instance, 0u, 1u, 0u),
        4294967295u,
        "checkRange(0u, 1u, 0u)"
    );
}
