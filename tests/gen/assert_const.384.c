
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.384.h"

void test() {
    m9_constX2E384Instance instance;
    m9_constX2E384Instantiate(&instance, resolveTestImports);
    printStart("const.384.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E384Export1_f(&instance)),
        7309342195222315009ull,
        "f()"
    );
}
