
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.32.h"

void test() {
    m14_floatX5FexprsX2E32Instance instance;
    m14_floatX5FexprsX2E32Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.32.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E32Export19_f32X2EnoX5FfoldX5FmulX5Fdiv(&instance, -3.247671518376755e+16, 1.0121375410693505e-14)),
        3672556236u,
        "f32.no_fold_mul_div(-3.247671518376755e+16, 1.0121375410693505e-14)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E32Export19_f32X2EnoX5FfoldX5FmulX5Fdiv(&instance, -1.556116302481314e-08, 1.5799828385609998e-32)),
        2995104594u,
        "f32.no_fold_mul_div(-1.556116302481314e-08, 1.5799828385609998e-32)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E32Export19_f32X2EnoX5FfoldX5FmulX5Fdiv(&instance, -6.763110003396491e-15, -441323995791360.0)),
        2817764013u,
        "f32.no_fold_mul_div(-6.763110003396491e-15, -441323995791360.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E32Export19_f32X2EnoX5FfoldX5FmulX5Fdiv(&instance, 7505613726679040.0, -2.1603840804897423e+18)),
        1507152518u,
        "f32.no_fold_mul_div(7505613726679040.0, -2.1603840804897423e+18)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E32Export19_f32X2EnoX5FfoldX5FmulX5Fdiv(&instance, -2.362576059154981e-28, -1.0808759269564927e-11)),
        2442510079u,
        "f32.no_fold_mul_div(-2.362576059154981e-28, -1.0808759269564927e-11)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E32Export19_f64X2EnoX5FfoldX5FmulX5Fdiv(&instance, -1.3532103713575586e-252, -3.347836467564916e-62)),
        10062123074470422078ull,
        "f64.no_fold_mul_div(-1.3532103713575586e-252, -3.347836467564916e-62)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E32Export19_f64X2EnoX5FfoldX5FmulX5Fdiv(&instance, 7.7662174313180845e+115, 1.9595915560693953e+176)),
        6340937764684870565ull,
        "f64.no_fold_mul_div(7.7662174313180845e+115, 1.9595915560693953e+176)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E32Export19_f64X2EnoX5FfoldX5FmulX5Fdiv(&instance, -7.180117811902948e+71, -9.320036042623636e-167)),
        14905228263410157970ull,
        "f64.no_fold_mul_div(-7.180117811902948e+71, -9.320036042623636e-167)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E32Export19_f64X2EnoX5FfoldX5FmulX5Fdiv(&instance, 1.7260010724693063e-50, 3.568792428129926e-273)),
        3862079437827029803ull,
        "f64.no_fold_mul_div(1.7260010724693063e-50, 3.568792428129926e-273)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E32Export19_f64X2EnoX5FfoldX5FmulX5Fdiv(&instance, -9.145223045828962e+198, -5.562094034342845e-99)),
        16807035693954817237ull,
        "f64.no_fold_mul_div(-9.145223045828962e+198, -5.562094034342845e-99)"
    );
}
