
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.235.h"

void test() {
    m9_constX2E235Instance instance;
    m9_constX2E235Instantiate(&instance, resolveTestImports);
    printStart("const.235.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E235Export1_f(&instance)),
        2793406465u,
        "f()"
    );
}
