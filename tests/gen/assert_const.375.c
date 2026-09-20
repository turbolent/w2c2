
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.375.h"

void test() {
    m9_constX2E375Instance instance;
    m9_constX2E375Instantiate(&instance, resolveTestImports);
    printStart("const.375.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E375Export1_f(&instance)),
        18329650483397918720ull,
        "f()"
    );
}
