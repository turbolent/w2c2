
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.92.h"

void test() {
    m14_floatX5FexprsX2E92Instance instance;
    m14_floatX5FexprsX2E92Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.92.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E92Export28_f32X2EdivisionX5FbyX5FsmallX5Fnumber(&instance, 112000000.0, 100000.0, 0.0008999999845400453)),
        1230570368u,
        "f32.division_by_small_number(112000000.0, 100000.0, 0.0008999999845400453)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E92Export28_f64X2EdivisionX5FbyX5FsmallX5Fnumber(&instance, 112000000.0, 100000.0, 0.0009)),
        4695882709507797376ull,
        "f64.division_by_small_number(112000000.0, 100000.0, 0.0009)"
    );
}
