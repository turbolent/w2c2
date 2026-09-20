
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_int_exprs.5.h"

void test() {
    m11_intX5FexprsX2E5Instance instance;
    m11_intX5FexprsX2E5Instantiate(&instance, resolveTestImports);
    printStart("int_exprs.5.wasm");
    assertEqualU32(
        m11_intX5FexprsX2E5Export21_i32X2EnoX5FfoldX5FdivX5FsX5Fmul(&instance, 1u),
        0u,
        "i32.no_fold_div_s_mul(1u)"
    );
    assertEqualU32(
        m11_intX5FexprsX2E5Export21_i32X2EnoX5FfoldX5FdivX5FuX5Fmul(&instance, 1u),
        0u,
        "i32.no_fold_div_u_mul(1u)"
    );
    assertEqualU64(
        m11_intX5FexprsX2E5Export21_i64X2EnoX5FfoldX5FdivX5FsX5Fmul(&instance, 1ull),
        0ull,
        "i64.no_fold_div_s_mul(1ull)"
    );
    assertEqualU64(
        m11_intX5FexprsX2E5Export21_i64X2EnoX5FfoldX5FdivX5FuX5Fmul(&instance, 1ull),
        0ull,
        "i64.no_fold_div_u_mul(1ull)"
    );
}
