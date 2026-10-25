
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.213.h"

void test() {
    m9_constX2E213Instance instance;
    m9_constX2E213Instantiate(&instance, resolveTestImports);
    printStart("const.213.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E213Export1_f(&instance)),
        2793406465u,
        "f()"
    );
}
