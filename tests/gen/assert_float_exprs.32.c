
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.32.h"

void test() {
    floatexprs32Instance instance;
    floatexprs32Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.32.wasm");
    assertEqualF32(
        floatexprs32_f32X2EnoX5FfoldX5FmulX5Fdiv(&instance, -3.247671518376755e+16, 1.0121375410693505e-14),
        -3.2476713036283904e+16,
        "f32.no_fold_mul_div(-3.247671518376755e+16, 1.0121375410693505e-14)"
    );
    assertEqualF32(
        floatexprs32_f32X2EnoX5FfoldX5FmulX5Fdiv(&instance, -1.556116302481314e-08, 1.5799828385609998e-32),
        -1.5561145261244747e-08,
        "f32.no_fold_mul_div(-1.556116302481314e-08, 1.5799828385609998e-32)"
    );
    assertEqualF32(
        floatexprs32_f32X2EnoX5FfoldX5FmulX5Fdiv(&instance, -6.763110003396491e-15, -441323995791360.0),
        -6.763109579880017e-15,
        "f32.no_fold_mul_div(-6.763110003396491e-15, -441323995791360.0)"
    );
    assertEqualF32(
        floatexprs32_f32X2EnoX5FfoldX5FmulX5Fdiv(&instance, 7505613726679040.0, -2.1603840804897423e+18),
        7505613189808128.0,
        "f32.no_fold_mul_div(7505613726679040.0, -2.1603840804897423e+18)"
    );
    assertEqualF32(
        floatexprs32_f32X2EnoX5FfoldX5FmulX5Fdiv(&instance, -2.362576059154981e-28, -1.0808759269564927e-11),
        -2.362576540637467e-28,
        "f32.no_fold_mul_div(-2.362576059154981e-28, -1.0808759269564927e-11)"
    );
    assertEqualF64(
        floatexprs32_f64X2EnoX5FfoldX5FmulX5Fdiv(&instance, -1.3532103713575586e-252, -3.347836467564916e-62),
        -1.3532103713672434e-252,
        "f64.no_fold_mul_div(-1.3532103713575586e-252, -3.347836467564916e-62)"
    );
    assertEqualF64(
        floatexprs32_f64X2EnoX5FfoldX5FmulX5Fdiv(&instance, 7.7662174313180845e+115, 1.9595915560693953e+176),
        7.766217431318085e+115,
        "f64.no_fold_mul_div(7.7662174313180845e+115, 1.9595915560693953e+176)"
    );
    assertEqualF64(
        floatexprs32_f64X2EnoX5FfoldX5FmulX5Fdiv(&instance, -7.180117811902948e+71, -9.320036042623636e-167),
        -7.1801178119029475e+71,
        "f64.no_fold_mul_div(-7.180117811902948e+71, -9.320036042623636e-167)"
    );
    assertEqualF64(
        floatexprs32_f64X2EnoX5FfoldX5FmulX5Fdiv(&instance, 1.7260010724693063e-50, 3.568792428129926e-273),
        1.661286799244216e-50,
        "f64.no_fold_mul_div(1.7260010724693063e-50, 3.568792428129926e-273)"
    );
    assertEqualF64(
        floatexprs32_f64X2EnoX5FfoldX5FmulX5Fdiv(&instance, -9.145223045828962e+198, -5.562094034342845e-99),
        -9.145223045828963e+198,
        "f64.no_fold_mul_div(-9.145223045828962e+198, -5.562094034342845e-99)"
    );
}
