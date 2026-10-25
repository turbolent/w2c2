
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.187.h"

void test() {
    m9_constX2E187Instance instance;
    m9_constX2E187Instantiate(&instance, resolveTestImports);
    printStart("const.187.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E187Export1_f(&instance)),
        2793406465u,
        "f()"
    );
}
