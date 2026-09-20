
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.435.h"

void test() {
    m9_constX2E435Instance instance;
    m9_constX2E435Instantiate(&instance, resolveTestImports);
    printStart("const.435.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E435Export1_f(&instance)),
        14267403619509731330ull,
        "f()"
    );
}
