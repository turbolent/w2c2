
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_grow.0.h"

void test() {
    memorygrow0Instance instance;
    memorygrow0Instantiate(&instance, resolveTestImports);
    printStart("memory_grow.0.wasm");
    assertEqualU32(
        memorygrow0_size(&instance),
        0u,
        "size()"
    );
    assertEqualU32(
        memorygrow0_grow(&instance, 1u),
        0u,
        "grow(1u)"
    );
    assertEqualU32(
        memorygrow0_size(&instance),
        1u,
        "size()"
    );
    assertEqualU32(
        memorygrow0_loadX5FatX5Fzero(&instance),
        0u,
        "load_at_zero()"
    );
    memorygrow0_storeX5FatX5Fzero(&instance);
    assertEqualU32(
        memorygrow0_loadX5FatX5Fzero(&instance),
        2u,
        "load_at_zero()"
    );
    assertEqualU32(
        memorygrow0_grow(&instance, 4u),
        1u,
        "grow(4u)"
    );
    assertEqualU32(
        memorygrow0_size(&instance),
        5u,
        "size()"
    );
    assertEqualU32(
        memorygrow0_loadX5FatX5Fzero(&instance),
        2u,
        "load_at_zero()"
    );
    memorygrow0_storeX5FatX5Fzero(&instance);
    assertEqualU32(
        memorygrow0_loadX5FatX5Fzero(&instance),
        2u,
        "load_at_zero()"
    );
    assertEqualU32(
        memorygrow0_loadX5FatX5FpageX5Fsize(&instance),
        0u,
        "load_at_page_size()"
    );
    memorygrow0_storeX5FatX5FpageX5Fsize(&instance);
    assertEqualU32(
        memorygrow0_loadX5FatX5FpageX5Fsize(&instance),
        3u,
        "load_at_page_size()"
    );
}
