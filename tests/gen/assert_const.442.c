
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.442.h"

void test() {
    m9_constX2E442Instance instance;
    m9_constX2E442Instantiate(&instance, resolveTestImports);
    printStart("const.442.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E442Export1_f(&instance)),
        4877398396442247169ull,
        "f()"
    );
}
