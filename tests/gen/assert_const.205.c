
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.205.h"

void test() {
    m9_constX2E205Instance instance;
    m9_constX2E205Instantiate(&instance, resolveTestImports);
    printStart("const.205.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E205Export1_f(&instance)),
        2793406467u,
        "f()"
    );
}
