
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.242.h"

void test() {
    m9_constX2E242Instance instance;
    m9_constX2E242Instantiate(&instance, resolveTestImports);
    printStart("const.242.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E242Export1_f(&instance)),
        1484783617u,
        "f()"
    );
}
