
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.25.h"

void test() {
    floatexprs25Instance instance;
    floatexprs25Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.25.wasm");
    assertEqualF32(
        floatexprs25_f32X2EnoX5FfoldX5FtoX5Fhypot(&instance, 7.285491363580183e-25, 4.236579586704008e-21),
        4.236653499815384e-21,
        "f32.no_fold_to_hypot(7.285491363580183e-25, 4.236579586704008e-21)"
    );
    assertEqualF32(
        floatexprs25_f32X2EnoX5FfoldX5FtoX5Fhypot(&instance, -7.470285075631299e-22, -7.45374502637483e-33),
        7.468043953354002e-22,
        "f32.no_fold_to_hypot(-7.470285075631299e-22, -7.45374502637483e-33)"
    );
    assertEqualF32(
        floatexprs25_f32X2EnoX5FfoldX5FtoX5Fhypot(&instance, -7.708949923849511e-35, -3.2627214338520023e-21),
        3.2627694975692356e-21,
        "f32.no_fold_to_hypot(-7.708949923849511e-35, -3.2627214338520023e-21)"
    );
    assertEqualF32(
        floatexprs25_f32X2EnoX5FfoldX5FtoX5Fhypot(&instance, -35.42818069458008, 174209.484375),
        174209.5,
        "f32.no_fold_to_hypot(-35.42818069458008, 174209.484375)"
    );
    assertEqualF32(
        floatexprs25_f32X2EnoX5FfoldX5FtoX5Fhypot(&instance, 2.062814311395589e-23, -4.634475271768322e-22),
        4.630320183608342e-22,
        "f32.no_fold_to_hypot(2.062814311395589e-23, -4.634475271768322e-22)"
    );
    assertEqualF64(
        floatexprs25_f64X2EnoX5FfoldX5FtoX5Fhypot(&instance, 3.863640258986321e-192, 1.9133014752624014e-161),
        1.9120893753235554e-161,
        "f64.no_fold_to_hypot(3.863640258986321e-192, 1.9133014752624014e-161)"
    );
    assertEqualF64(
        floatexprs25_f64X2EnoX5FfoldX5FtoX5Fhypot(&instance, 1.3856123895032977e+119, -2.828038515930043e+123),
        2.8280385193244834e+123,
        "f64.no_fold_to_hypot(1.3856123895032977e+119, -2.828038515930043e+123)"
    );
    assertEqualF64(
        floatexprs25_f64X2EnoX5FfoldX5FtoX5Fhypot(&instance, 6.502729096641792e-162, -4.544399933151275e-231),
        6.668276248455232e-162,
        "f64.no_fold_to_hypot(6.502729096641792e-162, -4.544399933151275e-231)"
    );
    assertEqualF64(
        floatexprs25_f64X2EnoX5FfoldX5FtoX5Fhypot(&instance, -2.2340232024202604e-157, 3.435929714143315e-221),
        2.2340232023799234e-157,
        "f64.no_fold_to_hypot(-2.2340232024202604e-157, 3.435929714143315e-221)"
    );
    assertEqualF64(
        floatexprs25_f64X2EnoX5FfoldX5FtoX5Fhypot(&instance, 2.797963998630554e-202, -1.906867996862016e-155),
        1.9068679968620105e-155,
        "f64.no_fold_to_hypot(2.797963998630554e-202, -1.906867996862016e-155)"
    );
}
