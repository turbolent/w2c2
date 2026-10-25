
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.417.h"

void test() {
    m9_constX2E417Instance instance;
    m9_constX2E417Instantiate(&instance, resolveTestImports);
    printStart("const.417.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E417Export1_f(&instance)),
        14267403619509731329ull,
        "f()"
    );
}
