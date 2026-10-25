
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.191.h"

void test() {
    m9_constX2E191Instance instance;
    m9_constX2E191Instantiate(&instance, resolveTestImports);
    printStart("const.191.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E191Export1_f(&instance)),
        2793406466u,
        "f()"
    );
}
