
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.439.h"

void test() {
    m9_constX2E439Instance instance;
    m9_constX2E439Instantiate(&instance, resolveTestImports);
    printStart("const.439.wasm");
    assertEqualF64(
        m9_constX2E439Export1_f(&instance),
        -1.152921504606847e+18,
        "f()"
    );
}
