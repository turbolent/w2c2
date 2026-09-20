
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.264.h"

void test() {
    m9_constX2E264Instance instance;
    m9_constX2E264Instantiate(&instance, resolveTestImports);
    printStart("const.264.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E264Export1_f(&instance)),
        1484783619u,
        "f()"
    );
}
