
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.311.h"

void test() {
    m9_constX2E311Instance instance;
    m9_constX2E311Instantiate(&instance, resolveTestImports);
    printStart("const.311.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E311Export1_f(&instance)),
        2147483650u,
        "f()"
    );
}
