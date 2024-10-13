
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_init.87.h"

void test() {
    memoryinit87Instance instance;
    memoryinit87Instantiate(&instance, resolveTestImports);
    printStart("memory_init.87.wasm");
    assertEqualU32(
        memoryinit87_checkRange(&instance, 0u, 1u, 0u),
        4294967295u,
        "checkRange(0u, 1u, 0u)"
    );
}
