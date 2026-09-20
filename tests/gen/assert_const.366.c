
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.366.h"

void test() {
    m9_constX2E366Instance instance;
    m9_constX2E366Instantiate(&instance, resolveTestImports);
    printStart("const.366.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E366Export1_f(&instance)),
        1905022642377719810ull,
        "f()"
    );
}
