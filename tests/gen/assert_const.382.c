
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.382.h"

void test() {
    m9_constX2E382Instance instance;
    m9_constX2E382Instantiate(&instance, resolveTestImports);
    printStart("const.382.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E382Export1_f(&instance)),
        7309342195222315008ull,
        "f()"
    );
}
