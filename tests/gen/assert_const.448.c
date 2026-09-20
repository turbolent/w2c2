
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.448.h"

void test() {
    m9_constX2E448Instance instance;
    m9_constX2E448Instantiate(&instance, resolveTestImports);
    printStart("const.448.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E448Export1_f(&instance)),
        1ull,
        "f()"
    );
}
