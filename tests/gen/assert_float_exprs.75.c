
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.75.h"

void test() {
    floatexprs75Instance instance;
    floatexprs75Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.75.wasm");
    assertEqualF32(
        floatexprs75_f32X2Eno_fold_div_sqrts(&instance, 7407384064.0, 209778928.0),
        5.942258358001709,
        "f32.no_fold_div_sqrts(7407384064.0, 209778928.0)"
    );
    assertEqualF32(
        floatexprs75_f32X2Eno_fold_div_sqrts(&instance, 1.3764125694787306e-36, 54692.8984375),
        5.016592728986257e-21,
        "f32.no_fold_div_sqrts(1.3764125694787306e-36, 54692.8984375)"
    );
    assertEqualF32(
        floatexprs75_f32X2Eno_fold_div_sqrts(&instance, 9.792889648106701e+17, 1.2643551761115646e-09),
        27830490497024.0,
        "f32.no_fold_div_sqrts(9.792889648106701e+17, 1.2643551761115646e-09)"
    );
    assertEqualF32(
        floatexprs75_f32X2Eno_fold_div_sqrts(&instance, 2.9141283262714446e-34, 1.7928174342978603e-31),
        0.04031682014465332,
        "f32.no_fold_div_sqrts(2.9141283262714446e-34, 1.7928174342978603e-31)"
    );
    assertEqualF64(
        floatexprs75_f64X2Eno_fold_div_sqrts(&instance, 3.3818852462305824e-177, 7.655783976315048e+162),
        2.1017671425665687e-170,
        "f64.no_fold_div_sqrts(3.3818852462305824e-177, 7.655783976315048e+162)"
    );
    assertEqualF64(
        floatexprs75_f64X2Eno_fold_div_sqrts(&instance, 4.596333567064751e+157, 2.3932467846883046e-33),
        1.3858366017266315e+95,
        "f64.no_fold_div_sqrts(4.596333567064751e+157, 2.3932467846883046e-33)"
    );
    assertEqualF64(
        floatexprs75_f64X2Eno_fold_div_sqrts(&instance, 2.5327340978668086e-244, 4.475305129961258e+87),
        2.3789399141325018e-166,
        "f64.no_fold_div_sqrts(2.5327340978668086e-244, 4.475305129961258e+87)"
    );
    assertEqualF64(
        floatexprs75_f64X2Eno_fold_div_sqrts(&instance, 5.103070160197939e-238, 4.601576690980825e+284),
        1.0530826009924495e-261,
        "f64.no_fold_div_sqrts(5.103070160197939e-238, 4.601576690980825e+284)"
    );
}
