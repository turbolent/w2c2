
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.335.h"

void test() {
    m9_constX2E335Instance instance;
    m9_constX2E335Instantiate(&instance, resolveTestImports);
    printStart("const.335.wasm");
    assertEqualF64(
        m9_constX2E335Export1_f(&instance),
        -2.409919865102885e-181,
        "f()"
    );
}
