
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.428.h"

void test() {
    m9_constX2E428Instance instance;
    m9_constX2E428Instantiate(&instance, resolveTestImports);
    printStart("const.428.wasm");
    assertEqualF64(
        m9_constX2E428Export1_f(&instance),
        1.5845632502852875e+29,
        "f()"
    );
}
