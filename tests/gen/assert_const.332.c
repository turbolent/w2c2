
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.332.h"

void test() {
    m9_constX2E332Instance instance;
    m9_constX2E332Instantiate(&instance, resolveTestImports);
    printStart("const.332.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E332Export1_f(&instance)),
        1905022642377719809ull,
        "f()"
    );
}
