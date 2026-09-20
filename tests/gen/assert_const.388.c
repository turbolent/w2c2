
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.388.h"

void test() {
    m9_constX2E388Instance instance;
    m9_constX2E388Instantiate(&instance, resolveTestImports);
    printStart("const.388.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E388Export1_f(&instance)),
        7309342195222315009ull,
        "f()"
    );
}
