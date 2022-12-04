
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.30.h"

void test() {
    floatexprs30Instance instance;
    floatexprs30Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.30.wasm");
    assertEqualF32(
        floatexprs30_f32X2EnoX5FfoldX5FaddX5Fsub(&instance, 1.2138281983817452e-14, -2.0946384182707334e-08),
        1.2434497875801753e-14,
        "f32.no_fold_add_sub(1.2138281983817452e-14, -2.0946384182707334e-08)"
    );
    assertEqualF32(
        floatexprs30_f32X2EnoX5FfoldX5FaddX5Fsub(&instance, -1.9768197034863988e-07, 3.7154566143726697e-06),
        -1.976820840354776e-07,
        "f32.no_fold_add_sub(-1.9768197034863988e-07, 3.7154566143726697e-06)"
    );
    assertEqualF32(
        floatexprs30_f32X2EnoX5FfoldX5FaddX5Fsub(&instance, -9.596213016386575e+24, -3.538041396989809e+30),
        -9.671406556917033e+24,
        "f32.no_fold_add_sub(-9.596213016386575e+24, -3.538041396989809e+30)"
    );
    assertEqualF32(
        floatexprs30_f32X2EnoX5FfoldX5FaddX5Fsub(&instance, 5.054345810151827e-24, 2.4572655756057543e-17),
        4.963083675318166e-24,
        "f32.no_fold_add_sub(5.054345810151827e-24, 2.4572655756057543e-17)"
    );
    assertEqualF32(
        floatexprs30_f32X2EnoX5FfoldX5FaddX5Fsub(&instance, -3.3693146823161225e-33, -7.101491652849161e-26),
        -6.162975822039155e-33,
        "f32.no_fold_add_sub(-3.3693146823161225e-33, -7.101491652849161e-26)"
    );
    assertEqualF64(
        floatexprs30_f64X2EnoX5FfoldX5FaddX5Fsub(&instance, -8.445702651973109e-264, 1.110684389828854e-258),
        -8.445702651873978e-264,
        "f64.no_fold_add_sub(-8.445702651973109e-264, 1.110684389828854e-258)"
    );
    assertEqualF64(
        floatexprs30_f64X2EnoX5FfoldX5FaddX5Fsub(&instance, 8.198798715927055e-165, 4.624035606110903e-159),
        8.198798715897085e-165,
        "f64.no_fold_add_sub(8.198798715927055e-165, 4.624035606110903e-159)"
    );
    assertEqualF64(
        floatexprs30_f64X2EnoX5FfoldX5FaddX5Fsub(&instance, -1.3604511322066714e-09, -0.1751431740707098),
        -1.3604511406306585e-09,
        "f64.no_fold_add_sub(-1.3604511322066714e-09, -0.1751431740707098)"
    );
    assertEqualF64(
        floatexprs30_f64X2EnoX5FfoldX5FaddX5Fsub(&instance, -3.944335437865966e-103, 1.663809741322667e-92),
        -3.9443355500325104e-103,
        "f64.no_fold_add_sub(-3.944335437865966e-103, 1.663809741322667e-92)"
    );
    assertEqualF64(
        floatexprs30_f64X2EnoX5FfoldX5FaddX5Fsub(&instance, -5.078309818866e-187, -1.0790431644461104e-177),
        -5.07831047937567e-187,
        "f64.no_fold_add_sub(-5.078309818866e-187, -1.0790431644461104e-177)"
    );
}
