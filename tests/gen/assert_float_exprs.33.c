
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.33.h"

void test() {
    floatexprs33Instance instance;
    floatexprs33Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.33.wasm");
    assertEqualF32(
        floatexprs33_f32X2EnoX5FfoldX5FdivX5Fmul(&instance, -511517982720.0, 986062208.0),
        -511517949952.0,
        "f32.no_fold_div_mul(-511517982720.0, 986062208.0)"
    );
    assertEqualF32(
        floatexprs33_f32X2EnoX5FfoldX5FdivX5Fmul(&instance, -2.494485295186517e-16, -4.153983354626689e-06),
        -2.494485559884313e-16,
        "f32.no_fold_div_mul(-2.494485295186517e-16, -4.153983354626689e-06)"
    );
    assertEqualF32(
        floatexprs33_f32X2EnoX5FfoldX5FdivX5Fmul(&instance, 2.0827855005069695e-38, -235.19847106933594),
        2.0828013351796163e-38,
        "f32.no_fold_div_mul(2.0827855005069695e-38, -235.19847106933594)"
    );
    assertEqualF32(
        floatexprs33_f32X2EnoX5FfoldX5FdivX5Fmul(&instance, -6.249948683472858e-23, -6.96312604972286e+17),
        -6.249919022302821e-23,
        "f32.no_fold_div_mul(-6.249948683472858e-23, -6.96312604972286e+17)"
    );
    assertEqualF32(
        floatexprs33_f32X2EnoX5FfoldX5FdivX5Fmul(&instance, 5.835351440532773e-30, 212781120.0),
        5.8353518166909656e-30,
        "f32.no_fold_div_mul(5.835351440532773e-30, 212781120.0)"
    );
    assertEqualF64(
        floatexprs33_f64X2EnoX5FfoldX5FdivX5Fmul(&instance, 3.5984644259935362e-264, -2.881226329803332e+55),
        3.5985034356565485e-264,
        "f64.no_fold_div_mul(3.5984644259935362e-264, -2.881226329803332e+55)"
    );
    assertEqualF64(
        floatexprs33_f64X2EnoX5FfoldX5FdivX5Fmul(&instance, -1.7486367047479447e-215, 1.6508738454798636e-16),
        -1.748636704747945e-215,
        "f64.no_fold_div_mul(-1.7486367047479447e-215, 1.6508738454798636e-16)"
    );
    assertEqualF64(
        floatexprs33_f64X2EnoX5FfoldX5FdivX5Fmul(&instance, -3.140341989542684e-44, 9.428298090819196e+128),
        -3.1403419895426836e-44,
        "f64.no_fold_div_mul(-3.140341989542684e-44, 9.428298090819196e+128)"
    );
    assertEqualF64(
        floatexprs33_f64X2EnoX5FfoldX5FdivX5Fmul(&instance, -3.919745428533519e-84, -2.1314747179654705e+85),
        -3.9197454285335185e-84,
        "f64.no_fold_div_mul(-3.919745428533519e-84, -2.1314747179654705e+85)"
    );
    assertEqualF64(
        floatexprs33_f64X2EnoX5FfoldX5FdivX5Fmul(&instance, -5.734160003788982e+186, 6.350805843612229e+297),
        -5.734160003788981e+186,
        "f64.no_fold_div_mul(-5.734160003788982e+186, 6.350805843612229e+297)"
    );
}
