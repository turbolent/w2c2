
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.73.h"

void test() {
    floatexprs73Instance instance;
    floatexprs73Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.73.wasm");
    assertEqualF32(
        floatexprs73_f32X2Eno_fold_sqrt_square(&instance, -1.8460000706651253e-20),
        1.8460010400174057e-20,
        "f32.no_fold_sqrt_square(-1.8460000706651253e-20)"
    );
    assertEqualF32(
        floatexprs73_f32X2Eno_fold_sqrt_square(&instance, -1.7907473239008437e-22),
        1.7952678124321221e-22,
        "f32.no_fold_sqrt_square(-1.7907473239008437e-22)"
    );
    assertEqualF32(
        floatexprs73_f32X2Eno_fold_sqrt_square(&instance, -7.912078484555785e-22),
        7.91442007615797e-22,
        "f32.no_fold_sqrt_square(-7.912078484555785e-22)"
    );
    assertEqualF32(
        floatexprs73_f32X2Eno_fold_sqrt_square(&instance, 1.8012937732222048e-26),
        0.0,
        "f32.no_fold_sqrt_square(1.8012937732222048e-26)"
    );
    assertEqualF32(
        floatexprs73_f32X2Eno_fold_sqrt_square(&instance, 6.1050196817521095e+32),
        INFINITY,
        "f32.no_fold_sqrt_square(6.1050196817521095e+32)"
    );
    assertEqualF64(
        floatexprs73_f64X2Eno_fold_sqrt_square(&instance, 6.209297167747496e-160),
        6.209299542179727e-160,
        "f64.no_fold_sqrt_square(6.209297167747496e-160)"
    );
    assertEqualF64(
        floatexprs73_f64X2Eno_fold_sqrt_square(&instance, -2.4211175303738945e-155),
        2.4211175303738937e-155,
        "f64.no_fold_sqrt_square(-2.4211175303738945e-155)"
    );
    assertEqualF64(
        floatexprs73_f64X2Eno_fold_sqrt_square(&instance, -1.6460687611875645e-157),
        1.6460687611532367e-157,
        "f64.no_fold_sqrt_square(-1.6460687611875645e-157)"
    );
    assertEqualF64(
        floatexprs73_f64X2Eno_fold_sqrt_square(&instance, -3.797811613378828e-186),
        0.0,
        "f64.no_fold_sqrt_square(-3.797811613378828e-186)"
    );
    assertEqualF64(
        floatexprs73_f64X2Eno_fold_sqrt_square(&instance, 8.158084284605592e+257),
        INFINITY,
        "f64.no_fold_sqrt_square(8.158084284605592e+257)"
    );
}
