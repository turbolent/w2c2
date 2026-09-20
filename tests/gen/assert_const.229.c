
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.229.h"

void test() {
    m9_constX2E229Instance instance;
    m9_constX2E229Instantiate(&instance, resolveTestImports);
    printStart("const.229.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E229Export1_f(&instance)),
        2793406467u,
        "f()"
    );
}
