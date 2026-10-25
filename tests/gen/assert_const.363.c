
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.363.h"

void test() {
    m9_constX2E363Instance instance;
    m9_constX2E363Instantiate(&instance, resolveTestImports);
    printStart("const.363.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E363Export1_f(&instance)),
        11128394679232495618ull,
        "f()"
    );
}
