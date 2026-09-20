
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.189.h"

void test() {
    m9_constX2E189Instance instance;
    m9_constX2E189Instantiate(&instance, resolveTestImports);
    printStart("const.189.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E189Export1_f(&instance)),
        2793406465u,
        "f()"
    );
}
