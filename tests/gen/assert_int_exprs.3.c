
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_int_exprs.3.h"

void test() {
    m11_intX5FexprsX2E3Instance instance;
    m11_intX5FexprsX2E3Instantiate(&instance, resolveTestImports);
    printStart("int_exprs.3.wasm");
    assertEqualU32(
        m11_intX5FexprsX2E3Export21_i32X2EnoX5FfoldX5FshlX5FshrX5Fs(&instance, 2147483648u),
        0u,
        "i32.no_fold_shl_shr_s(2147483648u)"
    );
    assertEqualU32(
        m11_intX5FexprsX2E3Export21_i32X2EnoX5FfoldX5FshlX5FshrX5Fu(&instance, 2147483648u),
        0u,
        "i32.no_fold_shl_shr_u(2147483648u)"
    );
    assertEqualU64(
        m11_intX5FexprsX2E3Export21_i64X2EnoX5FfoldX5FshlX5FshrX5Fs(&instance, 9223372036854775808ull),
        0ull,
        "i64.no_fold_shl_shr_s(9223372036854775808ull)"
    );
    assertEqualU64(
        m11_intX5FexprsX2E3Export21_i64X2EnoX5FfoldX5FshlX5FshrX5Fu(&instance, 9223372036854775808ull),
        0ull,
        "i64.no_fold_shl_shr_u(9223372036854775808ull)"
    );
}
