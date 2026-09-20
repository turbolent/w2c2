
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.347.h"

void test() {
    m9_constX2E347Instance instance;
    m9_constX2E347Instantiate(&instance, resolveTestImports);
    printStart("const.347.wasm");
    assertEqualF64(
        m9_constX2E347Export1_f(&instance),
        -2.4099198651028857e-181,
        "f()"
    );
}
