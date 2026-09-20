
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.407.h"

void test() {
    m9_constX2E407Instance instance;
    m9_constX2E407Instantiate(&instance, resolveTestImports);
    printStart("const.407.wasm");
    assertEqualF64(
        m9_constX2E407Export1_f(&instance),
        -4.149515568880995e+180,
        "f()"
    );
}
