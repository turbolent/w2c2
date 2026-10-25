
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.473.h"

void test() {
    m9_constX2E473Instance instance;
    m9_constX2E473Instantiate(&instance, resolveTestImports);
    printStart("const.473.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E473Export1_f(&instance)),
        9227875636482146307ull,
        "f()"
    );
}
