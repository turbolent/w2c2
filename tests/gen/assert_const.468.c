
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.468.h"

void test() {
    m9_constX2E468Instance instance;
    m9_constX2E468Instantiate(&instance, resolveTestImports);
    printStart("const.468.wasm");
    assertEqualF64(
        m9_constX2E468Export1_f(&instance),
        1e-323,
        "f()"
    );
}
