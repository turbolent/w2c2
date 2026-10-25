
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.230.h"

void test() {
    m9_constX2E230Instance instance;
    m9_constX2E230Instantiate(&instance, resolveTestImports);
    printStart("const.230.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E230Export1_f(&instance)),
        645922816u,
        "f()"
    );
}
