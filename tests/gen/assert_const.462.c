
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.462.h"

void test() {
    m9_constX2E462Instance instance;
    m9_constX2E462Instantiate(&instance, resolveTestImports);
    printStart("const.462.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E462Export1_f(&instance)),
        2ull,
        "f()"
    );
}
