
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.456.h"

void test() {
    m9_constX2E456Instance instance;
    m9_constX2E456Instantiate(&instance, resolveTestImports);
    printStart("const.456.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E456Export1_f(&instance)),
        1ull,
        "f()"
    );
}
