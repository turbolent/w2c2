
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.359.h"

void test() {
    m9_constX2E359Instance instance;
    m9_constX2E359Instantiate(&instance, resolveTestImports);
    printStart("const.359.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E359Export1_f(&instance)),
        11128394679232495617ull,
        "f()"
    );
}
