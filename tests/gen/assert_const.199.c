
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.199.h"

void test() {
    m9_constX2E199Instance instance;
    m9_constX2E199Instantiate(&instance, resolveTestImports);
    printStart("const.199.wasm");
    assertEqualF32(
        m9_constX2E199Export1_f(&instance),
        -8.88178631458362e-16,
        "f()"
    );
}
