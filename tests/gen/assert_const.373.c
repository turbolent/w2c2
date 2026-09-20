
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.373.h"

void test() {
    m9_constX2E373Instance instance;
    m9_constX2E373Instantiate(&instance, resolveTestImports);
    printStart("const.373.wasm");
    assertEqualF64(
        m9_constX2E373Export1_f(&instance),
        -2.4099198651028857e-181,
        "f()"
    );
}
