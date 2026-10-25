
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.247.h"

void test() {
    m9_constX2E247Instance instance;
    m9_constX2E247Instantiate(&instance, resolveTestImports);
    printStart("const.247.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E247Export1_f(&instance)),
        3632267265u,
        "f()"
    );
}
