
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.434.h"

void test() {
    m9_constX2E434Instance instance;
    m9_constX2E434Instantiate(&instance, resolveTestImports);
    printStart("const.434.wasm");
    assertEqualF64(
        m9_constX2E434Export1_f(&instance),
        1.5845632502852875e+29,
        "f()"
    );
}
