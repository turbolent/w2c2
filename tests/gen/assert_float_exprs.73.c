
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.73.h"

void test() {
    m14_floatX5FexprsX2E73Instance instance;
    m14_floatX5FexprsX2E73Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.73.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E73Export23_f32X2EnoX5FfoldX5FsqrtX5Fsquare(&instance, -1.8460000706651253e-20)),
        514742673u,
        "f32.no_fold_sqrt_square(-1.8460000706651253e-20)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E73Export23_f32X2EnoX5FfoldX5FsqrtX5Fsquare(&instance, -1.7907473239008437e-22)),
        458819801u,
        "f32.no_fold_sqrt_square(-1.7907473239008437e-22)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E73Export23_f32X2EnoX5FfoldX5FsqrtX5Fsquare(&instance, -7.912078484555785e-22)),
        477049564u,
        "f32.no_fold_sqrt_square(-7.912078484555785e-22)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E73Export23_f32X2EnoX5FfoldX5FsqrtX5Fsquare(&instance, 1.8012937732222048e-26)),
        0u,
        "f32.no_fold_sqrt_square(1.8012937732222048e-26)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E73Export23_f32X2EnoX5FfoldX5FsqrtX5Fsquare(&instance, 6.1050196817521095e+32)),
        2139095040u,
        "f32.no_fold_sqrt_square(6.1050196817521095e+32)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E73Export23_f64X2EnoX5FfoldX5FsqrtX5Fsquare(&instance, 6.209297167747496e-160)),
        2225189011649283571ull,
        "f64.no_fold_sqrt_square(6.209297167747496e-160)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E73Export23_f64X2EnoX5FfoldX5FsqrtX5Fsquare(&instance, -2.4211175303738945e-155)),
        2293676422919064961ull,
        "f64.no_fold_sqrt_square(-2.4211175303738945e-155)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E73Export23_f64X2EnoX5FfoldX5FsqrtX5Fsquare(&instance, -1.6460687611875645e-157)),
        2261392448906973069ull,
        "f64.no_fold_sqrt_square(-1.6460687611875645e-157)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E73Export23_f64X2EnoX5FfoldX5FsqrtX5Fsquare(&instance, -3.797811613378828e-186)),
        0ull,
        "f64.no_fold_sqrt_square(-3.797811613378828e-186)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E73Export23_f64X2EnoX5FfoldX5FsqrtX5Fsquare(&instance, 8.158084284605592e+257)),
        9218868437227405312ull,
        "f64.no_fold_sqrt_square(8.158084284605592e+257)"
    );
}
