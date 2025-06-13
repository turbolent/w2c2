
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_init.89.h"

void test() {
    memoryinit89Instance instance;
    memoryinit89Instantiate(&instance, resolveTestImports);
    printStart("memory_init.89.wasm");
    assertEqualU32(
        memoryinit89_checkRange(&instance, 0u, 1u, 0u),
        4294967295u,
        "checkRange(0u, 1u, 0u)"
    );
}
