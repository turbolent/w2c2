
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.57.h"

void test() {
    m14_floatX5FexprsX2E57Instance instance;
    m14_floatX5FexprsX2E57Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.57.wasm");
    assertEqualF32(
        m14_floatX5FexprsX2E57Export16_f32X5FsqrtX5FminusX5F2(&instance, 4.0),
        0.0,
        "f32_sqrt_minus_2(4.0)"
    );
    assertEqualF64(
        m14_floatX5FexprsX2E57Export16_f64X5FsqrtX5FminusX5F2(&instance, 4.0),
        0.0,
        "f64_sqrt_minus_2(4.0)"
    );
}
