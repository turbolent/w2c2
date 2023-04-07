
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_int_exprs.17.h"

void test() {
    intexprs17Instance instance;
    intexprs17Instantiate(&instance, resolveTestImports);
    printStart("int_exprs.17.wasm");
    assertEqualU32(
        intexprs17_i32X2Erem_s_7(&instance, 71u),
        1u,
        "i32.rem_s_7(71u)"
    );
    assertEqualU32(
        intexprs17_i32X2Erem_s_7(&instance, 1879048192u),
        0u,
        "i32.rem_s_7(1879048192u)"
    );
    assertEqualU32(
        intexprs17_i32X2Erem_u_7(&instance, 71u),
        1u,
        "i32.rem_u_7(71u)"
    );
    assertEqualU32(
        intexprs17_i32X2Erem_u_7(&instance, 3758096384u),
        0u,
        "i32.rem_u_7(3758096384u)"
    );
    assertEqualU64(
        intexprs17_i64X2Erem_s_7(&instance, 71ull),
        1ull,
        "i64.rem_s_7(71ull)"
    );
    assertEqualU64(
        intexprs17_i64X2Erem_s_7(&instance, 8070450532247928832ull),
        0ull,
        "i64.rem_s_7(8070450532247928832ull)"
    );
    assertEqualU64(
        intexprs17_i64X2Erem_u_7(&instance, 71ull),
        1ull,
        "i64.rem_u_7(71ull)"
    );
    assertEqualU64(
        intexprs17_i64X2Erem_u_7(&instance, 16140901064495857664ull),
        0ull,
        "i64.rem_u_7(16140901064495857664ull)"
    );
}
