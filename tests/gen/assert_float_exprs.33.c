
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.33.h"

void test() {
    m14_floatX5FexprsX2E33Instance instance;
    m14_floatX5FexprsX2E33Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.33.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E33Export19_f32X2EnoX5FfoldX5FdivX5Fmul(&instance, -511517982720.0, 986062208.0)),
        3538825649u,
        "f32.no_fold_div_mul(-511517982720.0, 986062208.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E33Export19_f32X2EnoX5FfoldX5FdivX5Fmul(&instance, -2.494485295186517e-16, -4.153983354626689e-06)),
        2777664540u,
        "f32.no_fold_div_mul(-2.494485295186517e-16, -4.153983354626689e-06)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E33Export19_f32X2EnoX5FfoldX5FdivX5Fmul(&instance, 2.0827855005069695e-38, -235.19847106933594)),
        14863367u,
        "f32.no_fold_div_mul(2.0827855005069695e-38, -235.19847106933594)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E33Export19_f32X2EnoX5FfoldX5FdivX5Fmul(&instance, -6.249948683472858e-23, -6.96312604972286e+17)),
        2593594656u,
        "f32.no_fold_div_mul(-6.249948683472858e-23, -6.96312604972286e+17)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E33Export19_f32X2EnoX5FfoldX5FdivX5Fmul(&instance, 5.835351440532773e-30, 212781120.0)),
        250394050u,
        "f32.no_fold_div_mul(5.835351440532773e-30, 212781120.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E33Export19_f64X2EnoX5FfoldX5FdivX5Fmul(&instance, 3.5984644259935362e-264, -2.881226329803332e+55)),
        665690577722002880ull,
        "f64.no_fold_div_mul(3.5984644259935362e-264, -2.881226329803332e+55)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E33Export19_f64X2EnoX5FfoldX5FdivX5Fmul(&instance, -1.7486367047479447e-215, 1.6508738454798636e-16)),
        10617267697387344270ull,
        "f64.no_fold_div_mul(-1.7486367047479447e-215, 1.6508738454798636e-16)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E33Export19_f64X2EnoX5FfoldX5FdivX5Fmul(&instance, -3.140341989542684e-44, 9.428298090819196e+128)),
        13179336828827425933ull,
        "f64.no_fold_div_mul(-3.140341989542684e-44, 9.428298090819196e+128)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E33Export19_f64X2EnoX5FfoldX5FdivX5Fmul(&instance, -3.919745428533519e-84, -2.1314747179654705e+85)),
        12582623625647949668ull,
        "f64.no_fold_div_mul(-3.919745428533519e-84, -2.1314747179654705e+85)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E33Export19_f64X2EnoX5FfoldX5FdivX5Fmul(&instance, -5.734160003788982e+186, 6.350805843612229e+297)),
        16624217782795067215ull,
        "f64.no_fold_div_mul(-5.734160003788982e+186, 6.350805843612229e+297)"
    );
}
