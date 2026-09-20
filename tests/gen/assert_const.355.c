
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.355.h"

void test() {
    m9_constX2E355Instance instance;
    m9_constX2E355Instantiate(&instance, resolveTestImports);
    printStart("const.355.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E355Export1_f(&instance)),
        11128394679232495617ull,
        "f()"
    );
}
