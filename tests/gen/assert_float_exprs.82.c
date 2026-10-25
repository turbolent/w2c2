
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.82.h"

void test() {
    m14_floatX5FexprsX2E82Instance instance;
    m14_floatX5FexprsX2E82Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.82.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E82Export17_f32X2EcomputeX5Fradix(&instance, 1.0, 1.0)),
        1073741824u,
        "f32.compute_radix(1.0, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E82Export17_f64X2EcomputeX5Fradix(&instance, 1.0, 1.0)),
        4611686018427387904ull,
        "f64.compute_radix(1.0, 1.0)"
    );
}
