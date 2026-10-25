
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.411.h"

void test() {
    m9_constX2E411Instance instance;
    m9_constX2E411Instantiate(&instance, resolveTestImports);
    printStart("const.411.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E411Export1_f(&instance)),
        14267403619509731328ull,
        "f()"
    );
}
