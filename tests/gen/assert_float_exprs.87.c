
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.87.h"

void test() {
    floatexprs87Instance instance;
    floatexprs87Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.87.wasm");
    assertEqualU32(
        floatexprs87_f32X2EarithmeticX5FnanX5Fbitpattern(&instance, 2139107856u, 2139107856u),
        2143289344u,
        "f32.arithmetic_nan_bitpattern(2139107856u, 2139107856u)"
    );
    assertEqualU32(
        floatexprs87_f32X2EcanonicalX5FnanX5Fbitpattern(&instance, 0u, 0u),
        2143289344u,
        "f32.canonical_nan_bitpattern(0u, 0u)"
    );
    assertEqualU32(
        floatexprs87_f32X2EcanonicalX5FnanX5Fbitpattern(&instance, 2143289344u, 2143289344u),
        2143289344u,
        "f32.canonical_nan_bitpattern(2143289344u, 2143289344u)"
    );
    assertEqualU32(
        floatexprs87_f32X2EcanonicalX5FnanX5Fbitpattern(&instance, 4290772992u, 2143289344u),
        2143289344u,
        "f32.canonical_nan_bitpattern(4290772992u, 2143289344u)"
    );
    assertEqualU32(
        floatexprs87_f32X2EcanonicalX5FnanX5Fbitpattern(&instance, 2143289344u, 4290772992u),
        2143289344u,
        "f32.canonical_nan_bitpattern(2143289344u, 4290772992u)"
    );
    assertEqualU32(
        floatexprs87_f32X2EcanonicalX5FnanX5Fbitpattern(&instance, 4290772992u, 4290772992u),
        2143289344u,
        "f32.canonical_nan_bitpattern(4290772992u, 4290772992u)"
    );
    assertEqualU32(
        floatexprs87_f32X2EnonarithmeticX5FnanX5Fbitpattern(&instance, 2143302160u),
        4290785808u,
        "f32.nonarithmetic_nan_bitpattern(2143302160u)"
    );
    assertEqualU32(
        floatexprs87_f32X2EnonarithmeticX5FnanX5Fbitpattern(&instance, 4290785808u),
        2143302160u,
        "f32.nonarithmetic_nan_bitpattern(4290785808u)"
    );
    assertEqualU32(
        floatexprs87_f32X2EnonarithmeticX5FnanX5Fbitpattern(&instance, 2139107856u),
        4286591504u,
        "f32.nonarithmetic_nan_bitpattern(2139107856u)"
    );
    assertEqualU32(
        floatexprs87_f32X2EnonarithmeticX5FnanX5Fbitpattern(&instance, 4286591504u),
        2139107856u,
        "f32.nonarithmetic_nan_bitpattern(4286591504u)"
    );
    assertEqualU64(
        floatexprs87_f64X2EarithmeticX5FnanX5Fbitpattern(&instance, 9218868437227418128ull, 9218868437227418128ull),
        9221120237041090560ull,
        "f64.arithmetic_nan_bitpattern(9218868437227418128ull, 9218868437227418128ull)"
    );
    assertEqualU64(
        floatexprs87_f64X2EcanonicalX5FnanX5Fbitpattern(&instance, 0ull, 0ull),
        9221120237041090560ull,
        "f64.canonical_nan_bitpattern(0ull, 0ull)"
    );
    assertEqualU64(
        floatexprs87_f64X2EcanonicalX5FnanX5Fbitpattern(&instance, 9221120237041090560ull, 9221120237041090560ull),
        9221120237041090560ull,
        "f64.canonical_nan_bitpattern(9221120237041090560ull, 9221120237041090560ull)"
    );
    assertEqualU64(
        floatexprs87_f64X2EcanonicalX5FnanX5Fbitpattern(&instance, 18444492273895866368ull, 9221120237041090560ull),
        9221120237041090560ull,
        "f64.canonical_nan_bitpattern(18444492273895866368ull, 9221120237041090560ull)"
    );
    assertEqualU64(
        floatexprs87_f64X2EcanonicalX5FnanX5Fbitpattern(&instance, 9221120237041090560ull, 18444492273895866368ull),
        9221120237041090560ull,
        "f64.canonical_nan_bitpattern(9221120237041090560ull, 18444492273895866368ull)"
    );
    assertEqualU64(
        floatexprs87_f64X2EcanonicalX5FnanX5Fbitpattern(&instance, 18444492273895866368ull, 18444492273895866368ull),
        9221120237041090560ull,
        "f64.canonical_nan_bitpattern(18444492273895866368ull, 18444492273895866368ull)"
    );
    assertEqualU64(
        floatexprs87_f64X2EnonarithmeticX5FnanX5Fbitpattern(&instance, 9221120237041103376ull),
        18444492273895879184ull,
        "f64.nonarithmetic_nan_bitpattern(9221120237041103376ull)"
    );
    assertEqualU64(
        floatexprs87_f64X2EnonarithmeticX5FnanX5Fbitpattern(&instance, 18444492273895879184ull),
        9221120237041103376ull,
        "f64.nonarithmetic_nan_bitpattern(18444492273895879184ull)"
    );
    assertEqualU64(
        floatexprs87_f64X2EnonarithmeticX5FnanX5Fbitpattern(&instance, 9218868437227418128ull),
        18442240474082193936ull,
        "f64.nonarithmetic_nan_bitpattern(9218868437227418128ull)"
    );
    assertEqualU64(
        floatexprs87_f64X2EnonarithmeticX5FnanX5Fbitpattern(&instance, 18442240474082193936ull),
        9218868437227418128ull,
        "f64.nonarithmetic_nan_bitpattern(18442240474082193936ull)"
    );
    assertEqualU32(
        floatexprs87_f32X2EnoX5FfoldX5FsubX5Fzero(&instance, 2141192192u),
        2143289344u,
        "f32.no_fold_sub_zero(2141192192u)"
    );
    assertEqualU32(
        floatexprs87_f32X2EnoX5FfoldX5Fneg0X5Fsub(&instance, 2141192192u),
        2143289344u,
        "f32.no_fold_neg0_sub(2141192192u)"
    );
    assertEqualU32(
        floatexprs87_f32X2EnoX5FfoldX5FmulX5Fone(&instance, 2141192192u),
        2143289344u,
        "f32.no_fold_mul_one(2141192192u)"
    );
    assertEqualU32(
        floatexprs87_f32X2EnoX5FfoldX5Fneg1X5Fmul(&instance, 2141192192u),
        2143289344u,
        "f32.no_fold_neg1_mul(2141192192u)"
    );
    assertEqualU32(
        floatexprs87_f32X2EnoX5FfoldX5FdivX5Fone(&instance, 2141192192u),
        2143289344u,
        "f32.no_fold_div_one(2141192192u)"
    );
    assertEqualU32(
        floatexprs87_f32X2EnoX5FfoldX5FdivX5Fneg1(&instance, 2141192192u),
        2143289344u,
        "f32.no_fold_div_neg1(2141192192u)"
    );
    assertEqualU64(
        floatexprs87_f64X2EnoX5FfoldX5FsubX5Fzero(&instance, 9219994337134247936ull),
        9221120237041090560ull,
        "f64.no_fold_sub_zero(9219994337134247936ull)"
    );
    assertEqualU64(
        floatexprs87_f64X2EnoX5FfoldX5Fneg0X5Fsub(&instance, 9219994337134247936ull),
        9221120237041090560ull,
        "f64.no_fold_neg0_sub(9219994337134247936ull)"
    );
    assertEqualU64(
        floatexprs87_f64X2EnoX5FfoldX5FmulX5Fone(&instance, 9219994337134247936ull),
        9221120237041090560ull,
        "f64.no_fold_mul_one(9219994337134247936ull)"
    );
    assertEqualU64(
        floatexprs87_f64X2EnoX5FfoldX5Fneg1X5Fmul(&instance, 9219994337134247936ull),
        9221120237041090560ull,
        "f64.no_fold_neg1_mul(9219994337134247936ull)"
    );
    assertEqualU64(
        floatexprs87_f64X2EnoX5FfoldX5FdivX5Fone(&instance, 9219994337134247936ull),
        9221120237041090560ull,
        "f64.no_fold_div_one(9219994337134247936ull)"
    );
    assertEqualU64(
        floatexprs87_f64X2EnoX5FfoldX5FdivX5Fneg1(&instance, 9219994337134247936ull),
        9221120237041090560ull,
        "f64.no_fold_div_neg1(9219994337134247936ull)"
    );
    assertEqualU32(
        floatexprs87_noX5FfoldX5FpromoteX5Fdemote(&instance, 2141192192u),
        2143289344u,
        "no_fold_promote_demote(2141192192u)"
    );
}
