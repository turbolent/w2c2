
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.251.h"

void test() {
    m9_constX2E251Instance instance;
    m9_constX2E251Instantiate(&instance, resolveTestImports);
    printStart("const.251.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E251Export1_f(&instance)),
        3632267266u,
        "f()"
    );
}
