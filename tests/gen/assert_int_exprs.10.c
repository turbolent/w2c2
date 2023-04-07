
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_int_exprs.10.h"

void test() {
    intexprs10Instance instance;
    intexprs10Instantiate(&instance, resolveTestImports);
    printStart("int_exprs.10.wasm");
    assertEqualU32(
        intexprs10_i32X2Eno_fold_rem_s_2(&instance, 4294967285u),
        4294967295u,
        "i32.no_fold_rem_s_2(4294967285u)"
    );
    assertEqualU64(
        intexprs10_i64X2Eno_fold_rem_s_2(&instance, 18446744073709551605ull),
        18446744073709551615ull,
        "i64.no_fold_rem_s_2(18446744073709551605ull)"
    );
}
