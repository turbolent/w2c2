
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_size.1.h"

void test() {
    m13_memoryX5FsizeX2E1Instance instance;
    m13_memoryX5FsizeX2E1Instantiate(&instance, resolveTestImports);
    printStart("memory_size.1.wasm");
    assertEqualU32(
        m13_memoryX5FsizeX2E1Export4_size(&instance),
        1u,
        "size()"
    );
    m13_memoryX5FsizeX2E1Export4_grow(&instance, 1u);
    assertEqualU32(
        m13_memoryX5FsizeX2E1Export4_size(&instance),
        2u,
        "size()"
    );
    m13_memoryX5FsizeX2E1Export4_grow(&instance, 4u);
    assertEqualU32(
        m13_memoryX5FsizeX2E1Export4_size(&instance),
        6u,
        "size()"
    );
    m13_memoryX5FsizeX2E1Export4_grow(&instance, 0u);
    assertEqualU32(
        m13_memoryX5FsizeX2E1Export4_size(&instance),
        6u,
        "size()"
    );
}
