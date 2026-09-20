
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.455.h"

void test() {
    m9_constX2E455Instance instance;
    m9_constX2E455Instantiate(&instance, resolveTestImports);
    printStart("const.455.wasm");
    assertEqualF64(
        m9_constX2E455Export1_f(&instance),
        -5e-324,
        "f()"
    );
}
