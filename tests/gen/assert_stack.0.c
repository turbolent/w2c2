
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_stack.0.h"

void test() {
    m7_stackX2E0Instance instance;
    m7_stackX2E0Instantiate(&instance, resolveTestImports);
    printStart("stack.0.wasm");
    assertEqualU64(
        m7_stackX2E0Export8_facX2Dexpr(&instance, 25ull),
        7034535277573963776ull,
        "fac-expr(25ull)"
    );
    assertEqualU64(
        m7_stackX2E0Export9_facX2Dstack(&instance, 25ull),
        7034535277573963776ull,
        "fac-stack(25ull)"
    );
    assertEqualU64(
        m7_stackX2E0Export9_facX2Dmixed(&instance, 25ull),
        7034535277573963776ull,
        "fac-mixed(25ull)"
    );
    assertEqualU32(
        m7_stackX2E0Export16_notX2DquiteX2DaX2Dtree(&instance),
        3u,
        "not-quite-a-tree()"
    );
    assertEqualU32(
        m7_stackX2E0Export16_notX2DquiteX2DaX2Dtree(&instance),
        9u,
        "not-quite-a-tree()"
    );
}
