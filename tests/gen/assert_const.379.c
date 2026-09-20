
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.379.h"

void test() {
    m9_constX2E379Instance instance;
    m9_constX2E379Instantiate(&instance, resolveTestImports);
    printStart("const.379.wasm");
    assertEqualF64(
        m9_constX2E379Export1_f(&instance),
        -5.357543035931338e+300,
        "f()"
    );
}
