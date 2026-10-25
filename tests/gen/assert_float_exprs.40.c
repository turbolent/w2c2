
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.40.h"

void test() {
    m14_floatX5FexprsX2E40Instance instance;
    m14_floatX5FexprsX2E40Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.40.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E40Export19_noX5FdemoteX5FmixedX5Fdiv(&instance, 1.7886048835324162e+45, 1.4437566377602219e+31)),
        1457608876u,
        "no_demote_mixed_div(1.7886048835324162e+45, 1.4437566377602219e+31)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E40Export19_noX5FdemoteX5FmixedX5Fdiv(&instance, 1.0952898401798359e-46, 2.5665392336139314e-25)),
        469826243u,
        "no_demote_mixed_div(1.0952898401798359e-46, 2.5665392336139314e-25)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E40Export19_noX5FdemoteX5FmixedX5Fdiv(&instance, 9.080603501514862e-12, 4.8373775871448426e-39)),
        1824659560u,
        "no_demote_mixed_div(9.080603501514862e-12, 4.8373775871448426e-39)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E40Export19_noX5FdemoteX5FmixedX5Fdiv(&instance, 3.782857642810886e-42, 3.438024151230309e-27)),
        647926247u,
        "no_demote_mixed_div(3.782857642810886e-42, 3.438024151230309e-27)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E40Export19_noX5FdemoteX5FmixedX5Fdiv(&instance, 3.4505644707116606e+22, 6.0033419644222506e+26)),
        946934754u,
        "no_demote_mixed_div(3.4505644707116606e+22, 6.0033419644222506e+26)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E40Export28_noX5FdemoteX5FmixedX5FdivX5Fcommuted(&instance, 9.751511021865503e-23, 2.6675841907359984e-13)),
        801699691u,
        "no_demote_mixed_div_commuted(9.751511021865503e-23, 2.6675841907359984e-13)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E40Export28_noX5FdemoteX5FmixedX5FdivX5Fcommuted(&instance, 100059280.0, 8.111351951123959e+47)),
        88031u,
        "no_demote_mixed_div_commuted(100059280.0, 8.111351951123959e+47)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E40Export28_noX5FdemoteX5FmixedX5FdivX5Fcommuted(&instance, 1.7325049814914673e-12, 1.1227001577189032e-41)),
        1878609809u,
        "no_demote_mixed_div_commuted(1.7325049814914673e-12, 1.1227001577189032e-41)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E40Export28_noX5FdemoteX5FmixedX5FdivX5Fcommuted(&instance, 1.752210102701486e+24, 2.5200730547930863e+63)),
        496184u,
        "no_demote_mixed_div_commuted(1.752210102701486e+24, 2.5200730547930863e+63)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E40Export28_noX5FdemoteX5FmixedX5FdivX5Fcommuted(&instance, 1.5513188252708936e-22, 3.5774408529541256e-60)),
        2114092635u,
        "no_demote_mixed_div_commuted(1.5513188252708936e-22, 3.5774408529541256e-60)"
    );
}
