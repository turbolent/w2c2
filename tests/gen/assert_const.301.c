
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.301.h"

void test() {
    m9_constX2E301Instance instance;
    m9_constX2E301Instantiate(&instance, resolveTestImports);
    printStart("const.301.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E301Export1_f(&instance)),
        2147483650u,
        "f()"
    );
}
