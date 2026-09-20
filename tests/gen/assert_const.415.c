
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.415.h"

void test() {
    m9_constX2E415Instance instance;
    m9_constX2E415Instantiate(&instance, resolveTestImports);
    printStart("const.415.wasm");
    assertEqualF64(
        m9_constX2E415Export1_f(&instance),
        -1.584563250285287e+29,
        "f()"
    );
}
