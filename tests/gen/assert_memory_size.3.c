
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_size.3.h"

void test() {
    m13_memoryX5FsizeX2E3Instance instance;
    m13_memoryX5FsizeX2E3Instantiate(&instance, resolveTestImports);
    printStart("memory_size.3.wasm");
    assertEqualU32(
        m13_memoryX5FsizeX2E3Export4_size(&instance),
        3u,
        "size()"
    );
    m13_memoryX5FsizeX2E3Export4_grow(&instance, 1u);
    assertEqualU32(
        m13_memoryX5FsizeX2E3Export4_size(&instance),
        4u,
        "size()"
    );
    m13_memoryX5FsizeX2E3Export4_grow(&instance, 3u);
    assertEqualU32(
        m13_memoryX5FsizeX2E3Export4_size(&instance),
        7u,
        "size()"
    );
    m13_memoryX5FsizeX2E3Export4_grow(&instance, 0u);
    assertEqualU32(
        m13_memoryX5FsizeX2E3Export4_size(&instance),
        7u,
        "size()"
    );
    m13_memoryX5FsizeX2E3Export4_grow(&instance, 2u);
    assertEqualU32(
        m13_memoryX5FsizeX2E3Export4_size(&instance),
        7u,
        "size()"
    );
    m13_memoryX5FsizeX2E3Export4_grow(&instance, 1u);
    assertEqualU32(
        m13_memoryX5FsizeX2E3Export4_size(&instance),
        8u,
        "size()"
    );
}
