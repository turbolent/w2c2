
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_fill.74.h"

void test() {
    memoryfill74Instance instance;
    memoryfill74Instantiate(&instance, resolveTestImports);
    printStart("memory_fill.74.wasm");
    assertEqualU32(
        memoryfill74_checkRange(&instance, 0u, 1u, 0u),
        4294967295u,
        "checkRange(0u, 1u, 0u)"
    );
}
