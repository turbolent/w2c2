
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.424.h"

void test() {
    m9_constX2E424Instance instance;
    m9_constX2E424Instantiate(&instance, resolveTestImports);
    printStart("const.424.wasm");
    assertEqualF64(
        m9_constX2E424Export1_f(&instance),
        1.5845632502852875e+29,
        "f()"
    );
}
