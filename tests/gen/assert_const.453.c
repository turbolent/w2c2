
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.453.h"

void test() {
    m9_constX2E453Instance instance;
    m9_constX2E453Instantiate(&instance, resolveTestImports);
    printStart("const.453.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E453Export1_f(&instance)),
        9223372036854775809ull,
        "f()"
    );
}
