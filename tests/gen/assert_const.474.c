
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.474.h"

void test() {
    m9_constX2E474Instance instance;
    m9_constX2E474Instantiate(&instance, resolveTestImports);
    printStart("const.474.wasm");
    assertEqualF64(
        m9_constX2E474Export1_f(&instance),
        1.7976931348623157e+308,
        "f()"
    );
}
