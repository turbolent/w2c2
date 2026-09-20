
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.264.h"

void test() {
    m9_constX2E264Instance instance;
    m9_constX2E264Instantiate(&instance, resolveTestImports);
    printStart("const.264.wasm");
    assertEqualF32(
        m9_constX2E264Export1_f(&instance),
        1125900309495808.0,
        "f()"
    );
}
