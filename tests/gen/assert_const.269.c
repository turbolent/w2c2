
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.269.h"

void test() {
    m9_constX2E269Instance instance;
    m9_constX2E269Instantiate(&instance, resolveTestImports);
    printStart("const.269.wasm");
    assertEqualF32(
        m9_constX2E269Export1_f(&instance),
        -1125900041060352.0,
        "f()"
    );
}
