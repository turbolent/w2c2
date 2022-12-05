
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.19.h"

void test() {
    floatexprs19Instance instance;
    floatexprs19Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.19.wasm");
    assertEqualF32(
        floatexprs19_f32X2EnoX5FregroupX5FdivX5Fmul(&instance, -2.831348900581148e-35, -7.270787044900695e-20, 1.6406605104124838e-35),
        1.2547467815134785e-19,
        "f32.no_regroup_div_mul(-2.831348900581148e-35, -7.270787044900695e-20, 1.6406605104124838e-35)"
    );
    assertEqualF32(
        floatexprs19_f32X2EnoX5FregroupX5FdivX5Fmul(&instance, -3.145897699301651e+27, -4.0864003417251035e-35, -9.245928315588461e+21),
        -0.0,
        "f32.no_regroup_div_mul(-3.145897699301651e+27, -4.0864003417251035e-35, -9.245928315588461e+21)"
    );
    assertEqualF32(
        floatexprs19_f32X2EnoX5FregroupX5FdivX5Fmul(&instance, -93157.4296875, -8.129265438583388e-07, -1.5469396736694269e-37),
        -4.8954812241811386e+35,
        "f32.no_regroup_div_mul(-93157.4296875, -8.129265438583388e-07, -1.5469396736694269e-37)"
    );
    assertEqualF32(
        floatexprs19_f32X2EnoX5FregroupX5FdivX5Fmul(&instance, -8.899642828403211e-29, 1.7887724636863027e+22, 5.146802318776667e+20),
        -3.09307295741405e-27,
        "f32.no_regroup_div_mul(-8.899642828403211e-29, 1.7887724636863027e+22, 5.146802318776667e+20)"
    );
    assertEqualF32(
        floatexprs19_f32X2EnoX5FregroupX5FdivX5Fmul(&instance, 9.222036179566499e+33, 33330492.0, -3.253108762736574e+21),
        -9.44865493251166e+19,
        "f32.no_regroup_div_mul(9.222036179566499e+33, 33330492.0, -3.253108762736574e+21)"
    );
    assertEqualF64(
        floatexprs19_f64X2EnoX5FregroupX5FdivX5Fmul(&instance, 5.698811412550059e-128, -1.8313439132919336e-36, 9.543270551003098e-194),
        -1.093596114413331e+30,
        "f64.no_regroup_div_mul(5.698811412550059e-128, -1.8313439132919336e-36, 9.543270551003098e-194)"
    );
    assertEqualF64(
        floatexprs19_f64X2EnoX5FregroupX5FdivX5Fmul(&instance, 3.5728928842550755e+101, 3.952760844538651e-135, -1.4507812412549008e+240),
        -0.0,
        "f64.no_regroup_div_mul(3.5728928842550755e+101, 3.952760844538651e-135, -1.4507812412549008e+240)"
    );
    assertEqualF64(
        floatexprs19_f64X2EnoX5FregroupX5FdivX5Fmul(&instance, 9.124278383497107e-145, 5.556134527714797e+271, 2.5090826940306507e-135),
        INFINITY,
        "f64.no_regroup_div_mul(9.124278383497107e-145, 5.556134527714797e+271, 2.5090826940306507e-135)"
    );
    assertEqualF64(
        floatexprs19_f64X2EnoX5FregroupX5FdivX5Fmul(&instance, -4.492093000352015e+144, -1.2087878984017852e+184, -5.966133806260623e+251),
        -9.101350780337626e+76,
        "f64.no_regroup_div_mul(-4.492093000352015e+144, -1.2087878984017852e+184, -5.966133806260623e+251)"
    );
    assertEqualF64(
        floatexprs19_f64X2EnoX5FregroupX5FdivX5Fmul(&instance, 7.470269158630455e-181, 7.568026329781282e-265, -1.055389683973521e-252),
        -5.356807494101561e-193,
        "f64.no_regroup_div_mul(7.470269158630455e-181, 7.568026329781282e-265, -1.055389683973521e-252)"
    );
}
