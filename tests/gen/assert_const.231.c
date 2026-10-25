
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.231.h"

void test() {
    m9_constX2E231Instance instance;
    m9_constX2E231Instantiate(&instance, resolveTestImports);
    printStart("const.231.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E231Export1_f(&instance)),
        2793406464u,
        "f()"
    );
}
