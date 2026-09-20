
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.411.h"

void test() {
    m9_constX2E411Instance instance;
    m9_constX2E411Instantiate(&instance, resolveTestImports);
    printStart("const.411.wasm");
    assertEqualF64(
        m9_constX2E411Export1_f(&instance),
        -1.5845632502852868e+29,
        "f()"
    );
}
