
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.398.h"

void test() {
    m9_constX2E398Instance instance;
    m9_constX2E398Instantiate(&instance, resolveTestImports);
    printStart("const.398.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E398Export1_f(&instance)),
        7309342195222315010ull,
        "f()"
    );
}
