
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.209.h"

void test() {
    m9_constX2E209Instance instance;
    m9_constX2E209Instantiate(&instance, resolveTestImports);
    printStart("const.209.wasm");
    assertEqualF32(
        m9_constX2E209Export1_f(&instance),
        -8.881785255792436e-16,
        "f()"
    );
}
