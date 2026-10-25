
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.402.h"

void test() {
    m9_constX2E402Instance instance;
    m9_constX2E402Instantiate(&instance, resolveTestImports);
    printStart("const.402.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E402Export1_f(&instance)),
        7309342195222315010ull,
        "f()"
    );
}
