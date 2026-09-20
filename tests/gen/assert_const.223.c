
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.223.h"

void test() {
    m9_constX2E223Instance instance;
    m9_constX2E223Instantiate(&instance, resolveTestImports);
    printStart("const.223.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E223Export1_f(&instance)),
        2793406466u,
        "f()"
    );
}
