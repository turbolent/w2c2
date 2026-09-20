
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.471.h"

void test() {
    m9_constX2E471Instance instance;
    m9_constX2E471Instantiate(&instance, resolveTestImports);
    printStart("const.471.wasm");
    assertEqualF64(
        m9_constX2E471Export1_f(&instance),
        -1e-323,
        "f()"
    );
}
