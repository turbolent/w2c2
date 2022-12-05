
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_int_exprs.8.h"

void test() {
    intexprs8Instance instance;
    intexprs8Instantiate(&instance, resolveTestImports);
    printStart("int_exprs.8.wasm");
    assertEqualU32(
        intexprs8_i32X2EnoX5FfoldX5FmulX5FdivX5Fs(&instance, 2147483648u),
        0u,
        "i32.no_fold_mul_div_s(2147483648u)"
    );
    assertEqualU32(
        intexprs8_i32X2EnoX5FfoldX5FmulX5FdivX5Fu(&instance, 2147483648u),
        0u,
        "i32.no_fold_mul_div_u(2147483648u)"
    );
    assertEqualU64(
        intexprs8_i64X2EnoX5FfoldX5FmulX5FdivX5Fs(&instance, 9223372036854775808ull),
        0ull,
        "i64.no_fold_mul_div_s(9223372036854775808ull)"
    );
    assertEqualU64(
        intexprs8_i64X2EnoX5FfoldX5FmulX5FdivX5Fu(&instance, 9223372036854775808ull),
        0ull,
        "i64.no_fold_mul_div_u(9223372036854775808ull)"
    );
}
