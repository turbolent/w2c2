
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.377.h"

void test() {
    m9_constX2E377Instance instance;
    m9_constX2E377Instantiate(&instance, resolveTestImports);
    printStart("const.377.wasm");
    assertEqualF64(
        m9_constX2E377Export1_f(&instance),
        -5.357543035931338e+300,
        "f()"
    );
}
