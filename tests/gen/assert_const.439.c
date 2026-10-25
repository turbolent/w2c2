
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.439.h"

void test() {
    m9_constX2E439Instance instance;
    m9_constX2E439Instantiate(&instance, resolveTestImports);
    printStart("const.439.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E439Export1_f(&instance)),
        14100770433297022976ull,
        "f()"
    );
}
