
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_fac.0.h"

void test() {
    fac0Instance instance;
    fac0Instantiate(&instance, resolveTestImports);
    printStart("fac.0.wasm");
    assertEqualU64(
        fac0_facX2Drec(&instance, 25ull),
        7034535277573963776ull,
        "fac-rec(25ull)"
    );
    assertEqualU64(
        fac0_facX2Diter(&instance, 25ull),
        7034535277573963776ull,
        "fac-iter(25ull)"
    );
    assertEqualU64(
        fac0_facX2DrecX2Dnamed(&instance, 25ull),
        7034535277573963776ull,
        "fac-rec-named(25ull)"
    );
    assertEqualU64(
        fac0_facX2DiterX2Dnamed(&instance, 25ull),
        7034535277573963776ull,
        "fac-iter-named(25ull)"
    );
    assertEqualU64(
        fac0_facX2Dopt(&instance, 25ull),
        7034535277573963776ull,
        "fac-opt(25ull)"
    );
}
