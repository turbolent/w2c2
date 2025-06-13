
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.77.h"

void test() {
    floatexprs77Instance instance;
    floatexprs77Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.77.wasm");
    assertEqualF32(
        floatexprs77_f32X2Eno_flush_intermediate_subnormal(&instance, 1.1754943508222875e-38, 1.1920928955078125e-07, 8388608.0),
        1.1754943508222875e-38,
        "f32.no_flush_intermediate_subnormal(1.1754943508222875e-38, 1.1920928955078125e-07, 8388608.0)"
    );
    assertEqualF64(
        floatexprs77_f64X2Eno_flush_intermediate_subnormal(&instance, 2.2250738585072014e-308, 2.220446049250313e-16, 4503599627370496.0),
        2.2250738585072014e-308,
        "f64.no_flush_intermediate_subnormal(2.2250738585072014e-308, 2.220446049250313e-16, 4503599627370496.0)"
    );
}
