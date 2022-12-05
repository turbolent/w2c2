
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_size.1.h"

void test() {
    memorysize1Instance instance;
    memorysize1Instantiate(&instance, resolveTestImports);
    printStart("memory_size.1.wasm");
    assertEqualU32(
        memorysize1_size(&instance),
        1u,
        "size()"
    );
    memorysize1_grow(&instance, 1u);
    assertEqualU32(
        memorysize1_size(&instance),
        2u,
        "size()"
    );
    memorysize1_grow(&instance, 4u);
    assertEqualU32(
        memorysize1_size(&instance),
        6u,
        "size()"
    );
    memorysize1_grow(&instance, 0u);
    assertEqualU32(
        memorysize1_size(&instance),
        6u,
        "size()"
    );
}
