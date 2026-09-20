
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.210.h"

void test() {
    m9_constX2E210Instance instance;
    m9_constX2E210Instantiate(&instance, resolveTestImports);
    printStart("const.210.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E210Export1_f(&instance)),
        645922817u,
        "f()"
    );
}
