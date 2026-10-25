
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.316.h"

void test() {
    m9_constX2E316Instance instance;
    m9_constX2E316Instantiate(&instance, resolveTestImports);
    printStart("const.316.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E316Export1_f(&instance)),
        2139095039u,
        "f()"
    );
}
