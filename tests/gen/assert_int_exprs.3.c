
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_int_exprs.3.h"

void test() {
    intexprs3Instance instance;
    intexprs3Instantiate(&instance, resolveTestImports);
    printStart("int_exprs.3.wasm");
    assertEqualU32(
        intexprs3_i32X2EnoX5FfoldX5FshlX5FshrX5Fs(&instance, 2147483648u),
        0u,
        "i32.no_fold_shl_shr_s(2147483648u)"
    );
    assertEqualU32(
        intexprs3_i32X2EnoX5FfoldX5FshlX5FshrX5Fu(&instance, 2147483648u),
        0u,
        "i32.no_fold_shl_shr_u(2147483648u)"
    );
    assertEqualU64(
        intexprs3_i64X2EnoX5FfoldX5FshlX5FshrX5Fs(&instance, 9223372036854775808ull),
        0ull,
        "i64.no_fold_shl_shr_s(9223372036854775808ull)"
    );
    assertEqualU64(
        intexprs3_i64X2EnoX5FfoldX5FshlX5FshrX5Fu(&instance, 9223372036854775808ull),
        0ull,
        "i64.no_fold_shl_shr_u(9223372036854775808ull)"
    );
}
