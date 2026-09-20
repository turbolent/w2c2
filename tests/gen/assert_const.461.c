
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.461.h"

void test() {
    m9_constX2E461Instance instance;
    m9_constX2E461Instantiate(&instance, resolveTestImports);
    printStart("const.461.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E461Export1_f(&instance)),
        9223372036854775810ull,
        "f()"
    );
}
