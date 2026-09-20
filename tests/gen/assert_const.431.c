
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.431.h"

void test() {
    m9_constX2E431Instance instance;
    m9_constX2E431Instantiate(&instance, resolveTestImports);
    printStart("const.431.wasm");
    assertEqualF64(
        m9_constX2E431Export1_f(&instance),
        -1.5845632502852875e+29,
        "f()"
    );
}
