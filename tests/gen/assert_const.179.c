
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.179.h"

void test() {
    m9_constX2E179Instance instance;
    m9_constX2E179Instantiate(&instance, resolveTestImports);
    printStart("const.179.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E179Export1_f(&instance)),
        2793406464u,
        "f()"
    );
}
