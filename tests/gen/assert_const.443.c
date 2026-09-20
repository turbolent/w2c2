
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.443.h"

void test() {
    m9_constX2E443Instance instance;
    m9_constX2E443Instantiate(&instance, resolveTestImports);
    printStart("const.443.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E443Export1_f(&instance)),
        14100770433297022977ull,
        "f()"
    );
}
