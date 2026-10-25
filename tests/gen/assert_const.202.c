
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.202.h"

void test() {
    m9_constX2E202Instance instance;
    m9_constX2E202Instantiate(&instance, resolveTestImports);
    printStart("const.202.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E202Export1_f(&instance)),
        645922818u,
        "f()"
    );
}
