
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.61.h"

void test() {
    m14_floatX5FexprsX2E61Instance instance;
    m14_floatX5FexprsX2E61Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.61.wasm");
    m14_floatX5FexprsX2E61Export17_f32X2EsimpleX5Fx4X5Fsum(&instance, 0u, 16u, 32u);
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E61Export8_f32X2Eload(&instance, 32u)),
        2u,
        "f32.load(32u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E61Export8_f32X2Eload(&instance, 36u)),
        0u,
        "f32.load(36u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E61Export8_f32X2Eload(&instance, 40u)),
        1u,
        "f32.load(40u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E61Export8_f32X2Eload(&instance, 44u)),
        2147483649u,
        "f32.load(44u)"
    );
}
