
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.426.h"

void test() {
    m9_constX2E426Instance instance;
    m9_constX2E426Instantiate(&instance, resolveTestImports);
    printStart("const.426.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E426Export1_f(&instance)),
        5044031582654955522ull,
        "f()"
    );
}
