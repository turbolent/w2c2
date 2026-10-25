
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.282.h"

void test() {
    m9_constX2E282Instance instance;
    m9_constX2E282Instantiate(&instance, resolveTestImports);
    printStart("const.282.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E282Export1_f(&instance)),
        1484783617u,
        "f()"
    );
}
