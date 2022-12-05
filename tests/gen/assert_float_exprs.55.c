
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.55.h"

void test() {
    floatexprs55Instance instance;
    floatexprs55Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.55.wasm");
    assertEqualF32(
        floatexprs55_f32X5FsqrtX5FminusX5F2(&instance, 4.0),
        0.0,
        "f32_sqrt_minus_2(4.0)"
    );
    assertEqualF64(
        floatexprs55_f64X5FsqrtX5FminusX5F2(&instance, 4.0),
        0.0,
        "f64_sqrt_minus_2(4.0)"
    );
}
