
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_int_exprs.8.h"

void test() {
    intexprs8Instance instance;
    intexprs8Instantiate(&instance, resolveTestImports);
    printStart("int_exprs.8.wasm");
    assertEqualU32(
        intexprs8_i32X2Eno_fold_mul_div_s(&instance, 2147483648u),
        0u,
        "i32.no_fold_mul_div_s(2147483648u)"
    );
    assertEqualU32(
        intexprs8_i32X2Eno_fold_mul_div_u(&instance, 2147483648u),
        0u,
        "i32.no_fold_mul_div_u(2147483648u)"
    );
    assertEqualU64(
        intexprs8_i64X2Eno_fold_mul_div_s(&instance, 9223372036854775808ull),
        0ull,
        "i64.no_fold_mul_div_s(9223372036854775808ull)"
    );
    assertEqualU64(
        intexprs8_i64X2Eno_fold_mul_div_u(&instance, 9223372036854775808ull),
        0ull,
        "i64.no_fold_mul_div_u(9223372036854775808ull)"
    );
}
