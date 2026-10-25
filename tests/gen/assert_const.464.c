
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.464.h"

void test() {
    m9_constX2E464Instance instance;
    m9_constX2E464Instantiate(&instance, resolveTestImports);
    printStart("const.464.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E464Export1_f(&instance)),
        2ull,
        "f()"
    );
}
