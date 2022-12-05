
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_fill.72.h"

void test() {
    memoryfill72Instance instance;
    memoryfill72Instantiate(&instance, resolveTestImports);
    printStart("memory_fill.72.wasm");
    assertEqualU32(
        memoryfill72_checkRange(&instance, 0u, 1u, 0u),
        4294967295u,
        "checkRange(0u, 1u, 0u)"
    );
}
