
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.226.h"

void test() {
    m9_constX2E226Instance instance;
    m9_constX2E226Instantiate(&instance, resolveTestImports);
    printStart("const.226.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E226Export1_f(&instance)),
        645922818u,
        "f()"
    );
}
