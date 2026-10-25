
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.268.h"

void test() {
    m9_constX2E268Instance instance;
    m9_constX2E268Instantiate(&instance, resolveTestImports);
    printStart("const.268.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E268Export1_f(&instance)),
        1484783617u,
        "f()"
    );
}
