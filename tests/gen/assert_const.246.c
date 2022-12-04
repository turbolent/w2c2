
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.246.h"

void test() {
    const246Instance instance;
    const246Instantiate(&instance, resolveTestImports);
    printStart("const.246.wasm");
    assertEqualF32(
        const246_f(&instance),
        1125900041060352.0,
        "f()"
    );
}
