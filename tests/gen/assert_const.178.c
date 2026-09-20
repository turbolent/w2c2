
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.178.h"

void test() {
    m9_constX2E178Instance instance;
    m9_constX2E178Instantiate(&instance, resolveTestImports);
    printStart("const.178.wasm");
    assertEqualF32(
        m9_constX2E178Export1_f(&instance),
        8.881784197001252e-16,
        "f()"
    );
}
