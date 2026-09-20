
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.415.h"

void test() {
    m9_constX2E415Instance instance;
    m9_constX2E415Instantiate(&instance, resolveTestImports);
    printStart("const.415.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E415Export1_f(&instance)),
        14267403619509731329ull,
        "f()"
    );
}
