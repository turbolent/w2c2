
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.259.h"

void test() {
    m9_constX2E259Instance instance;
    m9_constX2E259Instantiate(&instance, resolveTestImports);
    printStart("const.259.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E259Export1_f(&instance)),
        3632267266u,
        "f()"
    );
}
