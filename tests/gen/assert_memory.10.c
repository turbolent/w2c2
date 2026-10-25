
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory.10.h"

void test() {
    m9_memoryX2E10Instance instance;
    m9_memoryX2E10Instantiate(&instance, resolveTestImports);
    printStart("memory.10.wasm");
    assertEqualU32(
        m9_memoryX2E10Export7_memsize(&instance),
        1u,
        "memsize()"
    );
}
