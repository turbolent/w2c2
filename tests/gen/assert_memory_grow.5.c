
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_grow.5.h"

void test() {
    m13_memoryX5FgrowX2E5Instance instance;
    m13_memoryX5FgrowX2E5Instantiate(&instance, resolveTestImports);
    printStart("memory_grow.5.wasm");
    assertEqualU32(
        m13_memoryX5FgrowX2E5Export4_grow(&instance),
        1u,
        "grow()"
    );
}
