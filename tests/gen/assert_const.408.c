
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.408.h"

void test() {
    m9_constX2E408Instance instance;
    m9_constX2E408Instantiate(&instance, resolveTestImports);
    printStart("const.408.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E408Export1_f(&instance)),
        7309342195222315011ull,
        "f()"
    );
}
