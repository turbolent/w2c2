
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.204.h"

void test() {
    m9_constX2E204Instance instance;
    m9_constX2E204Instantiate(&instance, resolveTestImports);
    printStart("const.204.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E204Export1_f(&instance)),
        645922819u,
        "f()"
    );
}
