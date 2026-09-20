
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.436.h"

void test() {
    m9_constX2E436Instance instance;
    m9_constX2E436Instantiate(&instance, resolveTestImports);
    printStart("const.436.wasm");
    assertEqualF64(
        m9_constX2E436Export1_f(&instance),
        1.5845632502852878e+29,
        "f()"
    );
}
