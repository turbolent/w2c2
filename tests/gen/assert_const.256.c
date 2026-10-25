
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.256.h"

void test() {
    m9_constX2E256Instance instance;
    m9_constX2E256Instantiate(&instance, resolveTestImports);
    printStart("const.256.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E256Export1_f(&instance)),
        1484783618u,
        "f()"
    );
}
