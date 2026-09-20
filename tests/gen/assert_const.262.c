
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.262.h"

void test() {
    m9_constX2E262Instance instance;
    m9_constX2E262Instantiate(&instance, resolveTestImports);
    printStart("const.262.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E262Export1_f(&instance)),
        1484783618u,
        "f()"
    );
}
