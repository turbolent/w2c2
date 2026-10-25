
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.376.h"

void test() {
    m9_constX2E376Instance instance;
    m9_constX2E376Instantiate(&instance, resolveTestImports);
    printStart("const.376.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E376Export1_f(&instance)),
        9106278446543142913ull,
        "f()"
    );
}
