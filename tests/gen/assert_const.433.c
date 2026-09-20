
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.433.h"

void test() {
    m9_constX2E433Instance instance;
    m9_constX2E433Instantiate(&instance, resolveTestImports);
    printStart("const.433.wasm");
    assertEqualF64(
        m9_constX2E433Export1_f(&instance),
        -1.5845632502852875e+29,
        "f()"
    );
}
