
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.63.h"

void test() {
    m14_floatX5FexprsX2E63Instance instance;
    m14_floatX5FexprsX2E63Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.63.wasm");
    assertEqualF32(
        m14_floatX5FexprsX2E63Export13_f32X2EkahanX5Fsum(&instance, 0u, 256u),
        -2.1558138246206565e+31,
        "f32.kahan_sum(0u, 256u)"
    );
    assertEqualF32(
        m14_floatX5FexprsX2E63Export13_f32X2EplainX5Fsum(&instance, 0u, 256u),
        -1.6487539472071106e+31,
        "f32.plain_sum(0u, 256u)"
    );
}
