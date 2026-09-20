
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.472.h"

void test() {
    m9_constX2E472Instance instance;
    m9_constX2E472Instantiate(&instance, resolveTestImports);
    printStart("const.472.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E472Export1_f(&instance)),
        4503599627370499ull,
        "f()"
    );
}
