
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_size.2.h"

void test() {
    m13_memoryX5FsizeX2E2Instance instance;
    m13_memoryX5FsizeX2E2Instantiate(&instance, resolveTestImports);
    printStart("memory_size.2.wasm");
    assertEqualU32(
        m13_memoryX5FsizeX2E2Export4_size(&instance),
        0u,
        "size()"
    );
    m13_memoryX5FsizeX2E2Export4_grow(&instance, 3u);
    assertEqualU32(
        m13_memoryX5FsizeX2E2Export4_size(&instance),
        0u,
        "size()"
    );
    m13_memoryX5FsizeX2E2Export4_grow(&instance, 1u);
    assertEqualU32(
        m13_memoryX5FsizeX2E2Export4_size(&instance),
        1u,
        "size()"
    );
    m13_memoryX5FsizeX2E2Export4_grow(&instance, 0u);
    assertEqualU32(
        m13_memoryX5FsizeX2E2Export4_size(&instance),
        1u,
        "size()"
    );
    m13_memoryX5FsizeX2E2Export4_grow(&instance, 4u);
    assertEqualU32(
        m13_memoryX5FsizeX2E2Export4_size(&instance),
        1u,
        "size()"
    );
    m13_memoryX5FsizeX2E2Export4_grow(&instance, 1u);
    assertEqualU32(
        m13_memoryX5FsizeX2E2Export4_size(&instance),
        2u,
        "size()"
    );
}
