
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.76.h"

void test() {
    m14_floatX5FexprsX2E76Instance instance;
    m14_floatX5FexprsX2E76Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.76.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E76Export24_f32X2EnoX5FfoldX5FmulX5FsqrtX5Fdiv(&instance, -4.7285568066582555e+24, 8.677281708846403e+27)),
        4286578688u,
        "f32.no_fold_mul_sqrt_div(-4.7285568066582555e+24, 8.677281708846403e+27)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E76Export24_f32X2EnoX5FfoldX5FmulX5FsqrtX5Fdiv(&instance, -1.1776881788564836e-36, 9.805153097384004e-30)),
        2147483648u,
        "f32.no_fold_mul_sqrt_div(-1.1776881788564836e-36, 9.805153097384004e-30)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E76Export24_f32X2EnoX5FfoldX5FmulX5FsqrtX5Fdiv(&instance, 816717056.0, 3.323170900355518e-39)),
        1849105549u,
        "f32.no_fold_mul_sqrt_div(816717056.0, 3.323170900355518e-39)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E76Export24_f32X2EnoX5FfoldX5FmulX5FsqrtX5Fdiv(&instance, -11932267446272.0, 8.637066802072802e+33)),
        3104219421u,
        "f32.no_fold_mul_sqrt_div(-11932267446272.0, 8.637066802072802e+33)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E76Export24_f32X2EnoX5FfoldX5FmulX5FsqrtX5Fdiv(&instance, -401.02349853515625, 134.33021545410156)),
        3255461622u,
        "f32.no_fold_mul_sqrt_div(-401.02349853515625, 134.33021545410156)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E76Export24_f64X2EnoX5FfoldX5FmulX5FsqrtX5Fdiv(&instance, 1.4681346229104905e+210, 2.466074582285183e+228)),
        9218868437227405312ull,
        "f64.no_fold_mul_sqrt_div(1.4681346229104905e+210, 2.466074582285183e+228)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E76Export24_f64X2EnoX5FfoldX5FmulX5FsqrtX5Fdiv(&instance, -1.7254022016758028e-249, 5.5835540747130025e-202)),
        9223372036854775808ull,
        "f64.no_fold_mul_sqrt_div(-1.7254022016758028e-249, 5.5835540747130025e-202)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E76Export24_f64X2EnoX5FfoldX5FmulX5FsqrtX5Fdiv(&instance, 1.6812810256029166e-128, 7.362783602442129e+168)),
        1432338140829931582ull,
        "f64.no_fold_mul_sqrt_div(1.6812810256029166e-128, 7.362783602442129e+168)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E76Export24_f64X2EnoX5FfoldX5FmulX5FsqrtX5Fdiv(&instance, -1.0605483729939836e+106, 6.22591783694072e-146)),
        16502590179898118478ull,
        "f64.no_fold_mul_sqrt_div(-1.0605483729939836e+106, 6.22591783694072e-146)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E76Export24_f64X2EnoX5FfoldX5FmulX5FsqrtX5Fdiv(&instance, 2.6336349695373093e+31, 3.07914132858533e+253)),
        3180744754328846996ull,
        "f64.no_fold_mul_sqrt_div(2.6336349695373093e+31, 3.07914132858533e+253)"
    );
}
