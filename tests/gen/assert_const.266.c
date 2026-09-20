
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.266.h"

void test() {
    m9_constX2E266Instance instance;
    m9_constX2E266Instantiate(&instance, resolveTestImports);
    printStart("const.266.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E266Export1_f(&instance)),
        1484783616u,
        "f()"
    );
}
