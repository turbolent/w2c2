
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.77.h"

void test() {
    m14_floatX5FexprsX2E77Instance instance;
    m14_floatX5FexprsX2E77Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.77.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E77Export35_f32X2EnoX5FflushX5FintermediateX5Fsubnormal(&instance, 1.1754943508222875e-38, 1.1920928955078125e-07, 8388608.0)),
        8388608u,
        "f32.no_flush_intermediate_subnormal(1.1754943508222875e-38, 1.1920928955078125e-07, 8388608.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E77Export35_f64X2EnoX5FflushX5FintermediateX5Fsubnormal(&instance, 2.2250738585072014e-308, 2.220446049250313e-16, 4503599627370496.0)),
        4503599627370496ull,
        "f64.no_flush_intermediate_subnormal(2.2250738585072014e-308, 2.220446049250313e-16, 4503599627370496.0)"
    );
}
