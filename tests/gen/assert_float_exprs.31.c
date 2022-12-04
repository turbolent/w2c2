
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.31.h"

void test() {
    floatexprs31Instance instance;
    floatexprs31Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.31.wasm");
    assertEqualF32(
        floatexprs31_f32X2EnoX5FfoldX5FsubX5Fadd(&instance, -676.474365234375, 403.03680419921875),
        -676.4744262695312,
        "f32.no_fold_sub_add(-676.474365234375, 403.03680419921875)"
    );
    assertEqualF32(
        floatexprs31_f32X2EnoX5FfoldX5FsubX5Fadd(&instance, -6.305943118406008e-34, 3.67186006875961e-29),
        -6.319457630020618e-34,
        "f32.no_fold_sub_add(-6.305943118406008e-34, 3.67186006875961e-29)"
    );
    assertEqualF32(
        floatexprs31_f32X2EnoX5FfoldX5FsubX5Fadd(&instance, 83184800.0, 46216216576.0),
        83185664.0,
        "f32.no_fold_sub_add(83184800.0, 46216216576.0)"
    );
    assertEqualF32(
        floatexprs31_f32X2EnoX5FfoldX5FsubX5Fadd(&instance, 2.211956963080186e-12, -1.0437929631734733e-08),
        2.211564265053312e-12,
        "f32.no_fold_sub_add(2.211956963080186e-12, -1.0437929631734733e-08)"
    );
    assertEqualF32(
        floatexprs31_f32X2EnoX5FfoldX5FsubX5Fadd(&instance, 0.14944395422935486, -27393.650390625),
        0.150390625,
        "f32.no_fold_sub_add(0.14944395422935486, -27393.650390625)"
    );
    assertEqualF64(
        floatexprs31_f64X2EnoX5FfoldX5FsubX5Fadd(&instance, 9.036598261794624e+76, -9.58186427535552e+77),
        9.036598261794628e+76,
        "f64.no_fold_sub_add(9.036598261794624e+76, -9.58186427535552e+77)"
    );
    assertEqualF64(
        floatexprs31_f64X2EnoX5FfoldX5FsubX5Fadd(&instance, 4.4230403564658815e-201, 2.6713491049366576e-195),
        4.423040356647721e-201,
        "f64.no_fold_sub_add(4.4230403564658815e-201, 2.6713491049366576e-195)"
    );
    assertEqualF64(
        floatexprs31_f64X2EnoX5FfoldX5FsubX5Fadd(&instance, 4.095348452776429e+75, -4.0501900195765687e+90),
        4.0708156372493975e+75,
        "f64.no_fold_sub_add(4.095348452776429e+75, -4.0501900195765687e+90)"
    );
    assertEqualF64(
        floatexprs31_f64X2EnoX5FfoldX5FsubX5Fadd(&instance, 2.4008889207554433e-08, -0.00017253797929188484),
        2.400888920756506e-08,
        "f64.no_fold_sub_add(2.4008889207554433e-08, -0.00017253797929188484)"
    );
    assertEqualF64(
        floatexprs31_f64X2EnoX5FfoldX5FsubX5Fadd(&instance, 4.3367542918305866e-111, -3.9597706708227122e-109),
        4.336754291830597e-111,
        "f64.no_fold_sub_add(4.3367542918305866e-111, -3.9597706708227122e-109)"
    );
}
