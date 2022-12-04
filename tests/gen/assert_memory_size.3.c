
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_size.3.h"

void test() {
    memorysize3Instance instance;
    memorysize3Instantiate(&instance, resolveTestImports);
    printStart("memory_size.3.wasm");
    assertEqualU32(
        memorysize3_size(&instance),
        3u,
        "size()"
    );
    memorysize3_grow(&instance, 1u);
    assertEqualU32(
        memorysize3_size(&instance),
        4u,
        "size()"
    );
    memorysize3_grow(&instance, 3u);
    assertEqualU32(
        memorysize3_size(&instance),
        7u,
        "size()"
    );
    memorysize3_grow(&instance, 0u);
    assertEqualU32(
        memorysize3_size(&instance),
        7u,
        "size()"
    );
    memorysize3_grow(&instance, 2u);
    assertEqualU32(
        memorysize3_size(&instance),
        7u,
        "size()"
    );
    memorysize3_grow(&instance, 1u);
    assertEqualU32(
        memorysize3_size(&instance),
        8u,
        "size()"
    );
}
