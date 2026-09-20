
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.380.h"

void test() {
    m9_constX2E380Instance instance;
    m9_constX2E380Instantiate(&instance, resolveTestImports);
    printStart("const.380.wasm");
    assertEqualF64(
        m9_constX2E380Export1_f(&instance),
        5.357543035931339e+300,
        "f()"
    );
}
