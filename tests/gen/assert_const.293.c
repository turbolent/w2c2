
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.293.h"

void test() {
    m9_constX2E293Instance instance;
    m9_constX2E293Instantiate(&instance, resolveTestImports);
    printStart("const.293.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E293Export1_f(&instance)),
        2147483649u,
        "f()"
    );
}
