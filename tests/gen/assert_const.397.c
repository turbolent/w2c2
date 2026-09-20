
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.397.h"

void test() {
    m9_constX2E397Instance instance;
    m9_constX2E397Instantiate(&instance, resolveTestImports);
    printStart("const.397.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E397Export1_f(&instance)),
        16532714232077090818ull,
        "f()"
    );
}
