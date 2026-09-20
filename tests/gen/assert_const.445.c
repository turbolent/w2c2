
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.445.h"

void test() {
    m9_constX2E445Instance instance;
    m9_constX2E445Instantiate(&instance, resolveTestImports);
    printStart("const.445.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E445Export1_f(&instance)),
        14100770433297022978ull,
        "f()"
    );
}
