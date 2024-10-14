
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_init.88.h"

void test() {
    memoryinit88Instance instance;
    memoryinit88Instantiate(&instance, resolveTestImports);
    printStart("memory_init.88.wasm");
    assertEqualU32(
        memoryinit88_checkRange(&instance, 0u, 1u, 0u),
        4294967295u,
        "checkRange(0u, 1u, 0u)"
    );
}
