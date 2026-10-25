
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.438.h"

void test() {
    m9_constX2E438Instance instance;
    m9_constX2E438Instantiate(&instance, resolveTestImports);
    printStart("const.438.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E438Export1_f(&instance)),
        4877398396442247168ull,
        "f()"
    );
}
