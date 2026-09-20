
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.378.h"

void test() {
    m9_constX2E378Instance instance;
    m9_constX2E378Instantiate(&instance, resolveTestImports);
    printStart("const.378.wasm");
    assertEqualF64(
        m9_constX2E378Export1_f(&instance),
        5.357543035931338e+300,
        "f()"
    );
}
