
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.291.h"

void test() {
    m9_constX2E291Instance instance;
    m9_constX2E291Instantiate(&instance, resolveTestImports);
    printStart("const.291.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E291Export1_f(&instance)),
        2147483649u,
        "f()"
    );
}
