
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.284.h"

void test() {
    m9_constX2E284Instance instance;
    m9_constX2E284Instantiate(&instance, resolveTestImports);
    printStart("const.284.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E284Export1_f(&instance)),
        1484783617u,
        "f()"
    );
}
