
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.421.h"

void test() {
    m9_constX2E421Instance instance;
    m9_constX2E421Instantiate(&instance, resolveTestImports);
    printStart("const.421.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E421Export1_f(&instance)),
        14267403619509731329ull,
        "f()"
    );
}
