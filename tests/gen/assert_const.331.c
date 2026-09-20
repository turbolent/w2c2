
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.331.h"

void test() {
    m9_constX2E331Instance instance;
    m9_constX2E331Instantiate(&instance, resolveTestImports);
    printStart("const.331.wasm");
    assertEqualF64(
        m9_constX2E331Export1_f(&instance),
        -2.4099198651028847e-181,
        "f()"
    );
}
