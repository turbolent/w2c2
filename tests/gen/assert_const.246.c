
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.246.h"

void test() {
    m9_constX2E246Instance instance;
    m9_constX2E246Instantiate(&instance, resolveTestImports);
    printStart("const.246.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E246Export1_f(&instance)),
        1484783617u,
        "f()"
    );
}
