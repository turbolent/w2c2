
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.227.h"

void test() {
    m9_constX2E227Instance instance;
    m9_constX2E227Instantiate(&instance, resolveTestImports);
    printStart("const.227.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E227Export1_f(&instance)),
        2793406466u,
        "f()"
    );
}
