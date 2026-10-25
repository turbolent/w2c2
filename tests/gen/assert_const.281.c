
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.281.h"

void test() {
    m9_constX2E281Instance instance;
    m9_constX2E281Instantiate(&instance, resolveTestImports);
    printStart("const.281.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E281Export1_f(&instance)),
        3632267264u,
        "f()"
    );
}
