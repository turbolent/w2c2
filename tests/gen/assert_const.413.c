
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.413.h"

void test() {
    m9_constX2E413Instance instance;
    m9_constX2E413Instantiate(&instance, resolveTestImports);
    printStart("const.413.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m9_constX2E413Export1_f(&instance)),
        14267403619509731329ull,
        "f()"
    );
}
