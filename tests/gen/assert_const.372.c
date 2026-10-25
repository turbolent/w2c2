
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.372.h"

void test() {
    m9_constX2E372Instance instance;
    m9_constX2E372Instantiate(&instance, resolveTestImports);
    printStart("const.372.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E372Export1_f(&instance)),
        1905022642377719811ull,
        "f()"
    );
}
