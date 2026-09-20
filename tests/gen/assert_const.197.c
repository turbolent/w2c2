
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.197.h"

void test() {
    m9_constX2E197Instance instance;
    m9_constX2E197Instantiate(&instance, resolveTestImports);
    printStart("const.197.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E197Export1_f(&instance)),
        2793406466u,
        "f()"
    );
}
