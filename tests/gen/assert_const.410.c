
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.410.h"

void test() {
    m9_constX2E410Instance instance;
    m9_constX2E410Instantiate(&instance, resolveTestImports);
    printStart("const.410.wasm");
    assertEqualF64(
        m9_constX2E410Export1_f(&instance),
        1.5845632502852868e+29,
        "f()"
    );
}
