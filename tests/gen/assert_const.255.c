
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.255.h"

void test() {
    m9_constX2E255Instance instance;
    m9_constX2E255Instantiate(&instance, resolveTestImports);
    printStart("const.255.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E255Export1_f(&instance)),
        3632267266u,
        "f()"
    );
}
