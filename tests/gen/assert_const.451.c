
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.451.h"

void test() {
    m9_constX2E451Instance instance;
    m9_constX2E451Instantiate(&instance, resolveTestImports);
    printStart("const.451.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E451Export1_f(&instance)),
        9223372036854775809ull,
        "f()"
    );
}
