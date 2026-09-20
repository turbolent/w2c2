
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.80.h"

void test() {
    m14_floatX5FexprsX2E80Instance instance;
    m14_floatX5FexprsX2E80Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.80.wasm");
    assertEqualF32(
        m14_floatX5FexprsX2E80Export23_f32X2EnoX5FdistributeX5Fexact(&instance, -0.0),
        0.0,
        "f32.no_distribute_exact(-0.0)"
    );
    assertEqualF64(
        m14_floatX5FexprsX2E80Export23_f64X2EnoX5FdistributeX5Fexact(&instance, -0.0),
        0.0,
        "f64.no_distribute_exact(-0.0)"
    );
}
