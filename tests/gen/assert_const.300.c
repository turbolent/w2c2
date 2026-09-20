
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.300.h"

void test() {
    m9_constX2E300Instance instance;
    m9_constX2E300Instantiate(&instance, resolveTestImports);
    printStart("const.300.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E300Export1_f(&instance)),
        2u,
        "f()"
    );
}
