
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.219.h"

void test() {
    m9_constX2E219Instance instance;
    m9_constX2E219Instantiate(&instance, resolveTestImports);
    printStart("const.219.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E219Export1_f(&instance)),
        2793406466u,
        "f()"
    );
}
