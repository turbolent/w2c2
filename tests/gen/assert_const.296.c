
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.296.h"

void test() {
    m9_constX2E296Instance instance;
    m9_constX2E296Instantiate(&instance, resolveTestImports);
    printStart("const.296.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E296Export1_f(&instance)),
        1u,
        "f()"
    );
}
