
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.457.h"

void test() {
    m9_constX2E457Instance instance;
    m9_constX2E457Instantiate(&instance, resolveTestImports);
    printStart("const.457.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E457Export1_f(&instance)),
        9223372036854775809ull,
        "f()"
    );
}
