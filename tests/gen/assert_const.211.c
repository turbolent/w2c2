
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.211.h"

void test() {
    m9_constX2E211Instance instance;
    m9_constX2E211Instantiate(&instance, resolveTestImports);
    printStart("const.211.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E211Export1_f(&instance)),
        2793406465u,
        "f()"
    );
}
