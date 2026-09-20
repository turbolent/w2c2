
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.77.h"

void test() {
    m14_floatX5FexprsX2E77Instance instance;
    m14_floatX5FexprsX2E77Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.77.wasm");
    assertEqualF32(
        m14_floatX5FexprsX2E77Export35_f32X2EnoX5FflushX5FintermediateX5Fsubnormal(&instance, 1.1754943508222875e-38, 1.1920928955078125e-07, 8388608.0),
        1.1754943508222875e-38,
        "f32.no_flush_intermediate_subnormal(1.1754943508222875e-38, 1.1920928955078125e-07, 8388608.0)"
    );
    assertEqualF64(
        m14_floatX5FexprsX2E77Export35_f64X2EnoX5FflushX5FintermediateX5Fsubnormal(&instance, 2.2250738585072014e-308, 2.220446049250313e-16, 4503599627370496.0),
        2.2250738585072014e-308,
        "f64.no_flush_intermediate_subnormal(2.2250738585072014e-308, 2.220446049250313e-16, 4503599627370496.0)"
    );
}
