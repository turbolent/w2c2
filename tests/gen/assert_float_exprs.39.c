
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.39.h"

void test() {
    m14_floatX5FexprsX2E39Instance instance;
    m14_floatX5FexprsX2E39Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.39.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E39Export19_noX5FdemoteX5FmixedX5Fmul(&instance, 2.5377744840344215e-61, 1.5802016161448726e+34)),
        329178166u,
        "no_demote_mixed_mul(2.5377744840344215e-61, 1.5802016161448726e+34)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E39Export19_noX5FdemoteX5FmixedX5Fmul(&instance, 2.1726692129428788e+42, 7.293721306977546e-33)),
        1349264105u,
        "no_demote_mixed_mul(2.1726692129428788e+42, 7.293721306977546e-33)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E39Export19_noX5FdemoteX5FmixedX5Fmul(&instance, 1.8566135475946957e+53, 1.1523598697264038e-17)),
        2077099629u,
        "no_demote_mixed_mul(1.8566135475946957e+53, 1.1523598697264038e-17)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E39Export19_noX5FdemoteX5FmixedX5Fmul(&instance, 5.434641042224456e+66, 2.3453285768874742e-37)),
        1904260016u,
        "no_demote_mixed_mul(5.434641042224456e+66, 2.3453285768874742e-37)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E39Export19_noX5FdemoteX5FmixedX5Fmul(&instance, 1.1834791522838056e-51, 310965329461248.0)),
        49968716u,
        "no_demote_mixed_mul(1.1834791522838056e-51, 310965329461248.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E39Export28_noX5FdemoteX5FmixedX5FmulX5Fcommuted(&instance, 1.5802016161448726e+34, 2.5377744840344215e-61)),
        329178166u,
        "no_demote_mixed_mul_commuted(1.5802016161448726e+34, 2.5377744840344215e-61)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E39Export28_noX5FdemoteX5FmixedX5FmulX5Fcommuted(&instance, 7.293721306977546e-33, 2.1726692129428788e+42)),
        1349264105u,
        "no_demote_mixed_mul_commuted(7.293721306977546e-33, 2.1726692129428788e+42)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E39Export28_noX5FdemoteX5FmixedX5FmulX5Fcommuted(&instance, 1.1523598697264038e-17, 1.8566135475946957e+53)),
        2077099629u,
        "no_demote_mixed_mul_commuted(1.1523598697264038e-17, 1.8566135475946957e+53)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E39Export28_noX5FdemoteX5FmixedX5FmulX5Fcommuted(&instance, 2.3453285768874742e-37, 5.434641042224456e+66)),
        1904260016u,
        "no_demote_mixed_mul_commuted(2.3453285768874742e-37, 5.434641042224456e+66)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E39Export28_noX5FdemoteX5FmixedX5FmulX5Fcommuted(&instance, 310965329461248.0, 1.1834791522838056e-51)),
        49968716u,
        "no_demote_mixed_mul_commuted(310965329461248.0, 1.1834791522838056e-51)"
    );
}
