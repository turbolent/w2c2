
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.266.h"

void test() {
    m9_constX2E266Instance instance;
    m9_constX2E266Instantiate(&instance, resolveTestImports);
    printStart("const.266.wasm");
    assertEqualF32(
        m9_constX2E266Export1_f(&instance),
        1125899906842624.0,
        "f()"
    );
}
