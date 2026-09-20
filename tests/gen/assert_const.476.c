
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.476.h"

void test() {
    m9_constX2E476Instance instance;
    m9_constX2E476Instantiate(&instance, resolveTestImports);
    printStart("const.476.wasm");
    assertEqualF64(
        m9_constX2E476Export1_f(&instance),
        1.7976931348623157e+308,
        "f()"
    );
}
