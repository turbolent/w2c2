
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.314.h"

void test() {
    m9_constX2E314Instance instance;
    m9_constX2E314Instantiate(&instance, resolveTestImports);
    printStart("const.314.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E314Export1_f(&instance)),
        3u,
        "f()"
    );
}
