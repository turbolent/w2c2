
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.437.h"

void test() {
    m9_constX2E437Instance instance;
    m9_constX2E437Instantiate(&instance, resolveTestImports);
    printStart("const.437.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E437Export1_f(&instance)),
        14267403619509731331ull,
        "f()"
    );
}
