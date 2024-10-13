
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_init.85.h"

void test() {
    memoryinit85Instance instance;
    memoryinit85Instantiate(&instance, resolveTestImports);
    printStart("memory_init.85.wasm");
    assertEqualU32(
        memoryinit85_checkRange(&instance, 0u, 1u, 0u),
        4294967295u,
        "checkRange(0u, 1u, 0u)"
    );
}
