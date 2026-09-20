
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.297.h"

void test() {
    m9_constX2E297Instance instance;
    m9_constX2E297Instantiate(&instance, resolveTestImports);
    printStart("const.297.wasm");
    assertEqualF32(
        m9_constX2E297Export1_f(&instance),
        -1.401298464324817e-45,
        "f()"
    );
}
