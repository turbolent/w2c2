
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.315.h"

void test() {
    m9_constX2E315Instance instance;
    m9_constX2E315Instantiate(&instance, resolveTestImports);
    printStart("const.315.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E315Export1_f(&instance)),
        2147483651u,
        "f()"
    );
}
