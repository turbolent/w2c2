
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.356.h"

void test() {
    m9_constX2E356Instance instance;
    m9_constX2E356Instantiate(&instance, resolveTestImports);
    printStart("const.356.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E356Export1_f(&instance)),
        1905022642377719809ull,
        "f()"
    );
}
