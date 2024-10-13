
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.39.h"

void test() {
    floatexprs39Instance instance;
    floatexprs39Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.39.wasm");
    assertEqualF32(
        floatexprs39_no_demote_mixed_mul(&instance, 2.5377744840344215e-61, 1.5802016161448726e+34),
        4.010195211734413e-27,
        "no_demote_mixed_mul(2.5377744840344215e-61, 1.5802016161448726e+34)"
    );
    assertEqualF32(
        floatexprs39_no_demote_mixed_mul(&instance, 2.1726692129428788e+42, 7.293721306977546e-33),
        15846843392.0,
        "no_demote_mixed_mul(2.1726692129428788e+42, 7.293721306977546e-33)"
    );
    assertEqualF32(
        floatexprs39_no_demote_mixed_mul(&instance, 1.8566135475946957e+53, 1.1523598697264038e-17),
        2.139486966371021e+36,
        "no_demote_mixed_mul(1.8566135475946957e+53, 1.1523598697264038e-17)"
    );
    assertEqualF32(
        floatexprs39_no_demote_mixed_mul(&instance, 5.434641042224456e+66, 2.3453285768874742e-37),
        1.2746019236910135e+30,
        "no_demote_mixed_mul(5.434641042224456e+66, 2.3453285768874742e-37)"
    );
    assertEqualF32(
        floatexprs39_no_demote_mixed_mul(&instance, 1.1834791522838056e-51, 310965329461248.0),
        3.6802097539506265e-37,
        "no_demote_mixed_mul(1.1834791522838056e-51, 310965329461248.0)"
    );
    assertEqualF32(
        floatexprs39_no_demote_mixed_mul_commuted(&instance, 1.5802016161448726e+34, 2.5377744840344215e-61),
        4.010195211734413e-27,
        "no_demote_mixed_mul_commuted(1.5802016161448726e+34, 2.5377744840344215e-61)"
    );
    assertEqualF32(
        floatexprs39_no_demote_mixed_mul_commuted(&instance, 7.293721306977546e-33, 2.1726692129428788e+42),
        15846843392.0,
        "no_demote_mixed_mul_commuted(7.293721306977546e-33, 2.1726692129428788e+42)"
    );
    assertEqualF32(
        floatexprs39_no_demote_mixed_mul_commuted(&instance, 1.1523598697264038e-17, 1.8566135475946957e+53),
        2.139486966371021e+36,
        "no_demote_mixed_mul_commuted(1.1523598697264038e-17, 1.8566135475946957e+53)"
    );
    assertEqualF32(
        floatexprs39_no_demote_mixed_mul_commuted(&instance, 2.3453285768874742e-37, 5.434641042224456e+66),
        1.2746019236910135e+30,
        "no_demote_mixed_mul_commuted(2.3453285768874742e-37, 5.434641042224456e+66)"
    );
    assertEqualF32(
        floatexprs39_no_demote_mixed_mul_commuted(&instance, 310965329461248.0, 1.1834791522838056e-51),
        3.6802097539506265e-37,
        "no_demote_mixed_mul_commuted(310965329461248.0, 1.1834791522838056e-51)"
    );
}
