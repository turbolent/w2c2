
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.56.h"

void test() {
    m14_floatX5FexprsX2E56Instance instance;
    m14_floatX5FexprsX2E56Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.56.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E56Export7_inverse(&instance, 96.0)),
        1009429163u,
        "inverse(96.0)"
    );
}
