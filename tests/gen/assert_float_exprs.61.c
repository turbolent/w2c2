
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.61.h"

void test() {
    m14_floatX5FexprsX2E61Instance instance;
    m14_floatX5FexprsX2E61Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.61.wasm");
    m14_floatX5FexprsX2E61Export17_f32X2EsimpleX5Fx4X5Fsum(&instance, 0u, 16u, 32u);
    assertEqualF32(
        m14_floatX5FexprsX2E61Export8_f32X2Eload(&instance, 32u),
        2.802596928649634e-45,
        "f32.load(32u)"
    );
    assertEqualF32(
        m14_floatX5FexprsX2E61Export8_f32X2Eload(&instance, 36u),
        0.0,
        "f32.load(36u)"
    );
    assertEqualF32(
        m14_floatX5FexprsX2E61Export8_f32X2Eload(&instance, 40u),
        1.401298464324817e-45,
        "f32.load(40u)"
    );
    assertEqualF32(
        m14_floatX5FexprsX2E61Export8_f32X2Eload(&instance, 44u),
        -1.401298464324817e-45,
        "f32.load(44u)"
    );
}
