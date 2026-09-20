
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.460.h"

void test() {
    m9_constX2E460Instance instance;
    m9_constX2E460Instantiate(&instance, resolveTestImports);
    printStart("const.460.wasm");
    assertEqualF64(
        m9_constX2E460Export1_f(&instance),
        1e-323,
        "f()"
    );
}
