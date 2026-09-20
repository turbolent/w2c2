
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory.8.h"

void test() {
    m8_memoryX2E8Instance instance;
    m8_memoryX2E8Instantiate(&instance, resolveTestImports);
    printStart("memory.8.wasm");
    assertEqualU32(
        m8_memoryX2E8Export7_memsize(&instance),
        0u,
        "memsize()"
    );
}
