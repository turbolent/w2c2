
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory.9.h"

void test() {
    m8_memoryX2E9Instance instance;
    m8_memoryX2E9Instantiate(&instance, resolveTestImports);
    printStart("memory.9.wasm");
    assertEqualU32(
        m8_memoryX2E9Export7_memsize(&instance),
        0u,
        "memsize()"
    );
}
