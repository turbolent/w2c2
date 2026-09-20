
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.449.h"

void test() {
    m9_constX2E449Instance instance;
    m9_constX2E449Instantiate(&instance, resolveTestImports);
    printStart("const.449.wasm");
    assertEqualF64(
        m9_constX2E449Export1_f(&instance),
        -5e-324,
        "f()"
    );
}
