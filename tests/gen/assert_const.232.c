
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.232.h"

void test() {
    m9_constX2E232Instance instance;
    m9_constX2E232Instantiate(&instance, resolveTestImports);
    printStart("const.232.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E232Export1_f(&instance)),
        645922817u,
        "f()"
    );
}
