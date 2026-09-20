
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.271.h"

void test() {
    m9_constX2E271Instance instance;
    m9_constX2E271Instantiate(&instance, resolveTestImports);
    printStart("const.271.wasm");
    assertEqualF32(
        m9_constX2E271Export1_f(&instance),
        -1125900041060352.0,
        "f()"
    );
}
