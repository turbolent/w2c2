
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.186.h"

void test() {
    m9_constX2E186Instance instance;
    m9_constX2E186Instantiate(&instance, resolveTestImports);
    printStart("const.186.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E186Export1_f(&instance)),
        645922817u,
        "f()"
    );
}
