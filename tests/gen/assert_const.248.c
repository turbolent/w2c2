
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.248.h"

void test() {
    const248Instance instance;
    const248Instantiate(&instance, resolveTestImports);
    printStart("const.248.wasm");
    assertEqualF32(
        const248_f(&instance),
        1125900041060352.0,
        "f()"
    );
}
