
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.41.h"

void test() {
    floatexprs41Instance instance;
    floatexprs41Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.41.wasm");
    assertEqualF32(
        floatexprs41_f32X2Ei32X2Eno_fold_trunc_s_convert_s(&instance, 1.5),
        1.0,
        "f32.i32.no_fold_trunc_s_convert_s(1.5)"
    );
    assertEqualF32(
        floatexprs41_f32X2Ei32X2Eno_fold_trunc_s_convert_s(&instance, -1.5),
        -1.0,
        "f32.i32.no_fold_trunc_s_convert_s(-1.5)"
    );
    assertEqualF32(
        floatexprs41_f32X2Ei32X2Eno_fold_trunc_u_convert_s(&instance, 1.5),
        1.0,
        "f32.i32.no_fold_trunc_u_convert_s(1.5)"
    );
    assertEqualF32(
        floatexprs41_f32X2Ei32X2Eno_fold_trunc_u_convert_s(&instance, -0.5),
        0.0,
        "f32.i32.no_fold_trunc_u_convert_s(-0.5)"
    );
    assertEqualF32(
        floatexprs41_f32X2Ei32X2Eno_fold_trunc_s_convert_u(&instance, 1.5),
        1.0,
        "f32.i32.no_fold_trunc_s_convert_u(1.5)"
    );
    assertEqualF32(
        floatexprs41_f32X2Ei32X2Eno_fold_trunc_s_convert_u(&instance, -1.5),
        4294967296.0,
        "f32.i32.no_fold_trunc_s_convert_u(-1.5)"
    );
    assertEqualF32(
        floatexprs41_f32X2Ei32X2Eno_fold_trunc_u_convert_u(&instance, 1.5),
        1.0,
        "f32.i32.no_fold_trunc_u_convert_u(1.5)"
    );
    assertEqualF32(
        floatexprs41_f32X2Ei32X2Eno_fold_trunc_u_convert_u(&instance, -0.5),
        0.0,
        "f32.i32.no_fold_trunc_u_convert_u(-0.5)"
    );
    assertEqualF64(
        floatexprs41_f64X2Ei32X2Eno_fold_trunc_s_convert_s(&instance, 1.5),
        1.0,
        "f64.i32.no_fold_trunc_s_convert_s(1.5)"
    );
    assertEqualF64(
        floatexprs41_f64X2Ei32X2Eno_fold_trunc_s_convert_s(&instance, -1.5),
        -1.0,
        "f64.i32.no_fold_trunc_s_convert_s(-1.5)"
    );
    assertEqualF64(
        floatexprs41_f64X2Ei32X2Eno_fold_trunc_u_convert_s(&instance, 1.5),
        1.0,
        "f64.i32.no_fold_trunc_u_convert_s(1.5)"
    );
    assertEqualF64(
        floatexprs41_f64X2Ei32X2Eno_fold_trunc_u_convert_s(&instance, -0.5),
        0.0,
        "f64.i32.no_fold_trunc_u_convert_s(-0.5)"
    );
    assertEqualF64(
        floatexprs41_f64X2Ei32X2Eno_fold_trunc_s_convert_u(&instance, 1.5),
        1.0,
        "f64.i32.no_fold_trunc_s_convert_u(1.5)"
    );
    assertEqualF64(
        floatexprs41_f64X2Ei32X2Eno_fold_trunc_s_convert_u(&instance, -1.5),
        4294967295.0,
        "f64.i32.no_fold_trunc_s_convert_u(-1.5)"
    );
    assertEqualF64(
        floatexprs41_f64X2Ei32X2Eno_fold_trunc_u_convert_u(&instance, 1.5),
        1.0,
        "f64.i32.no_fold_trunc_u_convert_u(1.5)"
    );
    assertEqualF64(
        floatexprs41_f64X2Ei32X2Eno_fold_trunc_u_convert_u(&instance, -0.5),
        0.0,
        "f64.i32.no_fold_trunc_u_convert_u(-0.5)"
    );
    assertEqualF32(
        floatexprs41_f32X2Ei64X2Eno_fold_trunc_s_convert_s(&instance, 1.5),
        1.0,
        "f32.i64.no_fold_trunc_s_convert_s(1.5)"
    );
    assertEqualF32(
        floatexprs41_f32X2Ei64X2Eno_fold_trunc_s_convert_s(&instance, -1.5),
        -1.0,
        "f32.i64.no_fold_trunc_s_convert_s(-1.5)"
    );
    assertEqualF32(
        floatexprs41_f32X2Ei64X2Eno_fold_trunc_u_convert_s(&instance, 1.5),
        1.0,
        "f32.i64.no_fold_trunc_u_convert_s(1.5)"
    );
    assertEqualF32(
        floatexprs41_f32X2Ei64X2Eno_fold_trunc_u_convert_s(&instance, -0.5),
        0.0,
        "f32.i64.no_fold_trunc_u_convert_s(-0.5)"
    );
    assertEqualF32(
        floatexprs41_f32X2Ei64X2Eno_fold_trunc_s_convert_u(&instance, 1.5),
        1.0,
        "f32.i64.no_fold_trunc_s_convert_u(1.5)"
    );
    assertEqualF32(
        floatexprs41_f32X2Ei64X2Eno_fold_trunc_s_convert_u(&instance, -1.5),
        1.8446744073709552e+19,
        "f32.i64.no_fold_trunc_s_convert_u(-1.5)"
    );
    assertEqualF32(
        floatexprs41_f32X2Ei64X2Eno_fold_trunc_u_convert_u(&instance, 1.5),
        1.0,
        "f32.i64.no_fold_trunc_u_convert_u(1.5)"
    );
    assertEqualF32(
        floatexprs41_f32X2Ei64X2Eno_fold_trunc_u_convert_u(&instance, -0.5),
        0.0,
        "f32.i64.no_fold_trunc_u_convert_u(-0.5)"
    );
    assertEqualF64(
        floatexprs41_f64X2Ei64X2Eno_fold_trunc_s_convert_s(&instance, 1.5),
        1.0,
        "f64.i64.no_fold_trunc_s_convert_s(1.5)"
    );
    assertEqualF64(
        floatexprs41_f64X2Ei64X2Eno_fold_trunc_s_convert_s(&instance, -1.5),
        -1.0,
        "f64.i64.no_fold_trunc_s_convert_s(-1.5)"
    );
    assertEqualF64(
        floatexprs41_f64X2Ei64X2Eno_fold_trunc_u_convert_s(&instance, 1.5),
        1.0,
        "f64.i64.no_fold_trunc_u_convert_s(1.5)"
    );
    assertEqualF64(
        floatexprs41_f64X2Ei64X2Eno_fold_trunc_u_convert_s(&instance, -0.5),
        0.0,
        "f64.i64.no_fold_trunc_u_convert_s(-0.5)"
    );
    assertEqualF64(
        floatexprs41_f64X2Ei64X2Eno_fold_trunc_s_convert_u(&instance, 1.5),
        1.0,
        "f64.i64.no_fold_trunc_s_convert_u(1.5)"
    );
    assertEqualF64(
        floatexprs41_f64X2Ei64X2Eno_fold_trunc_s_convert_u(&instance, -1.5),
        1.8446744073709552e+19,
        "f64.i64.no_fold_trunc_s_convert_u(-1.5)"
    );
    assertEqualF64(
        floatexprs41_f64X2Ei64X2Eno_fold_trunc_u_convert_u(&instance, 1.5),
        1.0,
        "f64.i64.no_fold_trunc_u_convert_u(1.5)"
    );
    assertEqualF64(
        floatexprs41_f64X2Ei64X2Eno_fold_trunc_u_convert_u(&instance, -0.5),
        0.0,
        "f64.i64.no_fold_trunc_u_convert_u(-0.5)"
    );
}
