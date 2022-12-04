
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_int_exprs.14.h"

void test() {
    intexprs14Instance instance;
    intexprs14Instantiate(&instance, resolveTestImports);
    printStart("int_exprs.14.wasm");
    assertEqualU32(
        intexprs14_i32X2EdivX5FsX5F7(&instance, 71u),
        10u,
        "i32.div_s_7(71u)"
    );
    assertEqualU32(
        intexprs14_i32X2EdivX5FsX5F7(&instance, 1879048192u),
        268435456u,
        "i32.div_s_7(1879048192u)"
    );
    assertEqualU32(
        intexprs14_i32X2EdivX5FuX5F7(&instance, 71u),
        10u,
        "i32.div_u_7(71u)"
    );
    assertEqualU32(
        intexprs14_i32X2EdivX5FuX5F7(&instance, 3758096384u),
        536870912u,
        "i32.div_u_7(3758096384u)"
    );
    assertEqualU64(
        intexprs14_i64X2EdivX5FsX5F7(&instance, 71ull),
        10ull,
        "i64.div_s_7(71ull)"
    );
    assertEqualU64(
        intexprs14_i64X2EdivX5FsX5F7(&instance, 8070450532247928832ull),
        1152921504606846976ull,
        "i64.div_s_7(8070450532247928832ull)"
    );
    assertEqualU64(
        intexprs14_i64X2EdivX5FuX5F7(&instance, 71ull),
        10ull,
        "i64.div_u_7(71ull)"
    );
    assertEqualU64(
        intexprs14_i64X2EdivX5FuX5F7(&instance, 16140901064495857664ull),
        2305843009213693952ull,
        "i64.div_u_7(16140901064495857664ull)"
    );
}
