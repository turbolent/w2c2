
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.373.h"

void test() {
    m9_constX2E373Instance instance;
    m9_constX2E373Instantiate(&instance, resolveTestImports);
    printStart("const.373.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E373Export1_f(&instance)),
        11128394679232495619ull,
        "f()"
    );
}
