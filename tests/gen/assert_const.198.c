
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.198.h"

void test() {
    m9_constX2E198Instance instance;
    m9_constX2E198Instantiate(&instance, resolveTestImports);
    printStart("const.198.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E198Export1_f(&instance)),
        645922818u,
        "f()"
    );
}
