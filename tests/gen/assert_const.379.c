
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.379.h"

void test() {
    m9_constX2E379Instance instance;
    m9_constX2E379Instantiate(&instance, resolveTestImports);
    printStart("const.379.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E379Export1_f(&instance)),
        18329650483397918721ull,
        "f()"
    );
}
