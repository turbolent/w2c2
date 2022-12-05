
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_int_exprs.16.h"

void test() {
    intexprs16Instance instance;
    intexprs16Instantiate(&instance, resolveTestImports);
    printStart("int_exprs.16.wasm");
    assertEqualU32(
        intexprs16_i32X2EremX5FsX5F5(&instance, 71u),
        1u,
        "i32.rem_s_5(71u)"
    );
    assertEqualU32(
        intexprs16_i32X2EremX5FsX5F5(&instance, 1342177280u),
        0u,
        "i32.rem_s_5(1342177280u)"
    );
    assertEqualU32(
        intexprs16_i32X2EremX5FuX5F5(&instance, 71u),
        1u,
        "i32.rem_u_5(71u)"
    );
    assertEqualU32(
        intexprs16_i32X2EremX5FuX5F5(&instance, 2684354560u),
        0u,
        "i32.rem_u_5(2684354560u)"
    );
    assertEqualU64(
        intexprs16_i64X2EremX5FsX5F5(&instance, 71ull),
        1ull,
        "i64.rem_s_5(71ull)"
    );
    assertEqualU64(
        intexprs16_i64X2EremX5FsX5F5(&instance, 5764607523034234880ull),
        0ull,
        "i64.rem_s_5(5764607523034234880ull)"
    );
    assertEqualU64(
        intexprs16_i64X2EremX5FuX5F5(&instance, 71ull),
        1ull,
        "i64.rem_u_5(71ull)"
    );
    assertEqualU64(
        intexprs16_i64X2EremX5FuX5F5(&instance, 11529215046068469760ull),
        0ull,
        "i64.rem_u_5(11529215046068469760ull)"
    );
}
