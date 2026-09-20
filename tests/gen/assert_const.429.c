
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.429.h"

void test() {
    m9_constX2E429Instance instance;
    m9_constX2E429Instantiate(&instance, resolveTestImports);
    printStart("const.429.wasm");
    assertEqualF64(
        m9_constX2E429Export1_f(&instance),
        -1.5845632502852875e+29,
        "f()"
    );
}
