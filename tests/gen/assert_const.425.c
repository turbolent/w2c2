
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.425.h"

void test() {
    m9_constX2E425Instance instance;
    m9_constX2E425Instantiate(&instance, resolveTestImports);
    printStart("const.425.wasm");
    assertEqualF64(
        m9_constX2E425Export1_f(&instance),
        -1.5845632502852875e+29,
        "f()"
    );
}
