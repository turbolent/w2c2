
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.317.h"

void test() {
    m9_constX2E317Instance instance;
    m9_constX2E317Instantiate(&instance, resolveTestImports);
    printStart("const.317.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E317Export1_f(&instance)),
        4286578687u,
        "f()"
    );
}
