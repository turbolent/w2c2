
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_init.84.h"

void test() {
    memoryinit84Instance instance;
    memoryinit84Instantiate(&instance, resolveTestImports);
    printStart("memory_init.84.wasm");
    assertEqualU32(
        memoryinit84_checkRange(&instance, 0u, 1u, 0u),
        4294967295u,
        "checkRange(0u, 1u, 0u)"
    );
}
