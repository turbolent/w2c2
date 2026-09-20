
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.190.h"

void test() {
    m9_constX2E190Instance instance;
    m9_constX2E190Instantiate(&instance, resolveTestImports);
    printStart("const.190.wasm");
    assertEqualF32(
        m9_constX2E190Export1_f(&instance),
        8.88178631458362e-16,
        "f()"
    );
}
