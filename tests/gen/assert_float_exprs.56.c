
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.56.h"

void test() {
    floatexprs56Instance instance;
    floatexprs56Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.56.wasm");
    assertEqualF32(
        floatexprs56_f32X2Eno_fold_recip_recip(&instance, -7.043578799867927e+19),
        -7.043578360063276e+19,
        "f32.no_fold_recip_recip(-7.043578799867927e+19)"
    );
    assertEqualF32(
        floatexprs56_f32X2Eno_fold_recip_recip(&instance, 1.2466100672499874e-23),
        1.2466099883638969e-23,
        "f32.no_fold_recip_recip(1.2466100672499874e-23)"
    );
    assertEqualF32(
        floatexprs56_f32X2Eno_fold_recip_recip(&instance, 9.718454544006024e-20),
        9.718455190240878e-20,
        "f32.no_fold_recip_recip(9.718454544006024e-20)"
    );
    assertEqualF32(
        floatexprs56_f32X2Eno_fold_recip_recip(&instance, -30.400758743286133),
        -30.400760650634766,
        "f32.no_fold_recip_recip(-30.400758743286133)"
    );
    assertEqualF32(
        floatexprs56_f32X2Eno_fold_recip_recip(&instance, 2.3316591903901535e+21),
        2.3316590496526652e+21,
        "f32.no_fold_recip_recip(2.3316591903901535e+21)"
    );
    assertEqualF32(
        floatexprs56_f32X2Eno_fold_recip_recip(&instance, -0.0),
        -0.0,
        "f32.no_fold_recip_recip(-0.0)"
    );
    assertEqualF32(
        floatexprs56_f32X2Eno_fold_recip_recip(&instance, 0.0),
        0.0,
        "f32.no_fold_recip_recip(0.0)"
    );
    assertEqualF32(
        floatexprs56_f32X2Eno_fold_recip_recip(&instance, -INFINITY),
        -INFINITY,
        "f32.no_fold_recip_recip(-INFINITY)"
    );
    assertEqualF32(
        floatexprs56_f32X2Eno_fold_recip_recip(&instance, INFINITY),
        INFINITY,
        "f32.no_fold_recip_recip(INFINITY)"
    );
    assertEqualF64(
        floatexprs56_f64X2Eno_fold_recip_recip(&instance, -6.5797153436288686e+44),
        -6.579715343628869e+44,
        "f64.no_fold_recip_recip(-6.5797153436288686e+44)"
    );
    assertEqualF64(
        floatexprs56_f64X2Eno_fold_recip_recip(&instance, -1.4424693186857643e+20),
        -1.4424693186857642e+20,
        "f64.no_fold_recip_recip(-1.4424693186857643e+20)"
    );
    assertEqualF64(
        floatexprs56_f64X2Eno_fold_recip_recip(&instance, 1.8499468920623135e+50),
        1.8499468920623133e+50,
        "f64.no_fold_recip_recip(1.8499468920623135e+50)"
    );
    assertEqualF64(
        floatexprs56_f64X2Eno_fold_recip_recip(&instance, 5.779584288006583e-207),
        5.779584288006582e-207,
        "f64.no_fold_recip_recip(5.779584288006583e-207)"
    );
    assertEqualF64(
        floatexprs56_f64X2Eno_fold_recip_recip(&instance, 5.150117869614164e+271),
        5.1501178696141634e+271,
        "f64.no_fold_recip_recip(5.150117869614164e+271)"
    );
    assertEqualF64(
        floatexprs56_f64X2Eno_fold_recip_recip(&instance, -0.0),
        -0.0,
        "f64.no_fold_recip_recip(-0.0)"
    );
    assertEqualF64(
        floatexprs56_f64X2Eno_fold_recip_recip(&instance, 0.0),
        0.0,
        "f64.no_fold_recip_recip(0.0)"
    );
    assertEqualF64(
        floatexprs56_f64X2Eno_fold_recip_recip(&instance, -INFINITY),
        -INFINITY,
        "f64.no_fold_recip_recip(-INFINITY)"
    );
    assertEqualF64(
        floatexprs56_f64X2Eno_fold_recip_recip(&instance, INFINITY),
        INFINITY,
        "f64.no_fold_recip_recip(INFINITY)"
    );
}
