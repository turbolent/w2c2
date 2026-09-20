
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.380.h"

void test() {
    m9_constX2E380Instance instance;
    m9_constX2E380Instantiate(&instance, resolveTestImports);
    printStart("const.380.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E380Export1_f(&instance)),
        9106278446543142914ull,
        "f()"
    );
}
