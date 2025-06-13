
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.76.h"

void test() {
    floatexprs76Instance instance;
    floatexprs76Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.76.wasm");
    assertEqualF32(
        floatexprs76_f32X2Eno_fold_mul_sqrt_div(&instance, -4.7285568066582555e+24, 8.677281708846403e+27),
        -INFINITY,
        "f32.no_fold_mul_sqrt_div(-4.7285568066582555e+24, 8.677281708846403e+27)"
    );
    assertEqualF32(
        floatexprs76_f32X2Eno_fold_mul_sqrt_div(&instance, -1.1776881788564836e-36, 9.805153097384004e-30),
        -0.0,
        "f32.no_fold_mul_sqrt_div(-1.1776881788564836e-36, 9.805153097384004e-30)"
    );
    assertEqualF32(
        floatexprs76_f32X2Eno_fold_mul_sqrt_div(&instance, 816717056.0, 3.323170900355518e-39),
        1.416756814348236e+28,
        "f32.no_fold_mul_sqrt_div(816717056.0, 3.323170900355518e-39)"
    );
    assertEqualF32(
        floatexprs76_f32X2Eno_fold_mul_sqrt_div(&instance, -11932267446272.0, 8.637066802072802e+33),
        -0.0001283925521420315,
        "f32.no_fold_mul_sqrt_div(-11932267446272.0, 8.637066802072802e+33)"
    );
    assertEqualF32(
        floatexprs76_f32X2Eno_fold_mul_sqrt_div(&instance, -401.02349853515625, 134.33021545410156),
        -34.600547790527344,
        "f32.no_fold_mul_sqrt_div(-401.02349853515625, 134.33021545410156)"
    );
    assertEqualF64(
        floatexprs76_f64X2Eno_fold_mul_sqrt_div(&instance, 1.4681346229104905e+210, 2.466074582285183e+228),
        INFINITY,
        "f64.no_fold_mul_sqrt_div(1.4681346229104905e+210, 2.466074582285183e+228)"
    );
    assertEqualF64(
        floatexprs76_f64X2Eno_fold_mul_sqrt_div(&instance, -1.7254022016758028e-249, 5.5835540747130025e-202),
        -0.0,
        "f64.no_fold_mul_sqrt_div(-1.7254022016758028e-249, 5.5835540747130025e-202)"
    );
    assertEqualF64(
        floatexprs76_f64X2Eno_fold_mul_sqrt_div(&instance, 1.6812810256029166e-128, 7.362783602442129e+168),
        6.196112486187196e-213,
        "f64.no_fold_mul_sqrt_div(1.6812810256029166e-128, 7.362783602442129e+168)"
    );
    assertEqualF64(
        floatexprs76_f64X2Eno_fold_mul_sqrt_div(&instance, -1.0605483729939836e+106, 6.22591783694072e-146),
        -4.2503900822233765e+178,
        "f64.no_fold_mul_sqrt_div(-1.0605483729939836e+106, 6.22591783694072e-146)"
    );
    assertEqualF64(
        floatexprs76_f64X2Eno_fold_mul_sqrt_div(&instance, 2.6336349695373093e+31, 3.07914132858533e+253),
        4.746142447510695e-96,
        "f64.no_fold_mul_sqrt_div(2.6336349695373093e+31, 3.07914132858533e+253)"
    );
}
