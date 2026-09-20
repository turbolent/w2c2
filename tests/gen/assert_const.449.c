
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.449.h"

void test() {
    m9_constX2E449Instance instance;
    m9_constX2E449Instantiate(&instance, resolveTestImports);
    printStart("const.449.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E449Export1_f(&instance)),
        9223372036854775809ull,
        "f()"
    );
}
