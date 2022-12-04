
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.29.h"

void test() {
    floatexprs29Instance instance;
    floatexprs29Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.29.wasm");
    assertEqualU32(
        floatexprs29_i32X2EnoX5FfoldX5Ff32X5Fs(&instance, 16777216u),
        16777216u,
        "i32.no_fold_f32_s(16777216u)"
    );
    assertEqualU32(
        floatexprs29_i32X2EnoX5FfoldX5Ff32X5Fs(&instance, 16777217u),
        16777216u,
        "i32.no_fold_f32_s(16777217u)"
    );
    assertEqualU32(
        floatexprs29_i32X2EnoX5FfoldX5Ff32X5Fs(&instance, 4026531856u),
        4026531856u,
        "i32.no_fold_f32_s(4026531856u)"
    );
    assertEqualU32(
        floatexprs29_i32X2EnoX5FfoldX5Ff32X5Fu(&instance, 16777216u),
        16777216u,
        "i32.no_fold_f32_u(16777216u)"
    );
    assertEqualU32(
        floatexprs29_i32X2EnoX5FfoldX5Ff32X5Fu(&instance, 16777217u),
        16777216u,
        "i32.no_fold_f32_u(16777217u)"
    );
    assertEqualU32(
        floatexprs29_i32X2EnoX5FfoldX5Ff32X5Fu(&instance, 4026531856u),
        4026531840u,
        "i32.no_fold_f32_u(4026531856u)"
    );
    assertEqualU64(
        floatexprs29_i64X2EnoX5FfoldX5Ff64X5Fs(&instance, 9007199254740992ull),
        9007199254740992ull,
        "i64.no_fold_f64_s(9007199254740992ull)"
    );
    assertEqualU64(
        floatexprs29_i64X2EnoX5FfoldX5Ff64X5Fs(&instance, 9007199254740993ull),
        9007199254740992ull,
        "i64.no_fold_f64_s(9007199254740993ull)"
    );
    assertEqualU64(
        floatexprs29_i64X2EnoX5FfoldX5Ff64X5Fs(&instance, 17293822569102705664ull),
        17293822569102705664ull,
        "i64.no_fold_f64_s(17293822569102705664ull)"
    );
    assertEqualU64(
        floatexprs29_i64X2EnoX5FfoldX5Ff64X5Fu(&instance, 9007199254740992ull),
        9007199254740992ull,
        "i64.no_fold_f64_u(9007199254740992ull)"
    );
    assertEqualU64(
        floatexprs29_i64X2EnoX5FfoldX5Ff64X5Fu(&instance, 9007199254740993ull),
        9007199254740992ull,
        "i64.no_fold_f64_u(9007199254740993ull)"
    );
    assertEqualU64(
        floatexprs29_i64X2EnoX5FfoldX5Ff64X5Fu(&instance, 17293822569102705664ull),
        17293822569102704640ull,
        "i64.no_fold_f64_u(17293822569102705664ull)"
    );
}
