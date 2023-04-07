
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.67.h"

void test() {
    floatexprs67Instance instance;
    floatexprs67Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.67.wasm");
    assertEqualF32(
        floatexprs67_f32X2Eno_fold_6x_via_add(&instance, -8.555137345589493e+29),
        -5.133082709585151e+30,
        "f32.no_fold_6x_via_add(-8.555137345589493e+29)"
    );
    assertEqualF32(
        floatexprs67_f32X2Eno_fold_6x_via_add(&instance, -1.2095059945729172e-23),
        -7.257036282981865e-23,
        "f32.no_fold_6x_via_add(-1.2095059945729172e-23)"
    );
    assertEqualF32(
        floatexprs67_f32X2Eno_fold_6x_via_add(&instance, 6.642689238252199e-24),
        3.9856133851791384e-23,
        "f32.no_fold_6x_via_add(6.642689238252199e-24)"
    );
    assertEqualF32(
        floatexprs67_f32X2Eno_fold_6x_via_add(&instance, -6.147345965601403e-10),
        -3.688407357316237e-09,
        "f32.no_fold_6x_via_add(-6.147345965601403e-10)"
    );
    assertEqualF32(
        floatexprs67_f32X2Eno_fold_6x_via_add(&instance, -1.209858100766292e+24),
        -7.259148316367375e+24,
        "f32.no_fold_6x_via_add(-1.209858100766292e+24)"
    );
    assertEqualF64(
        floatexprs67_f64X2Eno_fold_6x_via_add(&instance, -3.517044906027714e+20),
        -2.1102269436166286e+21,
        "f64.no_fold_6x_via_add(-3.517044906027714e+20)"
    );
    assertEqualF64(
        floatexprs67_f64X2Eno_fold_6x_via_add(&instance, -1.4824294109868734e-161),
        -8.894576465921239e-161,
        "f64.no_fold_6x_via_add(-1.4824294109868734e-161)"
    );
    assertEqualF64(
        floatexprs67_f64X2Eno_fold_6x_via_add(&instance, -7.484567838781003e+81),
        -4.4907407032686014e+82,
        "f64.no_fold_6x_via_add(-7.484567838781003e+81)"
    );
    assertEqualF64(
        floatexprs67_f64X2Eno_fold_6x_via_add(&instance, 1.7277868192936067e+226),
        1.0366720915761641e+227,
        "f64.no_fold_6x_via_add(1.7277868192936067e+226)"
    );
    assertEqualF64(
        floatexprs67_f64X2Eno_fold_6x_via_add(&instance, -4.311639752519561e+70),
        -2.5869838515117364e+71,
        "f64.no_fold_6x_via_add(-4.311639752519561e+70)"
    );
}
