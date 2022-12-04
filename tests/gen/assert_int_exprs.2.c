
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_int_exprs.2.h"

void test() {
    intexprs2Instance instance;
    intexprs2Instantiate(&instance, resolveTestImports);
    printStart("int_exprs.2.wasm");
    assertEqualU64(
        intexprs2_i64X2EnoX5FfoldX5FwrapX5FextendX5Fu(&instance, 4538991236898928ull),
        1079009392ull,
        "i64.no_fold_wrap_extend_u(4538991236898928ull)"
    );
}
