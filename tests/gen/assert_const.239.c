
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.239.h"

void test() {
    m9_constX2E239Instance instance;
    m9_constX2E239Instantiate(&instance, resolveTestImports);
    printStart("const.239.wasm");
    assertEqualF32(
        m9_constX2E239Export1_f(&instance),
        -1125899906842624.0,
        "f()"
    );
}
