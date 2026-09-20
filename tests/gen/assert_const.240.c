
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.240.h"

void test() {
    m9_constX2E240Instance instance;
    m9_constX2E240Instantiate(&instance, resolveTestImports);
    printStart("const.240.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E240Export1_f(&instance)),
        1484783617u,
        "f()"
    );
}
