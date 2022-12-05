
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_stack.0.h"

void test() {
    stack0Instance instance;
    stack0Instantiate(&instance, resolveTestImports);
    printStart("stack.0.wasm");
    assertEqualU64(
        stack0_facX2Dexpr(&instance, 25ull),
        7034535277573963776ull,
        "fac-expr(25ull)"
    );
    assertEqualU64(
        stack0_facX2Dstack(&instance, 25ull),
        7034535277573963776ull,
        "fac-stack(25ull)"
    );
    assertEqualU64(
        stack0_facX2Dmixed(&instance, 25ull),
        7034535277573963776ull,
        "fac-mixed(25ull)"
    );
    assertEqualU32(
        stack0_notX2DquiteX2DaX2Dtree(&instance),
        3u,
        "not-quite-a-tree()"
    );
    assertEqualU32(
        stack0_notX2DquiteX2DaX2Dtree(&instance),
        9u,
        "not-quite-a-tree()"
    );
}
