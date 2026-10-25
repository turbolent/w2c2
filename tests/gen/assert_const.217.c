
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.217.h"

void test() {
    m9_constX2E217Instance instance;
    m9_constX2E217Instantiate(&instance, resolveTestImports);
    printStart("const.217.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E217Export1_f(&instance)),
        2793406465u,
        "f()"
    );
}
