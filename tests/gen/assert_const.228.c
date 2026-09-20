
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.228.h"

void test() {
    m9_constX2E228Instance instance;
    m9_constX2E228Instantiate(&instance, resolveTestImports);
    printStart("const.228.wasm");
    assertEqualF32(
        m9_constX2E228Export1_f(&instance),
        8.881787373374805e-16,
        "f()"
    );
}
