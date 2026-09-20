
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.261.h"

void test() {
    m9_constX2E261Instance instance;
    m9_constX2E261Instantiate(&instance, resolveTestImports);
    printStart("const.261.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E261Export1_f(&instance)),
        3632267266u,
        "f()"
    );
}
