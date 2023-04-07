
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.20.h"

void test() {
    floatexprs20Instance instance;
    floatexprs20Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.20.wasm");
    assertEqualF32(
        floatexprs20_f32X2Eno_regroup_mul_div(&instance, -2.831348900581148e-35, -7.270787044900695e-20, 1.6406605104124838e-35),
        0.0,
        "f32.no_regroup_mul_div(-2.831348900581148e-35, -7.270787044900695e-20, 1.6406605104124838e-35)"
    );
    assertEqualF32(
        floatexprs20_f32X2Eno_regroup_mul_div(&instance, -3.145897699301651e+27, -4.0864003417251035e-35, -9.245928315588461e+21),
        -1.3903847991921543e-29,
        "f32.no_regroup_mul_div(-3.145897699301651e+27, -4.0864003417251035e-35, -9.245928315588461e+21)"
    );
    assertEqualF32(
        floatexprs20_f32X2Eno_regroup_mul_div(&instance, -93157.4296875, -8.129265438583388e-07, -1.5469396736694269e-37),
        -4.895481620321951e+35,
        "f32.no_regroup_mul_div(-93157.4296875, -8.129265438583388e-07, -1.5469396736694269e-37)"
    );
    assertEqualF32(
        floatexprs20_f32X2Eno_regroup_mul_div(&instance, -8.899642828403211e-29, 1.7887724636863027e+22, 5.146802318776667e+20),
        -3.0930731500070443e-27,
        "f32.no_regroup_mul_div(-8.899642828403211e-29, 1.7887724636863027e+22, 5.146802318776667e+20)"
    );
    assertEqualF32(
        floatexprs20_f32X2Eno_regroup_mul_div(&instance, 9.222036179566499e+33, 33330492.0, -3.253108762736574e+21),
        -INFINITY,
        "f32.no_regroup_mul_div(9.222036179566499e+33, 33330492.0, -3.253108762736574e+21)"
    );
    assertEqualF64(
        floatexprs20_f64X2Eno_regroup_mul_div(&instance, 5.698811412550059e-128, -1.8313439132919336e-36, 9.543270551003098e-194),
        -1.0935961144133311e+30,
        "f64.no_regroup_mul_div(5.698811412550059e-128, -1.8313439132919336e-36, 9.543270551003098e-194)"
    );
    assertEqualF64(
        floatexprs20_f64X2Eno_regroup_mul_div(&instance, 3.5728928842550755e+101, 3.952760844538651e-135, -1.4507812412549008e+240),
        -9.734611044734945e-274,
        "f64.no_regroup_mul_div(3.5728928842550755e+101, 3.952760844538651e-135, -1.4507812412549008e+240)"
    );
    assertEqualF64(
        floatexprs20_f64X2Eno_regroup_mul_div(&instance, 9.124278383497107e-145, 5.556134527714797e+271, 2.5090826940306507e-135),
        2.0204881364667663e+262,
        "f64.no_regroup_mul_div(9.124278383497107e-145, 5.556134527714797e+271, 2.5090826940306507e-135)"
    );
    assertEqualF64(
        floatexprs20_f64X2Eno_regroup_mul_div(&instance, -4.492093000352015e+144, -1.2087878984017852e+184, -5.966133806260623e+251),
        -INFINITY,
        "f64.no_regroup_mul_div(-4.492093000352015e+144, -1.2087878984017852e+184, -5.966133806260623e+251)"
    );
    assertEqualF64(
        floatexprs20_f64X2Eno_regroup_mul_div(&instance, 7.470269158630455e-181, 7.568026329781282e-265, -1.055389683973521e-252),
        -0.0,
        "f64.no_regroup_mul_div(7.470269158630455e-181, 7.568026329781282e-265, -1.055389683973521e-252)"
    );
}
