
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.91.h"

void test() {
    m14_floatX5FexprsX2E91Instance instance;
    m14_floatX5FexprsX2E91Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.91.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E91Export16_f32X2Econtract2fma(&instance, 1.0, 1.0)),
        0u,
        "f32.contract2fma(1.0, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E91Export16_f32X2Econtract2fma(&instance, 1.100000023841858, 1.100000023841858)),
        0u,
        "f32.contract2fma(1.100000023841858, 1.100000023841858)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E91Export16_f32X2Econtract2fma(&instance, 1.1999999284744263, 1.1999999284744263)),
        0u,
        "f32.contract2fma(1.1999999284744263, 1.1999999284744263)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E91Export16_f64X2Econtract2fma(&instance, 1.0, 1.0)),
        0ull,
        "f64.contract2fma(1.0, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E91Export16_f64X2Econtract2fma(&instance, 1.1, 1.1)),
        0ull,
        "f64.contract2fma(1.1, 1.1)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E91Export16_f64X2Econtract2fma(&instance, 1.2, 1.2)),
        0ull,
        "f64.contract2fma(1.2, 1.2)"
    );
}
