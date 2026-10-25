
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.277.h"

void test() {
    m9_constX2E277Instance instance;
    m9_constX2E277Instantiate(&instance, resolveTestImports);
    printStart("const.277.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E277Export1_f(&instance)),
        3632267265u,
        "f()"
    );
}
