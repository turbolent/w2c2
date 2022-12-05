
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_fill.73.h"

void test() {
    memoryfill73Instance instance;
    memoryfill73Instantiate(&instance, resolveTestImports);
    printStart("memory_fill.73.wasm");
    assertEqualU32(
        memoryfill73_checkRange(&instance, 0u, 1u, 0u),
        4294967295u,
        "checkRange(0u, 1u, 0u)"
    );
}
