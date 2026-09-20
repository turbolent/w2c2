
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.41.h"

void test() {
    m14_floatX5FexprsX2E41Instance instance;
    m14_floatX5FexprsX2E41Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.41.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E41Export33_f32X2Ei32X2EnoX5FfoldX5FtruncX5FsX5FconvertX5Fs(&instance, 1.5)),
        1065353216u,
        "f32.i32.no_fold_trunc_s_convert_s(1.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E41Export33_f32X2Ei32X2EnoX5FfoldX5FtruncX5FsX5FconvertX5Fs(&instance, -1.5)),
        3212836864u,
        "f32.i32.no_fold_trunc_s_convert_s(-1.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E41Export33_f32X2Ei32X2EnoX5FfoldX5FtruncX5FuX5FconvertX5Fs(&instance, 1.5)),
        1065353216u,
        "f32.i32.no_fold_trunc_u_convert_s(1.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E41Export33_f32X2Ei32X2EnoX5FfoldX5FtruncX5FuX5FconvertX5Fs(&instance, -0.5)),
        0u,
        "f32.i32.no_fold_trunc_u_convert_s(-0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E41Export33_f32X2Ei32X2EnoX5FfoldX5FtruncX5FsX5FconvertX5Fu(&instance, 1.5)),
        1065353216u,
        "f32.i32.no_fold_trunc_s_convert_u(1.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E41Export33_f32X2Ei32X2EnoX5FfoldX5FtruncX5FsX5FconvertX5Fu(&instance, -1.5)),
        1333788672u,
        "f32.i32.no_fold_trunc_s_convert_u(-1.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E41Export33_f32X2Ei32X2EnoX5FfoldX5FtruncX5FuX5FconvertX5Fu(&instance, 1.5)),
        1065353216u,
        "f32.i32.no_fold_trunc_u_convert_u(1.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E41Export33_f32X2Ei32X2EnoX5FfoldX5FtruncX5FuX5FconvertX5Fu(&instance, -0.5)),
        0u,
        "f32.i32.no_fold_trunc_u_convert_u(-0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E41Export33_f64X2Ei32X2EnoX5FfoldX5FtruncX5FsX5FconvertX5Fs(&instance, 1.5)),
        4607182418800017408ull,
        "f64.i32.no_fold_trunc_s_convert_s(1.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E41Export33_f64X2Ei32X2EnoX5FfoldX5FtruncX5FsX5FconvertX5Fs(&instance, -1.5)),
        13830554455654793216ull,
        "f64.i32.no_fold_trunc_s_convert_s(-1.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E41Export33_f64X2Ei32X2EnoX5FfoldX5FtruncX5FuX5FconvertX5Fs(&instance, 1.5)),
        4607182418800017408ull,
        "f64.i32.no_fold_trunc_u_convert_s(1.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E41Export33_f64X2Ei32X2EnoX5FfoldX5FtruncX5FuX5FconvertX5Fs(&instance, -0.5)),
        0ull,
        "f64.i32.no_fold_trunc_u_convert_s(-0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E41Export33_f64X2Ei32X2EnoX5FfoldX5FtruncX5FsX5FconvertX5Fu(&instance, 1.5)),
        4607182418800017408ull,
        "f64.i32.no_fold_trunc_s_convert_u(1.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E41Export33_f64X2Ei32X2EnoX5FfoldX5FtruncX5FsX5FconvertX5Fu(&instance, -1.5)),
        4751297606873776128ull,
        "f64.i32.no_fold_trunc_s_convert_u(-1.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E41Export33_f64X2Ei32X2EnoX5FfoldX5FtruncX5FuX5FconvertX5Fu(&instance, 1.5)),
        4607182418800017408ull,
        "f64.i32.no_fold_trunc_u_convert_u(1.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E41Export33_f64X2Ei32X2EnoX5FfoldX5FtruncX5FuX5FconvertX5Fu(&instance, -0.5)),
        0ull,
        "f64.i32.no_fold_trunc_u_convert_u(-0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E41Export33_f32X2Ei64X2EnoX5FfoldX5FtruncX5FsX5FconvertX5Fs(&instance, 1.5)),
        1065353216u,
        "f32.i64.no_fold_trunc_s_convert_s(1.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E41Export33_f32X2Ei64X2EnoX5FfoldX5FtruncX5FsX5FconvertX5Fs(&instance, -1.5)),
        3212836864u,
        "f32.i64.no_fold_trunc_s_convert_s(-1.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E41Export33_f32X2Ei64X2EnoX5FfoldX5FtruncX5FuX5FconvertX5Fs(&instance, 1.5)),
        1065353216u,
        "f32.i64.no_fold_trunc_u_convert_s(1.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E41Export33_f32X2Ei64X2EnoX5FfoldX5FtruncX5FuX5FconvertX5Fs(&instance, -0.5)),
        0u,
        "f32.i64.no_fold_trunc_u_convert_s(-0.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E41Export33_f32X2Ei64X2EnoX5FfoldX5FtruncX5FsX5FconvertX5Fu(&instance, 1.5)),
        1065353216u,
        "f32.i64.no_fold_trunc_s_convert_u(1.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E41Export33_f32X2Ei64X2EnoX5FfoldX5FtruncX5FsX5FconvertX5Fu(&instance, -1.5)),
        1602224128u,
        "f32.i64.no_fold_trunc_s_convert_u(-1.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E41Export33_f32X2Ei64X2EnoX5FfoldX5FtruncX5FuX5FconvertX5Fu(&instance, 1.5)),
        1065353216u,
        "f32.i64.no_fold_trunc_u_convert_u(1.5)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E41Export33_f32X2Ei64X2EnoX5FfoldX5FtruncX5FuX5FconvertX5Fu(&instance, -0.5)),
        0u,
        "f32.i64.no_fold_trunc_u_convert_u(-0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E41Export33_f64X2Ei64X2EnoX5FfoldX5FtruncX5FsX5FconvertX5Fs(&instance, 1.5)),
        4607182418800017408ull,
        "f64.i64.no_fold_trunc_s_convert_s(1.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E41Export33_f64X2Ei64X2EnoX5FfoldX5FtruncX5FsX5FconvertX5Fs(&instance, -1.5)),
        13830554455654793216ull,
        "f64.i64.no_fold_trunc_s_convert_s(-1.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E41Export33_f64X2Ei64X2EnoX5FfoldX5FtruncX5FuX5FconvertX5Fs(&instance, 1.5)),
        4607182418800017408ull,
        "f64.i64.no_fold_trunc_u_convert_s(1.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E41Export33_f64X2Ei64X2EnoX5FfoldX5FtruncX5FuX5FconvertX5Fs(&instance, -0.5)),
        0ull,
        "f64.i64.no_fold_trunc_u_convert_s(-0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E41Export33_f64X2Ei64X2EnoX5FfoldX5FtruncX5FsX5FconvertX5Fu(&instance, 1.5)),
        4607182418800017408ull,
        "f64.i64.no_fold_trunc_s_convert_u(1.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E41Export33_f64X2Ei64X2EnoX5FfoldX5FtruncX5FsX5FconvertX5Fu(&instance, -1.5)),
        4895412794951729152ull,
        "f64.i64.no_fold_trunc_s_convert_u(-1.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E41Export33_f64X2Ei64X2EnoX5FfoldX5FtruncX5FuX5FconvertX5Fu(&instance, 1.5)),
        4607182418800017408ull,
        "f64.i64.no_fold_trunc_u_convert_u(1.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E41Export33_f64X2Ei64X2EnoX5FfoldX5FtruncX5FuX5FconvertX5Fu(&instance, -0.5)),
        0ull,
        "f64.i64.no_fold_trunc_u_convert_u(-0.5)"
    );
}
