
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.413.h"

void test() {
    m9_constX2E413Instance instance;
    m9_constX2E413Instantiate(&instance, resolveTestImports);
    printStart("const.413.wasm");
    assertEqualF64(
        m9_constX2E413Export1_f(&instance),
        -1.584563250285287e+29,
        "f()"
    );
}
