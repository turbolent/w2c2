
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.245.h"

void test() {
    m9_constX2E245Instance instance;
    m9_constX2E245Instantiate(&instance, resolveTestImports);
    printStart("const.245.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E245Export1_f(&instance)),
        3632267265u,
        "f()"
    );
}
