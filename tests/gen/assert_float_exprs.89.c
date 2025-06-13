
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.89.h"

void test() {
    floatexprs89Instance instance;
    floatexprs89Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.89.wasm");
    assertEqualU32(
        floatexprs89_f32X2Earithmetic_nan_bitpattern(&instance, 2139107856u, 2139107856u),
        2143289344u,
        "f32.arithmetic_nan_bitpattern(2139107856u, 2139107856u)"
    );
    assertEqualU32(
        floatexprs89_f32X2Ecanonical_nan_bitpattern(&instance, 0u, 0u),
        2143289344u,
        "f32.canonical_nan_bitpattern(0u, 0u)"
    );
    assertEqualU32(
        floatexprs89_f32X2Ecanonical_nan_bitpattern(&instance, 2143289344u, 2143289344u),
        2143289344u,
        "f32.canonical_nan_bitpattern(2143289344u, 2143289344u)"
    );
    assertEqualU32(
        floatexprs89_f32X2Ecanonical_nan_bitpattern(&instance, 4290772992u, 2143289344u),
        2143289344u,
        "f32.canonical_nan_bitpattern(4290772992u, 2143289344u)"
    );
    assertEqualU32(
        floatexprs89_f32X2Ecanonical_nan_bitpattern(&instance, 2143289344u, 4290772992u),
        2143289344u,
        "f32.canonical_nan_bitpattern(2143289344u, 4290772992u)"
    );
    assertEqualU32(
        floatexprs89_f32X2Ecanonical_nan_bitpattern(&instance, 4290772992u, 4290772992u),
        2143289344u,
        "f32.canonical_nan_bitpattern(4290772992u, 4290772992u)"
    );
    assertEqualU32(
        floatexprs89_f32X2Enonarithmetic_nan_bitpattern(&instance, 2143302160u),
        4290785808u,
        "f32.nonarithmetic_nan_bitpattern(2143302160u)"
    );
    assertEqualU32(
        floatexprs89_f32X2Enonarithmetic_nan_bitpattern(&instance, 4290785808u),
        2143302160u,
        "f32.nonarithmetic_nan_bitpattern(4290785808u)"
    );
    assertEqualU32(
        floatexprs89_f32X2Enonarithmetic_nan_bitpattern(&instance, 2139107856u),
        4286591504u,
        "f32.nonarithmetic_nan_bitpattern(2139107856u)"
    );
    assertEqualU32(
        floatexprs89_f32X2Enonarithmetic_nan_bitpattern(&instance, 4286591504u),
        2139107856u,
        "f32.nonarithmetic_nan_bitpattern(4286591504u)"
    );
    assertEqualU64(
        floatexprs89_f64X2Earithmetic_nan_bitpattern(&instance, 9218868437227418128ull, 9218868437227418128ull),
        9221120237041090560ull,
        "f64.arithmetic_nan_bitpattern(9218868437227418128ull, 9218868437227418128ull)"
    );
    assertEqualU64(
        floatexprs89_f64X2Ecanonical_nan_bitpattern(&instance, 0ull, 0ull),
        9221120237041090560ull,
        "f64.canonical_nan_bitpattern(0ull, 0ull)"
    );
    assertEqualU64(
        floatexprs89_f64X2Ecanonical_nan_bitpattern(&instance, 9221120237041090560ull, 9221120237041090560ull),
        9221120237041090560ull,
        "f64.canonical_nan_bitpattern(9221120237041090560ull, 9221120237041090560ull)"
    );
    assertEqualU64(
        floatexprs89_f64X2Ecanonical_nan_bitpattern(&instance, 18444492273895866368ull, 9221120237041090560ull),
        9221120237041090560ull,
        "f64.canonical_nan_bitpattern(18444492273895866368ull, 9221120237041090560ull)"
    );
    assertEqualU64(
        floatexprs89_f64X2Ecanonical_nan_bitpattern(&instance, 9221120237041090560ull, 18444492273895866368ull),
        9221120237041090560ull,
        "f64.canonical_nan_bitpattern(9221120237041090560ull, 18444492273895866368ull)"
    );
    assertEqualU64(
        floatexprs89_f64X2Ecanonical_nan_bitpattern(&instance, 18444492273895866368ull, 18444492273895866368ull),
        9221120237041090560ull,
        "f64.canonical_nan_bitpattern(18444492273895866368ull, 18444492273895866368ull)"
    );
    assertEqualU64(
        floatexprs89_f64X2Enonarithmetic_nan_bitpattern(&instance, 9221120237041103376ull),
        18444492273895879184ull,
        "f64.nonarithmetic_nan_bitpattern(9221120237041103376ull)"
    );
    assertEqualU64(
        floatexprs89_f64X2Enonarithmetic_nan_bitpattern(&instance, 18444492273895879184ull),
        9221120237041103376ull,
        "f64.nonarithmetic_nan_bitpattern(18444492273895879184ull)"
    );
    assertEqualU64(
        floatexprs89_f64X2Enonarithmetic_nan_bitpattern(&instance, 9218868437227418128ull),
        18442240474082193936ull,
        "f64.nonarithmetic_nan_bitpattern(9218868437227418128ull)"
    );
    assertEqualU64(
        floatexprs89_f64X2Enonarithmetic_nan_bitpattern(&instance, 18442240474082193936ull),
        9218868437227418128ull,
        "f64.nonarithmetic_nan_bitpattern(18442240474082193936ull)"
    );
    assertEqualU32(
        floatexprs89_f32X2Eno_fold_sub_zero(&instance, 2141192192u),
        2143289344u,
        "f32.no_fold_sub_zero(2141192192u)"
    );
    assertEqualU32(
        floatexprs89_f32X2Eno_fold_neg0_sub(&instance, 2141192192u),
        2143289344u,
        "f32.no_fold_neg0_sub(2141192192u)"
    );
    assertEqualU32(
        floatexprs89_f32X2Eno_fold_mul_one(&instance, 2141192192u),
        2143289344u,
        "f32.no_fold_mul_one(2141192192u)"
    );
    assertEqualU32(
        floatexprs89_f32X2Eno_fold_neg1_mul(&instance, 2141192192u),
        2143289344u,
        "f32.no_fold_neg1_mul(2141192192u)"
    );
    assertEqualU32(
        floatexprs89_f32X2Eno_fold_div_one(&instance, 2141192192u),
        2143289344u,
        "f32.no_fold_div_one(2141192192u)"
    );
    assertEqualU32(
        floatexprs89_f32X2Eno_fold_div_neg1(&instance, 2141192192u),
        2143289344u,
        "f32.no_fold_div_neg1(2141192192u)"
    );
    assertEqualU64(
        floatexprs89_f64X2Eno_fold_sub_zero(&instance, 9219994337134247936ull),
        9221120237041090560ull,
        "f64.no_fold_sub_zero(9219994337134247936ull)"
    );
    assertEqualU64(
        floatexprs89_f64X2Eno_fold_neg0_sub(&instance, 9219994337134247936ull),
        9221120237041090560ull,
        "f64.no_fold_neg0_sub(9219994337134247936ull)"
    );
    assertEqualU64(
        floatexprs89_f64X2Eno_fold_mul_one(&instance, 9219994337134247936ull),
        9221120237041090560ull,
        "f64.no_fold_mul_one(9219994337134247936ull)"
    );
    assertEqualU64(
        floatexprs89_f64X2Eno_fold_neg1_mul(&instance, 9219994337134247936ull),
        9221120237041090560ull,
        "f64.no_fold_neg1_mul(9219994337134247936ull)"
    );
    assertEqualU64(
        floatexprs89_f64X2Eno_fold_div_one(&instance, 9219994337134247936ull),
        9221120237041090560ull,
        "f64.no_fold_div_one(9219994337134247936ull)"
    );
    assertEqualU64(
        floatexprs89_f64X2Eno_fold_div_neg1(&instance, 9219994337134247936ull),
        9221120237041090560ull,
        "f64.no_fold_div_neg1(9219994337134247936ull)"
    );
    assertEqualU32(
        floatexprs89_no_fold_promote_demote(&instance, 2141192192u),
        2143289344u,
        "no_fold_promote_demote(2141192192u)"
    );
}
