
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.278.h"

void test() {
    m9_constX2E278Instance instance;
    m9_constX2E278Instantiate(&instance, resolveTestImports);
    printStart("const.278.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E278Export1_f(&instance)),
        1484783618u,
        "f()"
    );
}
