
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.94.h"

void test() {
    m14_floatX5FexprsX2E94Instance instance;
    m14_floatX5FexprsX2E94Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.94.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E94Export16_f32X2EsilverX5Fmeans(&instance, 0.0)),
        1065353216u,
        "f32.silver_means(0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E94Export16_f32X2EsilverX5Fmeans(&instance, 1.0)),
        1070537661u,
        "f32.silver_means(1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E94Export16_f32X2EsilverX5Fmeans(&instance, 2.0)),
        1075479162u,
        "f32.silver_means(2.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E94Export16_f32X2EsilverX5Fmeans(&instance, 3.0)),
        1079206061u,
        "f32.silver_means(3.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E94Export16_f32X2EsilverX5Fmeans(&instance, 4.0)),
        1082625502u,
        "f32.silver_means(4.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E94Export16_f32X2EsilverX5Fmeans(&instance, 5.0)),
        1084631458u,
        "f32.silver_means(5.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E94Export16_f64X2EsilverX5Fmeans(&instance, 0.0)),
        4607182418800017408ull,
        "f64.silver_means(0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E94Export16_f64X2EsilverX5Fmeans(&instance, 1.0)),
        4609965796441453736ull,
        "f64.silver_means(1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E94Export16_f64X2EsilverX5Fmeans(&instance, 2.0)),
        4612618744449965542ull,
        "f64.silver_means(2.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E94Export16_f64X2EsilverX5Fmeans(&instance, 3.0)),
        4614619608365706490ull,
        "f64.silver_means(3.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E94Export16_f64X2EsilverX5Fmeans(&instance, 4.0)),
        4616455406968633940ull,
        "f64.silver_means(4.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E94Export16_f64X2EsilverX5Fmeans(&instance, 5.0)),
        4617532346471836922ull,
        "f64.silver_means(5.0)"
    );
}
