
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.74.h"

void test() {
    m14_floatX5FexprsX2E74Instance instance;
    m14_floatX5FexprsX2E74Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.74.wasm");
    assertEqualU32(
        (i32_reinterpret_f32(m14_floatX5FexprsX2E74Export21_f32X2EnoX5FfoldX5FmulX5Fsqrts(&instance, 4.3885046947421455e-38, -1.1867333798281266e-25)) & 2147483647u),
        2143289344u,
        "f32.no_fold_mul_sqrts(4.3885046947421455e-38, -1.1867333798281266e-25)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E74Export21_f32X2EnoX5FfoldX5FmulX5Fsqrts(&instance, 2.536590811126416e-28, 4.132067465967282e-10)),
        549395357u,
        "f32.no_fold_mul_sqrts(2.536590811126416e-28, 4.132067465967282e-10)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E74Export21_f32X2EnoX5FfoldX5FmulX5Fsqrts(&instance, 4.2144832231674335e-27, 97.24911499023438)),
        724841268u,
        "f32.no_fold_mul_sqrts(4.2144832231674335e-27, 97.24911499023438)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E74Export21_f32X2EnoX5FfoldX5FmulX5Fsqrts(&instance, 3.7240763422782964e+30, 0.0029449081048369408)),
        1455324620u,
        "f32.no_fold_mul_sqrts(3.7240763422782964e+30, 0.0029449081048369408)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E74Export21_f32X2EnoX5FfoldX5FmulX5Fsqrts(&instance, 1.8660559344485864e-17, 0.002111261012032628)),
        794443079u,
        "f32.no_fold_mul_sqrts(1.8660559344485864e-17, 0.002111261012032628)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m14_floatX5FexprsX2E74Export21_f64X2EnoX5FfoldX5FmulX5Fsqrts(&instance, -1.2742064369772862e-191, -0.006829962938197246)) & 9223372036854775807ull),
        9221120237041090560ull,
        "f64.no_fold_mul_sqrts(-1.2742064369772862e-191, -0.006829962938197246)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E74Export21_f64X2EnoX5FfoldX5FmulX5Fsqrts(&instance, 3.7082569269527534e-194, 4.7183002857015043e-122)),
        2252469008297979510ull,
        "f64.no_fold_mul_sqrts(3.7082569269527534e-194, 4.7183002857015043e-122)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E74Export21_f64X2EnoX5FfoldX5FmulX5Fsqrts(&instance, 2.329359505918655e-27, 2.0743399642806364e-275)),
        2352856462697312748ull,
        "f64.no_fold_mul_sqrts(2.329359505918655e-27, 2.0743399642806364e-275)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E74Export21_f64X2EnoX5FfoldX5FmulX5Fsqrts(&instance, 1.0541899336289437e-109, 5.98123819872803e-173)),
        2503613111125550255ull,
        "f64.no_fold_mul_sqrts(1.0541899336289437e-109, 5.98123819872803e-173)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E74Export21_f64X2EnoX5FfoldX5FmulX5Fsqrts(&instance, 25589482.717358638, 3.913891207119902e+154)),
        5818898567902921651ull,
        "f64.no_fold_mul_sqrts(25589482.717358638, 3.913891207119902e+154)"
    );
}
