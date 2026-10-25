
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_grow.0.h"

void test() {
    m13_memoryX5FgrowX2E0Instance instance;
    m13_memoryX5FgrowX2E0Instantiate(&instance, resolveTestImports);
    printStart("memory_grow.0.wasm");
    assertEqualU32(
        m13_memoryX5FgrowX2E0Export4_size(&instance),
        0u,
        "size()"
    );
    assertEqualU32(
        m13_memoryX5FgrowX2E0Export4_grow(&instance, 1u),
        0u,
        "grow(1u)"
    );
    assertEqualU32(
        m13_memoryX5FgrowX2E0Export4_size(&instance),
        1u,
        "size()"
    );
    assertEqualU32(
        m13_memoryX5FgrowX2E0Export12_loadX5FatX5Fzero(&instance),
        0u,
        "load_at_zero()"
    );
    m13_memoryX5FgrowX2E0Export13_storeX5FatX5Fzero(&instance);
    assertEqualU32(
        m13_memoryX5FgrowX2E0Export12_loadX5FatX5Fzero(&instance),
        2u,
        "load_at_zero()"
    );
    assertEqualU32(
        m13_memoryX5FgrowX2E0Export4_grow(&instance, 4u),
        1u,
        "grow(4u)"
    );
    assertEqualU32(
        m13_memoryX5FgrowX2E0Export4_size(&instance),
        5u,
        "size()"
    );
    assertEqualU32(
        m13_memoryX5FgrowX2E0Export12_loadX5FatX5Fzero(&instance),
        2u,
        "load_at_zero()"
    );
    m13_memoryX5FgrowX2E0Export13_storeX5FatX5Fzero(&instance);
    assertEqualU32(
        m13_memoryX5FgrowX2E0Export12_loadX5FatX5Fzero(&instance),
        2u,
        "load_at_zero()"
    );
    assertEqualU32(
        m13_memoryX5FgrowX2E0Export17_loadX5FatX5FpageX5Fsize(&instance),
        0u,
        "load_at_page_size()"
    );
    m13_memoryX5FgrowX2E0Export18_storeX5FatX5FpageX5Fsize(&instance);
    assertEqualU32(
        m13_memoryX5FgrowX2E0Export17_loadX5FatX5FpageX5Fsize(&instance),
        3u,
        "load_at_page_size()"
    );
}
