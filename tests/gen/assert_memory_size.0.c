
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_size.0.h"

void test() {
    m13_memoryX5FsizeX2E0Instance instance;
    m13_memoryX5FsizeX2E0Instantiate(&instance, resolveTestImports);
    printStart("memory_size.0.wasm");
    assertEqualU32(
        m13_memoryX5FsizeX2E0Export4_size(&instance),
        0u,
        "size()"
    );
    m13_memoryX5FsizeX2E0Export4_grow(&instance, 1u);
    assertEqualU32(
        m13_memoryX5FsizeX2E0Export4_size(&instance),
        1u,
        "size()"
    );
    m13_memoryX5FsizeX2E0Export4_grow(&instance, 4u);
    assertEqualU32(
        m13_memoryX5FsizeX2E0Export4_size(&instance),
        5u,
        "size()"
    );
    m13_memoryX5FsizeX2E0Export4_grow(&instance, 0u);
    assertEqualU32(
        m13_memoryX5FsizeX2E0Export4_size(&instance),
        5u,
        "size()"
    );
}
