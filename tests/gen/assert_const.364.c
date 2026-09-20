
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.364.h"

void test() {
    m9_constX2E364Instance instance;
    m9_constX2E364Instantiate(&instance, resolveTestImports);
    printStart("const.364.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E364Export1_f(&instance)),
        1905022642377719810ull,
        "f()"
    );
}
