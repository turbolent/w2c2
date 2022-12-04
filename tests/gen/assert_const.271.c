
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.271.h"

void test() {
    const271Instance instance;
    const271Instantiate(&instance, resolveTestImports);
    printStart("const.271.wasm");
    assertEqualF32(
        const271_f(&instance),
        -1125900041060352.0,
        "f()"
    );
}
