
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.25.h"

void test() {
    m14_floatX5FexprsX2E25Instance instance;
    m14_floatX5FexprsX2E25Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.25.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E25Export20_f32X2EnoX5FfoldX5FtoX5Fhypot(&instance, 7.285491363580183e-25, 4.236579586704008e-21)),
        497028710u,
        "f32.no_fold_to_hypot(7.285491363580183e-25, 4.236579586704008e-21)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E25Export20_f32X2EnoX5FfoldX5FtoX5Fhypot(&instance, -7.470285075631299e-22, -7.45374502637483e-33)),
        476165425u,
        "f32.no_fold_to_hypot(-7.470285075631299e-22, -7.45374502637483e-33)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E25Export20_f32X2EnoX5FfoldX5FtoX5Fhypot(&instance, -7.708949923849511e-35, -3.2627214338520023e-21)),
        494307108u,
        "f32.no_fold_to_hypot(-7.708949923849511e-35, -3.2627214338520023e-21)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E25Export20_f32X2EnoX5FfoldX5FtoX5Fhypot(&instance, -35.42818069458008, 174209.484375)),
        1210720352u,
        "f32.no_fold_to_hypot(-35.42818069458008, 174209.484375)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E25Export20_f32X2EnoX5FfoldX5FtoX5Fhypot(&instance, 2.062814311395589e-23, -4.634475271768322e-22)),
        470544734u,
        "f32.no_fold_to_hypot(2.062814311395589e-23, -4.634475271768322e-22)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E25Export20_f64X2EnoX5FfoldX5FtoX5Fhypot(&instance, 3.863640258986321e-192, 1.9133014752624014e-161)),
        2202599296765198670ull,
        "f64.no_fold_to_hypot(3.863640258986321e-192, 1.9133014752624014e-161)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E25Export20_f64X2EnoX5FfoldX5FtoX5Fhypot(&instance, 1.3856123895032977e+119, -2.828038515930043e+123)),
        6453971336171062178ull,
        "f64.no_fold_to_hypot(1.3856123895032977e+119, -2.828038515930043e+123)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E25Export20_f64X2EnoX5FfoldX5FtoX5Fhypot(&instance, 6.502729096641792e-162, -4.544399933151275e-231)),
        2195504818343116800ull,
        "f64.no_fold_to_hypot(6.502729096641792e-162, -4.544399933151275e-231)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E25Export20_f64X2EnoX5FfoldX5FtoX5Fhypot(&instance, -2.2340232024202604e-157, 3.435929714143315e-221)),
        2263210186506929210ull,
        "f64.no_fold_to_hypot(-2.2340232024202604e-157, 3.435929714143315e-221)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E25Export20_f64X2EnoX5FfoldX5FtoX5Fhypot(&instance, 2.797963998630554e-202, -1.906867996862016e-155)),
        2292434337532533215ull,
        "f64.no_fold_to_hypot(2.797963998630554e-202, -1.906867996862016e-155)"
    );
}
