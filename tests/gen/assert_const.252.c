
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.252.h"

void test() {
    m9_constX2E252Instance instance;
    m9_constX2E252Instantiate(&instance, resolveTestImports);
    printStart("const.252.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E252Export1_f(&instance)),
        1484783618u,
        "f()"
    );
}
