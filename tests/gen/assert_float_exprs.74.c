
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.74.h"

void test() {
    floatexprs74Instance instance;
    floatexprs74Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.74.wasm");
    assertEqualF32(
        floatexprs74_f32X2Eno_fold_mul_sqrts(&instance, 2.536590811126416e-28, 4.132067465967282e-10),
        3.237493152183345e-19,
        "f32.no_fold_mul_sqrts(2.536590811126416e-28, 4.132067465967282e-10)"
    );
    assertEqualF32(
        floatexprs74_f32X2Eno_fold_mul_sqrts(&instance, 4.2144832231674335e-27, 97.24911499023438),
        6.401990482879372e-13,
        "f32.no_fold_mul_sqrts(4.2144832231674335e-27, 97.24911499023438)"
    );
    assertEqualF32(
        floatexprs74_f32X2Eno_fold_mul_sqrts(&instance, 3.7240763422782964e+30, 0.0029449081048369408),
        104723751370752.0,
        "f32.no_fold_mul_sqrts(3.7240763422782964e+30, 0.0029449081048369408)"
    );
    assertEqualF32(
        floatexprs74_f32X2Eno_fold_mul_sqrts(&instance, 1.8660559344485864e-17, 0.002111261012032628),
        1.9848754584383954e-10,
        "f32.no_fold_mul_sqrts(1.8660559344485864e-17, 0.002111261012032628)"
    );
    assertEqualF64(
        floatexprs74_f64X2Eno_fold_mul_sqrts(&instance, 3.7082569269527534e-194, 4.7183002857015043e-122),
        4.1829020688865954e-158,
        "f64.no_fold_mul_sqrts(3.7082569269527534e-194, 4.7183002857015043e-122)"
    );
    assertEqualF64(
        floatexprs74_f64X2Eno_fold_mul_sqrts(&instance, 2.329359505918655e-27, 2.0743399642806364e-275),
        2.1981545701574452e-151,
        "f64.no_fold_mul_sqrts(2.329359505918655e-27, 2.0743399642806364e-275)"
    );
    assertEqualF64(
        floatexprs74_f64X2Eno_fold_mul_sqrts(&instance, 1.0541899336289437e-109, 5.98123819872803e-173),
        2.511047809129887e-141,
        "f64.no_fold_mul_sqrts(1.0541899336289437e-109, 5.98123819872803e-173)"
    );
    assertEqualF64(
        floatexprs74_f64X2Eno_fold_mul_sqrts(&instance, 25589482.717358638, 3.913891207119902e+154),
        1.0007719590506955e+81,
        "f64.no_fold_mul_sqrts(25589482.717358638, 3.913891207119902e+154)"
    );
}
