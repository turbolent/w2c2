
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.444.h"

void test() {
    m9_constX2E444Instance instance;
    m9_constX2E444Instantiate(&instance, resolveTestImports);
    printStart("const.444.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E444Export1_f(&instance)),
        4877398396442247170ull,
        "f()"
    );
}
