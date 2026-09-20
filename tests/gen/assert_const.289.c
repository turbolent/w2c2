
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.289.h"

void test() {
    m9_constX2E289Instance instance;
    m9_constX2E289Instantiate(&instance, resolveTestImports);
    printStart("const.289.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E289Export1_f(&instance)),
        2147483648u,
        "f()"
    );
}
