
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_init.86.h"

void test() {
    memoryinit86Instance instance;
    memoryinit86Instantiate(&instance, resolveTestImports);
    printStart("memory_init.86.wasm");
    assertEqualU32(
        memoryinit86_checkRange(&instance, 0u, 1u, 0u),
        4294967295u,
        "checkRange(0u, 1u, 0u)"
    );
}
