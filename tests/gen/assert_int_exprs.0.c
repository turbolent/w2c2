
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_int_exprs.0.h"

void test() {
    intexprs0Instance instance;
    intexprs0Instantiate(&instance, resolveTestImports);
    printStart("int_exprs.0.wasm");
    assertEqualU32(
        intexprs0_i32X2EnoX5FfoldX5FcmpX5FsX5Foffset(&instance, 2147483647u, 0u),
        1u,
        "i32.no_fold_cmp_s_offset(2147483647u, 0u)"
    );
    assertEqualU32(
        intexprs0_i32X2EnoX5FfoldX5FcmpX5FuX5Foffset(&instance, 4294967295u, 0u),
        1u,
        "i32.no_fold_cmp_u_offset(4294967295u, 0u)"
    );
    assertEqualU32(
        intexprs0_i64X2EnoX5FfoldX5FcmpX5FsX5Foffset(&instance, 9223372036854775807ull, 0ull),
        1u,
        "i64.no_fold_cmp_s_offset(9223372036854775807ull, 0ull)"
    );
    assertEqualU32(
        intexprs0_i64X2EnoX5FfoldX5FcmpX5FuX5Foffset(&instance, 18446744073709551615ull, 0ull),
        1u,
        "i64.no_fold_cmp_u_offset(18446744073709551615ull, 0ull)"
    );
}
