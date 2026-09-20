
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.419.h"

void test() {
    m9_constX2E419Instance instance;
    m9_constX2E419Instantiate(&instance, resolveTestImports);
    printStart("const.419.wasm");
    assertEqualF64(
        m9_constX2E419Export1_f(&instance),
        -1.584563250285287e+29,
        "f()"
    );
}
