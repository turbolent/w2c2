
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.39.h"

void test() {
    floatexprs39Instance instance;
    floatexprs39Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.39.wasm");
    assertEqualF32(
        floatexprs39_f32X2Ei32X2EnoX5FfoldX5FtruncX5FsX5FconvertX5Fs(&instance, 1.5),
        1.0,
        "f32.i32.no_fold_trunc_s_convert_s(1.5)"
    );
    assertEqualF32(
        floatexprs39_f32X2Ei32X2EnoX5FfoldX5FtruncX5FsX5FconvertX5Fs(&instance, -1.5),
        -1.0,
        "f32.i32.no_fold_trunc_s_convert_s(-1.5)"
    );
    assertEqualF32(
        floatexprs39_f32X2Ei32X2EnoX5FfoldX5FtruncX5FuX5FconvertX5Fs(&instance, 1.5),
        1.0,
        "f32.i32.no_fold_trunc_u_convert_s(1.5)"
    );
    assertEqualF32(
        floatexprs39_f32X2Ei32X2EnoX5FfoldX5FtruncX5FuX5FconvertX5Fs(&instance, -0.5),
        0.0,
        "f32.i32.no_fold_trunc_u_convert_s(-0.5)"
    );
    assertEqualF32(
        floatexprs39_f32X2Ei32X2EnoX5FfoldX5FtruncX5FsX5FconvertX5Fu(&instance, 1.5),
        1.0,
        "f32.i32.no_fold_trunc_s_convert_u(1.5)"
    );
    assertEqualF32(
        floatexprs39_f32X2Ei32X2EnoX5FfoldX5FtruncX5FsX5FconvertX5Fu(&instance, -1.5),
        4294967296.0,
        "f32.i32.no_fold_trunc_s_convert_u(-1.5)"
    );
    assertEqualF32(
        floatexprs39_f32X2Ei32X2EnoX5FfoldX5FtruncX5FuX5FconvertX5Fu(&instance, 1.5),
        1.0,
        "f32.i32.no_fold_trunc_u_convert_u(1.5)"
    );
    assertEqualF32(
        floatexprs39_f32X2Ei32X2EnoX5FfoldX5FtruncX5FuX5FconvertX5Fu(&instance, -0.5),
        0.0,
        "f32.i32.no_fold_trunc_u_convert_u(-0.5)"
    );
    assertEqualF64(
        floatexprs39_f64X2Ei32X2EnoX5FfoldX5FtruncX5FsX5FconvertX5Fs(&instance, 1.5),
        1.0,
        "f64.i32.no_fold_trunc_s_convert_s(1.5)"
    );
    assertEqualF64(
        floatexprs39_f64X2Ei32X2EnoX5FfoldX5FtruncX5FsX5FconvertX5Fs(&instance, -1.5),
        -1.0,
        "f64.i32.no_fold_trunc_s_convert_s(-1.5)"
    );
    assertEqualF64(
        floatexprs39_f64X2Ei32X2EnoX5FfoldX5FtruncX5FuX5FconvertX5Fs(&instance, 1.5),
        1.0,
        "f64.i32.no_fold_trunc_u_convert_s(1.5)"
    );
    assertEqualF64(
        floatexprs39_f64X2Ei32X2EnoX5FfoldX5FtruncX5FuX5FconvertX5Fs(&instance, -0.5),
        0.0,
        "f64.i32.no_fold_trunc_u_convert_s(-0.5)"
    );
    assertEqualF64(
        floatexprs39_f64X2Ei32X2EnoX5FfoldX5FtruncX5FsX5FconvertX5Fu(&instance, 1.5),
        1.0,
        "f64.i32.no_fold_trunc_s_convert_u(1.5)"
    );
    assertEqualF64(
        floatexprs39_f64X2Ei32X2EnoX5FfoldX5FtruncX5FsX5FconvertX5Fu(&instance, -1.5),
        4294967295.0,
        "f64.i32.no_fold_trunc_s_convert_u(-1.5)"
    );
    assertEqualF64(
        floatexprs39_f64X2Ei32X2EnoX5FfoldX5FtruncX5FuX5FconvertX5Fu(&instance, 1.5),
        1.0,
        "f64.i32.no_fold_trunc_u_convert_u(1.5)"
    );
    assertEqualF64(
        floatexprs39_f64X2Ei32X2EnoX5FfoldX5FtruncX5FuX5FconvertX5Fu(&instance, -0.5),
        0.0,
        "f64.i32.no_fold_trunc_u_convert_u(-0.5)"
    );
    assertEqualF32(
        floatexprs39_f32X2Ei64X2EnoX5FfoldX5FtruncX5FsX5FconvertX5Fs(&instance, 1.5),
        1.0,
        "f32.i64.no_fold_trunc_s_convert_s(1.5)"
    );
    assertEqualF32(
        floatexprs39_f32X2Ei64X2EnoX5FfoldX5FtruncX5FsX5FconvertX5Fs(&instance, -1.5),
        -1.0,
        "f32.i64.no_fold_trunc_s_convert_s(-1.5)"
    );
    assertEqualF32(
        floatexprs39_f32X2Ei64X2EnoX5FfoldX5FtruncX5FuX5FconvertX5Fs(&instance, 1.5),
        1.0,
        "f32.i64.no_fold_trunc_u_convert_s(1.5)"
    );
    assertEqualF32(
        floatexprs39_f32X2Ei64X2EnoX5FfoldX5FtruncX5FuX5FconvertX5Fs(&instance, -0.5),
        0.0,
        "f32.i64.no_fold_trunc_u_convert_s(-0.5)"
    );
    assertEqualF32(
        floatexprs39_f32X2Ei64X2EnoX5FfoldX5FtruncX5FsX5FconvertX5Fu(&instance, 1.5),
        1.0,
        "f32.i64.no_fold_trunc_s_convert_u(1.5)"
    );
    assertEqualF32(
        floatexprs39_f32X2Ei64X2EnoX5FfoldX5FtruncX5FsX5FconvertX5Fu(&instance, -1.5),
        1.8446744073709552e+19,
        "f32.i64.no_fold_trunc_s_convert_u(-1.5)"
    );
    assertEqualF32(
        floatexprs39_f32X2Ei64X2EnoX5FfoldX5FtruncX5FuX5FconvertX5Fu(&instance, 1.5),
        1.0,
        "f32.i64.no_fold_trunc_u_convert_u(1.5)"
    );
    assertEqualF32(
        floatexprs39_f32X2Ei64X2EnoX5FfoldX5FtruncX5FuX5FconvertX5Fu(&instance, -0.5),
        0.0,
        "f32.i64.no_fold_trunc_u_convert_u(-0.5)"
    );
    assertEqualF64(
        floatexprs39_f64X2Ei64X2EnoX5FfoldX5FtruncX5FsX5FconvertX5Fs(&instance, 1.5),
        1.0,
        "f64.i64.no_fold_trunc_s_convert_s(1.5)"
    );
    assertEqualF64(
        floatexprs39_f64X2Ei64X2EnoX5FfoldX5FtruncX5FsX5FconvertX5Fs(&instance, -1.5),
        -1.0,
        "f64.i64.no_fold_trunc_s_convert_s(-1.5)"
    );
    assertEqualF64(
        floatexprs39_f64X2Ei64X2EnoX5FfoldX5FtruncX5FuX5FconvertX5Fs(&instance, 1.5),
        1.0,
        "f64.i64.no_fold_trunc_u_convert_s(1.5)"
    );
    assertEqualF64(
        floatexprs39_f64X2Ei64X2EnoX5FfoldX5FtruncX5FuX5FconvertX5Fs(&instance, -0.5),
        0.0,
        "f64.i64.no_fold_trunc_u_convert_s(-0.5)"
    );
    assertEqualF64(
        floatexprs39_f64X2Ei64X2EnoX5FfoldX5FtruncX5FsX5FconvertX5Fu(&instance, 1.5),
        1.0,
        "f64.i64.no_fold_trunc_s_convert_u(1.5)"
    );
    assertEqualF64(
        floatexprs39_f64X2Ei64X2EnoX5FfoldX5FtruncX5FsX5FconvertX5Fu(&instance, -1.5),
        1.8446744073709552e+19,
        "f64.i64.no_fold_trunc_s_convert_u(-1.5)"
    );
    assertEqualF64(
        floatexprs39_f64X2Ei64X2EnoX5FfoldX5FtruncX5FuX5FconvertX5Fu(&instance, 1.5),
        1.0,
        "f64.i64.no_fold_trunc_u_convert_u(1.5)"
    );
    assertEqualF64(
        floatexprs39_f64X2Ei64X2EnoX5FfoldX5FtruncX5FuX5FconvertX5Fu(&instance, -0.5),
        0.0,
        "f64.i64.no_fold_trunc_u_convert_u(-0.5)"
    );
}
