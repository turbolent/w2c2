
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.446.h"

void test() {
    m9_constX2E446Instance instance;
    m9_constX2E446Instantiate(&instance, resolveTestImports);
    printStart("const.446.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E446Export1_f(&instance)),
        0ull,
        "f()"
    );
}
