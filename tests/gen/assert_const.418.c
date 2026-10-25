
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.418.h"

void test() {
    m9_constX2E418Instance instance;
    m9_constX2E418Instantiate(&instance, resolveTestImports);
    printStart("const.418.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E418Export1_f(&instance)),
        5044031582654955521ull,
        "f()"
    );
}
