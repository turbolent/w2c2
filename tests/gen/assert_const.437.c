
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.437.h"

void test() {
    m9_constX2E437Instance instance;
    m9_constX2E437Instantiate(&instance, resolveTestImports);
    printStart("const.437.wasm");
    assertEqualF64(
        m9_constX2E437Export1_f(&instance),
        -1.5845632502852878e+29,
        "f()"
    );
}
