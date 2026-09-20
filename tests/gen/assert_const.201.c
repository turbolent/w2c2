
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.201.h"

void test() {
    m9_constX2E201Instance instance;
    m9_constX2E201Instantiate(&instance, resolveTestImports);
    printStart("const.201.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E201Export1_f(&instance)),
        2793406466u,
        "f()"
    );
}
