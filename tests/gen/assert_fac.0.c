
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_fac.0.h"

void test() {
    m5_facX2E0Instance instance;
    m5_facX2E0Instantiate(&instance, resolveTestImports);
    printStart("fac.0.wasm");
    assertEqualU64(
        m5_facX2E0Export7_facX2Drec(&instance, 25ull),
        7034535277573963776ull,
        "fac-rec(25ull)"
    );
    assertEqualU64(
        m5_facX2E0Export8_facX2Diter(&instance, 25ull),
        7034535277573963776ull,
        "fac-iter(25ull)"
    );
    assertEqualU64(
        m5_facX2E0Export13_facX2DrecX2Dnamed(&instance, 25ull),
        7034535277573963776ull,
        "fac-rec-named(25ull)"
    );
    assertEqualU64(
        m5_facX2E0Export14_facX2DiterX2Dnamed(&instance, 25ull),
        7034535277573963776ull,
        "fac-iter-named(25ull)"
    );
    assertEqualU64(
        m5_facX2E0Export7_facX2Dopt(&instance, 25ull),
        7034535277573963776ull,
        "fac-opt(25ull)"
    );
}
