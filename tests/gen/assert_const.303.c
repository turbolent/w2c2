
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.303.h"

void test() {
    m9_constX2E303Instance instance;
    m9_constX2E303Instantiate(&instance, resolveTestImports);
    printStart("const.303.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E303Export1_f(&instance)),
        2147483650u,
        "f()"
    );
}
