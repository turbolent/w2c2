
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.306.h"

void test() {
    m9_constX2E306Instance instance;
    m9_constX2E306Instantiate(&instance, resolveTestImports);
    printStart("const.306.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E306Export1_f(&instance)),
        2u,
        "f()"
    );
}
