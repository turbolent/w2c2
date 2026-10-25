
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.320.h"

void test() {
    m9_constX2E320Instance instance;
    m9_constX2E320Instantiate(&instance, resolveTestImports);
    printStart("const.320.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E320Export1_f(&instance)),
        2139095039u,
        "f()"
    );
}
