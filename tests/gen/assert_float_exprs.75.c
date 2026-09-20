
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.75.h"

void test() {
    m14_floatX5FexprsX2E75Instance instance;
    m14_floatX5FexprsX2E75Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.75.wasm");
    assertEqualU32(
        (i32_reinterpret_f32(m14_floatX5FexprsX2E75Export21_f32X2EnoX5FfoldX5FdivX5Fsqrts(&instance, -58545012.0, -6.443772954144732e-18)) & 2147483647u),
        2143289344u,
        "f32.no_fold_div_sqrts(-58545012.0, -6.443772954144732e-18)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E75Export21_f32X2EnoX5FfoldX5FdivX5Fsqrts(&instance, 7407384064.0, 209778928.0)),
        1086203643u,
        "f32.no_fold_div_sqrts(7407384064.0, 209778928.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E75Export21_f32X2EnoX5FfoldX5FdivX5Fsqrts(&instance, 1.3764125694787306e-36, 54692.8984375)),
        498959746u,
        "f32.no_fold_div_sqrts(1.3764125694787306e-36, 54692.8984375)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E75Export21_f32X2EnoX5FfoldX5FdivX5Fsqrts(&instance, 9.792889648106701e+17, 1.2643551761115646e-09)),
        1439333972u,
        "f32.no_fold_div_sqrts(9.792889648106701e+17, 1.2643551761115646e-09)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E75Export21_f32X2EnoX5FfoldX5FdivX5Fsqrts(&instance, 2.9141283262714446e-34, 1.7928174342978603e-31)),
        1025844032u,
        "f32.no_fold_div_sqrts(2.9141283262714446e-34, 1.7928174342978603e-31)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m14_floatX5FexprsX2E75Export21_f64X2EnoX5FfoldX5FdivX5Fsqrts(&instance, -1.2206137319883022e-214, -8.209583449676083e-57)) & 9223372036854775807ull),
        9221120237041090560ull,
        "f64.no_fold_div_sqrts(-1.2206137319883022e-214, -8.209583449676083e-57)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E75Export21_f64X2EnoX5FfoldX5FdivX5Fsqrts(&instance, 3.3818852462305824e-177, 7.655783976315048e+162)),
        2068364230648818889ull,
        "f64.no_fold_div_sqrts(3.3818852462305824e-177, 7.655783976315048e+162)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E75Export21_f64X2EnoX5FfoldX5FdivX5Fsqrts(&instance, 4.596333567064751e+157, 2.3932467846883046e-33)),
        6030491425828883991ull,
        "f64.no_fold_div_sqrts(4.596333567064751e+157, 2.3932467846883046e-33)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E75Export21_f64X2EnoX5FfoldX5FdivX5Fsqrts(&instance, 2.5327340978668086e-244, 4.475305129961258e+87)),
        2129092583060403799ull,
        "f64.no_fold_div_sqrts(2.5327340978668086e-244, 4.475305129961258e+87)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E75Export21_f64X2EnoX5FfoldX5FdivX5Fsqrts(&instance, 5.103070160197939e-238, 4.601576690980825e+284)),
        702724841785532050ull,
        "f64.no_fold_div_sqrts(5.103070160197939e-238, 4.601576690980825e+284)"
    );
}
