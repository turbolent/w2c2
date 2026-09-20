
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.207.h"

void test() {
    m9_constX2E207Instance instance;
    m9_constX2E207Instantiate(&instance, resolveTestImports);
    printStart("const.207.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E207Export1_f(&instance)),
        2793406464u,
        "f()"
    );
}
