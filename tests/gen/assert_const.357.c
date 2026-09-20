
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.357.h"

void test() {
    m9_constX2E357Instance instance;
    m9_constX2E357Instantiate(&instance, resolveTestImports);
    printStart("const.357.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E357Export1_f(&instance)),
        11128394679232495617ull,
        "f()"
    );
}
