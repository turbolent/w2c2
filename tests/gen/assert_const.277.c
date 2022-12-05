
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.277.h"

void test() {
    const277Instance instance;
    const277Instantiate(&instance, resolveTestImports);
    printStart("const.277.wasm");
    assertEqualF32(
        const277_f(&instance),
        -1125900041060352.0,
        "f()"
    );
}
