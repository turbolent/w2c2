
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.328.h"

void test() {
    m9_constX2E328Instance instance;
    m9_constX2E328Instantiate(&instance, resolveTestImports);
    printStart("const.328.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E328Export1_f(&instance)),
        1905022642377719809ull,
        "f()"
    );
}
