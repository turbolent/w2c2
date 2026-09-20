
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.430.h"

void test() {
    m9_constX2E430Instance instance;
    m9_constX2E430Instantiate(&instance, resolveTestImports);
    printStart("const.430.wasm");
    assertEqualF64(
        m9_constX2E430Export1_f(&instance),
        1.5845632502852875e+29,
        "f()"
    );
}
