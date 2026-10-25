
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.250.h"

void test() {
    m9_constX2E250Instance instance;
    m9_constX2E250Instantiate(&instance, resolveTestImports);
    printStart("const.250.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E250Export1_f(&instance)),
        1484783618u,
        "f()"
    );
}
