
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.248.h"

void test() {
    m9_constX2E248Instance instance;
    m9_constX2E248Instantiate(&instance, resolveTestImports);
    printStart("const.248.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E248Export1_f(&instance)),
        1484783617u,
        "f()"
    );
}
