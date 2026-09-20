
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.427.h"

void test() {
    m9_constX2E427Instance instance;
    m9_constX2E427Instantiate(&instance, resolveTestImports);
    printStart("const.427.wasm");
    assertEqualF64(
        m9_constX2E427Export1_f(&instance),
        -1.5845632502852875e+29,
        "f()"
    );
}
