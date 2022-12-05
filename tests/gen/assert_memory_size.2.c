
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_size.2.h"

void test() {
    memorysize2Instance instance;
    memorysize2Instantiate(&instance, resolveTestImports);
    printStart("memory_size.2.wasm");
    assertEqualU32(
        memorysize2_size(&instance),
        0u,
        "size()"
    );
    memorysize2_grow(&instance, 3u);
    assertEqualU32(
        memorysize2_size(&instance),
        0u,
        "size()"
    );
    memorysize2_grow(&instance, 1u);
    assertEqualU32(
        memorysize2_size(&instance),
        1u,
        "size()"
    );
    memorysize2_grow(&instance, 0u);
    assertEqualU32(
        memorysize2_size(&instance),
        1u,
        "size()"
    );
    memorysize2_grow(&instance, 4u);
    assertEqualU32(
        memorysize2_size(&instance),
        1u,
        "size()"
    );
    memorysize2_grow(&instance, 1u);
    assertEqualU32(
        memorysize2_size(&instance),
        2u,
        "size()"
    );
}
