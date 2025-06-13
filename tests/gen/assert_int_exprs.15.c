
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_int_exprs.15.h"

void test() {
    intexprs15Instance instance;
    intexprs15Instantiate(&instance, resolveTestImports);
    printStart("int_exprs.15.wasm");
    assertEqualU32(
        intexprs15_i32X2Erem_s_3(&instance, 71u),
        2u,
        "i32.rem_s_3(71u)"
    );
    assertEqualU32(
        intexprs15_i32X2Erem_s_3(&instance, 1610612736u),
        0u,
        "i32.rem_s_3(1610612736u)"
    );
    assertEqualU32(
        intexprs15_i32X2Erem_u_3(&instance, 71u),
        2u,
        "i32.rem_u_3(71u)"
    );
    assertEqualU32(
        intexprs15_i32X2Erem_u_3(&instance, 3221225472u),
        0u,
        "i32.rem_u_3(3221225472u)"
    );
    assertEqualU64(
        intexprs15_i64X2Erem_s_3(&instance, 71ull),
        2ull,
        "i64.rem_s_3(71ull)"
    );
    assertEqualU64(
        intexprs15_i64X2Erem_s_3(&instance, 3458764513820540928ull),
        0ull,
        "i64.rem_s_3(3458764513820540928ull)"
    );
    assertEqualU64(
        intexprs15_i64X2Erem_u_3(&instance, 71ull),
        2ull,
        "i64.rem_u_3(71ull)"
    );
    assertEqualU64(
        intexprs15_i64X2Erem_u_3(&instance, 13835058055282163712ull),
        0ull,
        "i64.rem_u_3(13835058055282163712ull)"
    );
}
