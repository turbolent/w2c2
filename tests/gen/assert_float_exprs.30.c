
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.30.h"

void test() {
    m14_floatX5FexprsX2E30Instance instance;
    m14_floatX5FexprsX2E30Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.30.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E30Export19_f32X2EnoX5FfoldX5FaddX5Fsub(&instance, 1.2138281983817452e-14, -2.0946384182707334e-08)),
        677380096u,
        "f32.no_fold_add_sub(1.2138281983817452e-14, -2.0946384182707334e-08)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E30Export19_f32X2EnoX5FfoldX5FaddX5Fsub(&instance, -1.9768197034863988e-07, 3.7154566143726697e-06)),
        3025420912u,
        "f32.no_fold_add_sub(-1.9768197034863988e-07, 3.7154566143726697e-06)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E30Export19_f32X2EnoX5FfoldX5FaddX5Fsub(&instance, -9.596213016386575e+24, -3.538041396989809e+30)),
        3909091328u,
        "f32.no_fold_add_sub(-9.596213016386575e+24, -3.538041396989809e+30)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E30Export19_f32X2EnoX5FfoldX5FaddX5Fsub(&instance, 5.054345810151827e-24, 2.4572655756057543e-17)),
        415236096u,
        "f32.no_fold_add_sub(5.054345810151827e-24, 2.4572655756057543e-17)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E30Export19_f32X2EnoX5FfoldX5FaddX5Fsub(&instance, -3.3693146823161225e-33, -7.101491652849161e-26)),
        2315255808u,
        "f32.no_fold_add_sub(-3.3693146823161225e-33, -7.101491652849161e-26)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E30Export19_f64X2EnoX5FfoldX5FaddX5Fsub(&instance, -8.445702651973109e-264, 1.110684389828854e-258)),
        9894695622864404480ull,
        "f64.no_fold_add_sub(-8.445702651973109e-264, 1.110684389828854e-258)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E30Export19_f64X2EnoX5FfoldX5FaddX5Fsub(&instance, 8.198798715927055e-165, 4.624035606110903e-159)),
        2152218683357790208ull,
        "f64.no_fold_add_sub(8.198798715927055e-165, 4.624035606110903e-159)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E30Export19_f64X2EnoX5FfoldX5FaddX5Fsub(&instance, -1.3604511322066714e-09, -0.1751431740707098)),
        13697521605247238144ull,
        "f64.no_fold_add_sub(-1.3604511322066714e-09, -0.1751431740707098)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E30Export19_f64X2EnoX5FfoldX5FaddX5Fsub(&instance, -3.944335437865966e-103, 1.663809741322667e-92)),
        12298280617463775232ull,
        "f64.no_fold_add_sub(-3.944335437865966e-103, 1.663809741322667e-92)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E30Export19_f64X2EnoX5FfoldX5FaddX5Fsub(&instance, -5.078309818866e-187, -1.0790431644461104e-177)),
        11043298296775835648ull,
        "f64.no_fold_add_sub(-5.078309818866e-187, -1.0790431644461104e-177)"
    );
}
