
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_int_exprs.4.h"

void test() {
    intexprs4Instance instance;
    intexprs4Instantiate(&instance, resolveTestImports);
    printStart("int_exprs.4.wasm");
    assertEqualU32(
        intexprs4_i32X2EnoX5FfoldX5FshrX5FsX5Fshl(&instance, 1u),
        0u,
        "i32.no_fold_shr_s_shl(1u)"
    );
    assertEqualU32(
        intexprs4_i32X2EnoX5FfoldX5FshrX5FuX5Fshl(&instance, 1u),
        0u,
        "i32.no_fold_shr_u_shl(1u)"
    );
    assertEqualU64(
        intexprs4_i64X2EnoX5FfoldX5FshrX5FsX5Fshl(&instance, 1ull),
        0ull,
        "i64.no_fold_shr_s_shl(1ull)"
    );
    assertEqualU64(
        intexprs4_i64X2EnoX5FfoldX5FshrX5FuX5Fshl(&instance, 1ull),
        0ull,
        "i64.no_fold_shr_u_shl(1ull)"
    );
}
