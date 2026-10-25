
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.470.h"

void test() {
    m9_constX2E470Instance instance;
    m9_constX2E470Instantiate(&instance, resolveTestImports);
    printStart("const.470.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E470Export1_f(&instance)),
        2ull,
        "f()"
    );
}
