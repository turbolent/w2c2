
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.225.h"

void test() {
    m9_constX2E225Instance instance;
    m9_constX2E225Instantiate(&instance, resolveTestImports);
    printStart("const.225.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E225Export1_f(&instance)),
        2793406466u,
        "f()"
    );
}
