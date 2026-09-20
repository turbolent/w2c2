
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.396.h"

void test() {
    m9_constX2E396Instance instance;
    m9_constX2E396Instantiate(&instance, resolveTestImports);
    printStart("const.396.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E396Export1_f(&instance)),
        7309342195222315010ull,
        "f()"
    );
}
