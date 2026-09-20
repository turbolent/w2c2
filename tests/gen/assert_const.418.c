
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.418.h"

void test() {
    m9_constX2E418Instance instance;
    m9_constX2E418Instantiate(&instance, resolveTestImports);
    printStart("const.418.wasm");
    assertEqualF64(
        m9_constX2E418Export1_f(&instance),
        1.584563250285287e+29,
        "f()"
    );
}
