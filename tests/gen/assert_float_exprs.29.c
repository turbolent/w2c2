
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.29.h"

void test() {
    floatexprs29Instance instance;
    floatexprs29Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.29.wasm");
    assertEqualU32(
        floatexprs29_i32X2Eno_fold_f32_s(&instance, 16777216u),
        16777216u,
        "i32.no_fold_f32_s(16777216u)"
    );
    assertEqualU32(
        floatexprs29_i32X2Eno_fold_f32_s(&instance, 16777217u),
        16777216u,
        "i32.no_fold_f32_s(16777217u)"
    );
    assertEqualU32(
        floatexprs29_i32X2Eno_fold_f32_s(&instance, 4026531856u),
        4026531856u,
        "i32.no_fold_f32_s(4026531856u)"
    );
    assertEqualU32(
        floatexprs29_i32X2Eno_fold_f32_u(&instance, 16777216u),
        16777216u,
        "i32.no_fold_f32_u(16777216u)"
    );
    assertEqualU32(
        floatexprs29_i32X2Eno_fold_f32_u(&instance, 16777217u),
        16777216u,
        "i32.no_fold_f32_u(16777217u)"
    );
    assertEqualU32(
        floatexprs29_i32X2Eno_fold_f32_u(&instance, 4026531856u),
        4026531840u,
        "i32.no_fold_f32_u(4026531856u)"
    );
    assertEqualU64(
        floatexprs29_i64X2Eno_fold_f64_s(&instance, 9007199254740992ull),
        9007199254740992ull,
        "i64.no_fold_f64_s(9007199254740992ull)"
    );
    assertEqualU64(
        floatexprs29_i64X2Eno_fold_f64_s(&instance, 9007199254740993ull),
        9007199254740992ull,
        "i64.no_fold_f64_s(9007199254740993ull)"
    );
    assertEqualU64(
        floatexprs29_i64X2Eno_fold_f64_s(&instance, 17293822569102705664ull),
        17293822569102705664ull,
        "i64.no_fold_f64_s(17293822569102705664ull)"
    );
    assertEqualU64(
        floatexprs29_i64X2Eno_fold_f64_u(&instance, 9007199254740992ull),
        9007199254740992ull,
        "i64.no_fold_f64_u(9007199254740992ull)"
    );
    assertEqualU64(
        floatexprs29_i64X2Eno_fold_f64_u(&instance, 9007199254740993ull),
        9007199254740992ull,
        "i64.no_fold_f64_u(9007199254740993ull)"
    );
    assertEqualU64(
        floatexprs29_i64X2Eno_fold_f64_u(&instance, 17293822569102705664ull),
        17293822569102704640ull,
        "i64.no_fold_f64_u(17293822569102705664ull)"
    );
}
