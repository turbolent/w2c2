
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.321.h"

void test() {
    m9_constX2E321Instance instance;
    m9_constX2E321Instantiate(&instance, resolveTestImports);
    printStart("const.321.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E321Export1_f(&instance)),
        4286578687u,
        "f()"
    );
}
