
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.374.h"

void test() {
    m9_constX2E374Instance instance;
    m9_constX2E374Instantiate(&instance, resolveTestImports);
    printStart("const.374.wasm");
    assertEqualF64(
        m9_constX2E374Export1_f(&instance),
        5.357543035931337e+300,
        "f()"
    );
}
