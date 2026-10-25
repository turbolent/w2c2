
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.299.h"

void test() {
    m9_constX2E299Instance instance;
    m9_constX2E299Instantiate(&instance, resolveTestImports);
    printStart("const.299.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E299Export1_f(&instance)),
        2147483649u,
        "f()"
    );
}
