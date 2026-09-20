
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.232.h"

void test() {
    m9_constX2E232Instance instance;
    m9_constX2E232Instantiate(&instance, resolveTestImports);
    printStart("const.232.wasm");
    assertEqualF32(
        m9_constX2E232Export1_f(&instance),
        8.881785255792436e-16,
        "f()"
    );
}
