
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.362.h"

void test() {
    m9_constX2E362Instance instance;
    m9_constX2E362Instantiate(&instance, resolveTestImports);
    printStart("const.362.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E362Export1_f(&instance)),
        1905022642377719810ull,
        "f()"
    );
}
