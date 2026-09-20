
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.294.h"

void test() {
    m9_constX2E294Instance instance;
    m9_constX2E294Instantiate(&instance, resolveTestImports);
    printStart("const.294.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E294Export1_f(&instance)),
        1u,
        "f()"
    );
}
