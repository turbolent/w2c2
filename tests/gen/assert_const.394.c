
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.394.h"

void test() {
    m9_constX2E394Instance instance;
    m9_constX2E394Instantiate(&instance, resolveTestImports);
    printStart("const.394.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E394Export1_f(&instance)),
        7309342195222315010ull,
        "f()"
    );
}
