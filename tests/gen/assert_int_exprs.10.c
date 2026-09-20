
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_int_exprs.10.h"

void test() {
    m12_intX5FexprsX2E10Instance instance;
    m12_intX5FexprsX2E10Instantiate(&instance, resolveTestImports);
    printStart("int_exprs.10.wasm");
    assertEqualU32(
        m12_intX5FexprsX2E10Export19_i32X2EnoX5FfoldX5FremX5FsX5F2(&instance, 4294967285u),
        4294967295u,
        "i32.no_fold_rem_s_2(4294967285u)"
    );
    assertEqualU64(
        m12_intX5FexprsX2E10Export19_i64X2EnoX5FfoldX5FremX5FsX5F2(&instance, 18446744073709551605ull),
        18446744073709551615ull,
        "i64.no_fold_rem_s_2(18446744073709551605ull)"
    );
}
