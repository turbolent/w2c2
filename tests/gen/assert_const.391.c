
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.391.h"

void test() {
    m9_constX2E391Instance instance;
    m9_constX2E391Instantiate(&instance, resolveTestImports);
    printStart("const.391.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E391Export1_f(&instance)),
        16532714232077090817ull,
        "f()"
    );
}
