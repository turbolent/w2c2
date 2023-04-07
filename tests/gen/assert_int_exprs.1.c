
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_int_exprs.1.h"

void test() {
    intexprs1Instance instance;
    intexprs1Instantiate(&instance, resolveTestImports);
    printStart("int_exprs.1.wasm");
    assertEqualU64(
        intexprs1_i64X2Eno_fold_wrap_extend_s(&instance, 4538991236898928ull),
        1079009392ull,
        "i64.no_fold_wrap_extend_s(4538991236898928ull)"
    );
    assertEqualU64(
        intexprs1_i64X2Eno_fold_wrap_extend_s(&instance, 45230338458316960ull),
        18446744072918986912ull,
        "i64.no_fold_wrap_extend_s(45230338458316960ull)"
    );
}
