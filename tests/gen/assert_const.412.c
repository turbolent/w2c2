
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.412.h"

void test() {
    m9_constX2E412Instance instance;
    m9_constX2E412Instantiate(&instance, resolveTestImports);
    printStart("const.412.wasm");
    assertEqualF64(
        m9_constX2E412Export1_f(&instance),
        1.584563250285287e+29,
        "f()"
    );
}
