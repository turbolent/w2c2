
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.465.h"

void test() {
    m9_constX2E465Instance instance;
    m9_constX2E465Instantiate(&instance, resolveTestImports);
    printStart("const.465.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E465Export1_f(&instance)),
        9223372036854775810ull,
        "f()"
    );
}
