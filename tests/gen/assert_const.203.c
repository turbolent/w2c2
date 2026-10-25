
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.203.h"

void test() {
    m9_constX2E203Instance instance;
    m9_constX2E203Instantiate(&instance, resolveTestImports);
    printStart("const.203.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E203Export1_f(&instance)),
        2793406466u,
        "f()"
    );
}
