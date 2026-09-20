
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.438.h"

void test() {
    m9_constX2E438Instance instance;
    m9_constX2E438Instantiate(&instance, resolveTestImports);
    printStart("const.438.wasm");
    assertEqualF64(
        m9_constX2E438Export1_f(&instance),
        1.152921504606847e+18,
        "f()"
    );
}
