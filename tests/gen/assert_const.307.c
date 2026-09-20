
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.307.h"

void test() {
    m9_constX2E307Instance instance;
    m9_constX2E307Instantiate(&instance, resolveTestImports);
    printStart("const.307.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E307Export1_f(&instance)),
        2147483650u,
        "f()"
    );
}
