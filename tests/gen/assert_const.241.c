
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.241.h"

void test() {
    m9_constX2E241Instance instance;
    m9_constX2E241Instantiate(&instance, resolveTestImports);
    printStart("const.241.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E241Export1_f(&instance)),
        3632267265u,
        "f()"
    );
}
