
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.233.h"

void test() {
    m9_constX2E233Instance instance;
    m9_constX2E233Instantiate(&instance, resolveTestImports);
    printStart("const.233.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E233Export1_f(&instance)),
        2793406465u,
        "f()"
    );
}
