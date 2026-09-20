
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.229.h"

void test() {
    m9_constX2E229Instance instance;
    m9_constX2E229Instantiate(&instance, resolveTestImports);
    printStart("const.229.wasm");
    assertEqualF32(
        m9_constX2E229Export1_f(&instance),
        -8.881787373374805e-16,
        "f()"
    );
}
