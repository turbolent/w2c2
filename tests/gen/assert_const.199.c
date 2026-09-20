
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.199.h"

void test() {
    m9_constX2E199Instance instance;
    m9_constX2E199Instantiate(&instance, resolveTestImports);
    printStart("const.199.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E199Export1_f(&instance)),
        2793406466u,
        "f()"
    );
}
