
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.372.h"

void test() {
    m9_constX2E372Instance instance;
    m9_constX2E372Instantiate(&instance, resolveTestImports);
    printStart("const.372.wasm");
    assertEqualF64(
        m9_constX2E372Export1_f(&instance),
        2.4099198651028857e-181,
        "f()"
    );
}
