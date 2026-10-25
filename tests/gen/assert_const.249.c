
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.249.h"

void test() {
    m9_constX2E249Instance instance;
    m9_constX2E249Instantiate(&instance, resolveTestImports);
    printStart("const.249.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E249Export1_f(&instance)),
        3632267265u,
        "f()"
    );
}
