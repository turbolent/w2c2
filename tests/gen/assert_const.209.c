
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.209.h"

void test() {
    m9_constX2E209Instance instance;
    m9_constX2E209Instantiate(&instance, resolveTestImports);
    printStart("const.209.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E209Export1_f(&instance)),
        2793406465u,
        "f()"
    );
}
