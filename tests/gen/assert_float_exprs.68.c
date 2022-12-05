
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.68.h"

void test() {
    floatexprs68Instance instance;
    floatexprs68Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.68.wasm");
    assertEqualF32(
        floatexprs68_f32X2EnoX5FfoldX5FdivX5Fdiv(&instance, -5.938475291688351e+23, -3.0265671739471145e-05, -1584.8681640625),
        -1.2380308618298272e+25,
        "f32.no_fold_div_div(-5.938475291688351e+23, -3.0265671739471145e-05, -1584.8681640625)"
    );
    assertEqualF32(
        floatexprs68_f32X2EnoX5FfoldX5FdivX5Fdiv(&instance, 1.5438961616455177e-21, 2.5334292803745544e+33, -2.684478285682781e-34),
        -0.0,
        "f32.no_fold_div_div(1.5438961616455177e-21, 2.5334292803745544e+33, -2.684478285682781e-34)"
    );
    assertEqualF32(
        floatexprs68_f32X2EnoX5FfoldX5FdivX5Fdiv(&instance, 13417423306752.0, 2.933920464447575e-32, 7.638637444001918e+31),
        INFINITY,
        "f32.no_fold_div_div(13417423306752.0, 2.933920464447575e-32, 7.638637444001918e+31)"
    );
    assertEqualF32(
        floatexprs68_f32X2EnoX5FfoldX5FdivX5Fdiv(&instance, -0.00010776529234135523, -3.422094290809958e+37, -1.656232388649176e-13),
        -1.9011326935735888e-29,
        "f32.no_fold_div_div(-0.00010776529234135523, -3.422094290809958e+37, -1.656232388649176e-13)"
    );
    assertEqualF32(
        floatexprs68_f32X2EnoX5FfoldX5FdivX5Fdiv(&instance, 130582499557376.0, 9.624534661044634e+16, -4.146154510069999e+37),
        -3.272312173891313e-41,
        "f32.no_fold_div_div(130582499557376.0, 9.624534661044634e+16, -4.146154510069999e+37)"
    );
    assertEqualF64(
        floatexprs68_f64X2EnoX5FfoldX5FdivX5Fdiv(&instance, 4.7776287467101434e+101, 1.0278672042040401e+176, -7.18999894988884e-236),
        -6.464673011878799e+160,
        "f64.no_fold_div_div(4.7776287467101434e+101, 1.0278672042040401e+176, -7.18999894988884e-236)"
    );
    assertEqualF64(
        floatexprs68_f64X2EnoX5FfoldX5FdivX5Fdiv(&instance, -2.1790236783875714e+238, 2.8324436844616576e-09, 1.861107682598687e+95),
        -4.133606807992067e+151,
        "f64.no_fold_div_div(-2.1790236783875714e+238, 2.8324436844616576e-09, 1.861107682598687e+95)"
    );
    assertEqualF64(
        floatexprs68_f64X2EnoX5FfoldX5FdivX5Fdiv(&instance, -7.287619347826683, -1.3467607316739855e+265, 2.462719007013688e+51),
        2.19725454e-316,
        "f64.no_fold_div_div(-7.287619347826683, -1.3467607316739855e+265, 2.462719007013688e+51)"
    );
    assertEqualF64(
        floatexprs68_f64X2EnoX5FfoldX5FdivX5Fdiv(&instance, -2.865523978629633e+248, 1.0211980370639414e-247, 2.876458648332401e+289),
        -INFINITY,
        "f64.no_fold_div_div(-2.865523978629633e+248, 1.0211980370639414e-247, 2.876458648332401e+289)"
    );
    assertEqualF64(
        floatexprs68_f64X2EnoX5FfoldX5FdivX5Fdiv(&instance, -9.525735602663874e-268, 5.0233948816631796e-180, -2.8304570228221077e-42),
        6.699534674970116e-47,
        "f64.no_fold_div_div(-9.525735602663874e-268, 5.0233948816631796e-180, -2.8304570228221077e-42)"
    );
}
