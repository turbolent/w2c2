
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_size.0.h"

void test() {
    memorysize0Instance instance;
    memorysize0Instantiate(&instance, resolveTestImports);
    printStart("memory_size.0.wasm");
    assertEqualU32(
        memorysize0_size(&instance),
        0u,
        "size()"
    );
    memorysize0_grow(&instance, 1u);
    assertEqualU32(
        memorysize0_size(&instance),
        1u,
        "size()"
    );
    memorysize0_grow(&instance, 4u);
    assertEqualU32(
        memorysize0_size(&instance),
        5u,
        "size()"
    );
    memorysize0_grow(&instance, 0u);
    assertEqualU32(
        memorysize0_size(&instance),
        5u,
        "size()"
    );
}
