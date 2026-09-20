
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.80.h"

void test() {
    m14_floatX5FexprsX2E80Instance instance;
    m14_floatX5FexprsX2E80Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.80.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E80Export23_f32X2EnoX5FdistributeX5Fexact(&instance, -0.0)),
        0u,
        "f32.no_distribute_exact(-0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E80Export23_f64X2EnoX5FdistributeX5Fexact(&instance, -0.0)),
        0ull,
        "f64.no_distribute_exact(-0.0)"
    );
}
