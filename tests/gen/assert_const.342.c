
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.342.h"

void test() {
    m9_constX2E342Instance instance;
    m9_constX2E342Instantiate(&instance, resolveTestImports);
    printStart("const.342.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E342Export1_f(&instance)),
        1905022642377719810ull,
        "f()"
    );
}
