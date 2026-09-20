
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.93.h"

void test() {
    m14_floatX5FexprsX2E93Instance instance;
    m14_floatX5FexprsX2E93Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.93.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E93Export16_f32X2EgoldenX5Fratio(&instance, 0.5, 1.0, 5.0)),
        1070537661u,
        "f32.golden_ratio(0.5, 1.0, 5.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E93Export16_f64X2EgoldenX5Fratio(&instance, 0.5, 1.0, 5.0)),
        4609965796441453736ull,
        "f64.golden_ratio(0.5, 1.0, 5.0)"
    );
}
