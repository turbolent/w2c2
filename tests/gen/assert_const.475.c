
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.475.h"

void test() {
    m9_constX2E475Instance instance;
    m9_constX2E475Instantiate(&instance, resolveTestImports);
    printStart("const.475.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E475Export1_f(&instance)),
        18442240474082181119ull,
        "f()"
    );
}
