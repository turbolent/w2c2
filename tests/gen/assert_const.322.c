
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.322.h"

void test() {
    m9_constX2E322Instance instance;
    m9_constX2E322Instantiate(&instance, resolveTestImports);
    printStart("const.322.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E322Export1_f(&instance)),
        1905022642377719808ull,
        "f()"
    );
}
