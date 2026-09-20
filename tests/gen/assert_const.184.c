
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.184.h"

void test() {
    m9_constX2E184Instance instance;
    m9_constX2E184Instantiate(&instance, resolveTestImports);
    printStart("const.184.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E184Export1_f(&instance)),
        645922817u,
        "f()"
    );
}
