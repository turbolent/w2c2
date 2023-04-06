
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.0.h"

void test() {
    floatexprs0Instance instance;
    floatexprs0Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.0.wasm");
    assertEqualF64(
        floatexprs0_f64X2Eno_contraction(&instance, -1.5967133604096234e-31, 8.763352160827123e+199, 4.289657620489846e+160),
        -1.3992561434270632e+169,
        "f64.no_contraction(-1.5967133604096234e-31, 8.763352160827123e+199, 4.289657620489846e+160)"
    );
    assertEqualF64(
        floatexprs0_f64X2Eno_contraction(&instance, 8341016642481988.0, 3.223424965918293e-97, 2.3310835741659086e-91),
        2.6886641288847496e-81,
        "f64.no_contraction(8341016642481988.0, 3.223424965918293e-97, 2.3310835741659086e-91)"
    );
    assertEqualF64(
        floatexprs0_f64X2Eno_contraction(&instance, -3.0119045290520013e-179, 5.269933643923675e+160, 6.654454781339856e-32),
        -1.5872537009936566e-18,
        "f64.no_contraction(-3.0119045290520013e-179, 5.269933643923675e+160, 6.654454781339856e-32)"
    );
    assertEqualF64(
        floatexprs0_f64X2Eno_contraction(&instance, 3.1413936116780743e-21, -7.262766035707377e-31, 4.619684894228461e-66),
        -2.28152068276836e-51,
        "f64.no_contraction(3.1413936116780743e-21, -7.262766035707377e-31, 4.619684894228461e-66)"
    );
    assertEqualF64(
        floatexprs0_f64X2Eno_contraction(&instance, -1.6080464217402378e-286, -3.82103410226833e+281, 1.0541980504151345e-16),
        6.144400215510552e-05,
        "f64.no_contraction(-1.6080464217402378e-286, -3.82103410226833e+281, 1.0541980504151345e-16)"
    );
}
