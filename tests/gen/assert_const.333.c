
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.333.h"

void test() {
    m9_constX2E333Instance instance;
    m9_constX2E333Instantiate(&instance, resolveTestImports);
    printStart("const.333.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E333Export1_f(&instance)),
        11128394679232495617ull,
        "f()"
    );
}
