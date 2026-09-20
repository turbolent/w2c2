
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.424.h"

void test() {
    m9_constX2E424Instance instance;
    m9_constX2E424Instantiate(&instance, resolveTestImports);
    printStart("const.424.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E424Export1_f(&instance)),
        5044031582654955522ull,
        "f()"
    );
}
