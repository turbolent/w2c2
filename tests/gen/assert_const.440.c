
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.440.h"

void test() {
    m9_constX2E440Instance instance;
    m9_constX2E440Instantiate(&instance, resolveTestImports);
    printStart("const.440.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E440Export1_f(&instance)),
        4877398396442247169ull,
        "f()"
    );
}
