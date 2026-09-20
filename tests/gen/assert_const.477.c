
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.477.h"

void test() {
    m9_constX2E477Instance instance;
    m9_constX2E477Instantiate(&instance, resolveTestImports);
    printStart("const.477.wasm");
    assertEqualF64(
        m9_constX2E477Export1_f(&instance),
        -1.7976931348623157e+308,
        "f()"
    );
}
