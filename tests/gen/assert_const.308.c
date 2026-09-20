
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.308.h"

void test() {
    m9_constX2E308Instance instance;
    m9_constX2E308Instantiate(&instance, resolveTestImports);
    printStart("const.308.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E308Export1_f(&instance)),
        2u,
        "f()"
    );
}
