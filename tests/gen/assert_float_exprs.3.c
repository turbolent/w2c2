
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.3.h"

void test() {
    m13_floatX5FexprsX2E3Instance instance;
    m13_floatX5FexprsX2E3Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.3.wasm");
    assertEqualF32(
        m13_floatX5FexprsX2E3Export20_f32X2EnoX5FfoldX5FzeroX5Fsub(&instance, 0.0),
        0.0,
        "f32.no_fold_zero_sub(0.0)"
    );
    assertEqualF64(
        m13_floatX5FexprsX2E3Export20_f64X2EnoX5FfoldX5FzeroX5Fsub(&instance, 0.0),
        0.0,
        "f64.no_fold_zero_sub(0.0)"
    );
}
