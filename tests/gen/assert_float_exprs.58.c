
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.58.h"

void test() {
    m14_floatX5FexprsX2E58Instance instance;
    m14_floatX5FexprsX2E58Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.58.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E58Export23_f32X2EnoX5FfoldX5FrecipX5Frecip(&instance, -7.043578799867927e+19)),
        3765723019u,
        "f32.no_fold_recip_recip(-7.043578799867927e+19)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E58Export23_f32X2EnoX5FfoldX5FrecipX5Frecip(&instance, 1.2466100672499874e-23)),
        426844451u,
        "f32.no_fold_recip_recip(1.2466100672499874e-23)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E58Export23_f32X2EnoX5FfoldX5FrecipX5Frecip(&instance, 9.718454544006024e-20)),
        535132277u,
        "f32.no_fold_recip_recip(9.718454544006024e-20)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E58Export23_f32X2EnoX5FfoldX5FrecipX5Frecip(&instance, -30.400758743286133)),
        3253941442u,
        "f32.no_fold_recip_recip(-30.400758743286133)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E58Export23_f32X2EnoX5FfoldX5FrecipX5Frecip(&instance, 2.3316591903901535e+21)),
        1660734602u,
        "f32.no_fold_recip_recip(2.3316591903901535e+21)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E58Export23_f32X2EnoX5FfoldX5FrecipX5Frecip(&instance, -0.0)),
        2147483648u,
        "f32.no_fold_recip_recip(-0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E58Export23_f32X2EnoX5FfoldX5FrecipX5Frecip(&instance, 0.0)),
        0u,
        "f32.no_fold_recip_recip(0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E58Export23_f32X2EnoX5FfoldX5FrecipX5Frecip(&instance, -INFINITY)),
        4286578688u,
        "f32.no_fold_recip_recip(-INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E58Export23_f32X2EnoX5FfoldX5FrecipX5Frecip(&instance, INFINITY)),
        2139095040u,
        "f32.no_fold_recip_recip(INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E58Export23_f64X2EnoX5FfoldX5FrecipX5Frecip(&instance, -6.5797153436288686e+44)),
        14500888369201570769ull,
        "f64.no_fold_recip_recip(-6.5797153436288686e+44)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E58Export23_f64X2EnoX5FfoldX5FrecipX5Frecip(&instance, -1.4424693186857643e+20)),
        14132092565459057122ull,
        "f64.no_fold_recip_recip(-1.4424693186857643e+20)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E58Export23_f64X2EnoX5FfoldX5FrecipX5Frecip(&instance, 1.8499468920623135e+50)),
        5359183527603521525ull,
        "f64.no_fold_recip_recip(1.8499468920623135e+50)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E58Export23_f64X2EnoX5FfoldX5FrecipX5Frecip(&instance, 5.779584288006583e-207)),
        1521566147669375633ull,
        "f64.no_fold_recip_recip(5.779584288006583e-207)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E58Export23_f64X2EnoX5FfoldX5FrecipX5Frecip(&instance, 5.150117869614164e+271)),
        8671785631545870378ull,
        "f64.no_fold_recip_recip(5.150117869614164e+271)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E58Export23_f64X2EnoX5FfoldX5FrecipX5Frecip(&instance, -0.0)),
        9223372036854775808ull,
        "f64.no_fold_recip_recip(-0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E58Export23_f64X2EnoX5FfoldX5FrecipX5Frecip(&instance, 0.0)),
        0ull,
        "f64.no_fold_recip_recip(0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E58Export23_f64X2EnoX5FfoldX5FrecipX5Frecip(&instance, -INFINITY)),
        18442240474082181120ull,
        "f64.no_fold_recip_recip(-INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E58Export23_f64X2EnoX5FfoldX5FrecipX5Frecip(&instance, INFINITY)),
        9218868437227405312ull,
        "f64.no_fold_recip_recip(INFINITY)"
    );
}
