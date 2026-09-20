
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_int_exprs.9.h"

void test() {
    m11_intX5FexprsX2E9Instance instance;
    m11_intX5FexprsX2E9Instantiate(&instance, resolveTestImports);
    printStart("int_exprs.9.wasm");
    assertEqualU32(
        m11_intX5FexprsX2E9Export19_i32X2EnoX5FfoldX5FdivX5FsX5F2(&instance, 4294967285u),
        4294967291u,
        "i32.no_fold_div_s_2(4294967285u)"
    );
    assertEqualU64(
        m11_intX5FexprsX2E9Export19_i64X2EnoX5FfoldX5FdivX5FsX5F2(&instance, 18446744073709551605ull),
        18446744073709551611ull,
        "i64.no_fold_div_s_2(18446744073709551605ull)"
    );
}
