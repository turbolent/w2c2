
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_int_exprs.5.h"

void test() {
    intexprs5Instance instance;
    intexprs5Instantiate(&instance, resolveTestImports);
    printStart("int_exprs.5.wasm");
    assertEqualU32(
        intexprs5_i32X2Eno_fold_div_s_mul(&instance, 1u),
        0u,
        "i32.no_fold_div_s_mul(1u)"
    );
    assertEqualU32(
        intexprs5_i32X2Eno_fold_div_u_mul(&instance, 1u),
        0u,
        "i32.no_fold_div_u_mul(1u)"
    );
    assertEqualU64(
        intexprs5_i64X2Eno_fold_div_s_mul(&instance, 1ull),
        0ull,
        "i64.no_fold_div_s_mul(1ull)"
    );
    assertEqualU64(
        intexprs5_i64X2Eno_fold_div_u_mul(&instance, 1ull),
        0ull,
        "i64.no_fold_div_u_mul(1ull)"
    );
}
