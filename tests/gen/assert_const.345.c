
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.345.h"

void test() {
    m9_constX2E345Instance instance;
    m9_constX2E345Instantiate(&instance, resolveTestImports);
    printStart("const.345.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E345Export1_f(&instance)),
        11128394679232495618ull,
        "f()"
    );
}
