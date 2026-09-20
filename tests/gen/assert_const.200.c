
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.200.h"

void test() {
    m9_constX2E200Instance instance;
    m9_constX2E200Instantiate(&instance, resolveTestImports);
    printStart("const.200.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E200Export1_f(&instance)),
        645922818u,
        "f()"
    );
}
