
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.436.h"

void test() {
    m9_constX2E436Instance instance;
    m9_constX2E436Instantiate(&instance, resolveTestImports);
    printStart("const.436.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E436Export1_f(&instance)),
        5044031582654955523ull,
        "f()"
    );
}
