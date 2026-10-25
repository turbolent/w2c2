
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.190.h"

void test() {
    m9_constX2E190Instance instance;
    m9_constX2E190Instantiate(&instance, resolveTestImports);
    printStart("const.190.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m9_constX2E190Export1_f(&instance)),
        645922818u,
        "f()"
    );
}
