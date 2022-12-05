
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.245.h"

void test() {
    const245Instance instance;
    const245Instantiate(&instance, resolveTestImports);
    printStart("const.245.wasm");
    assertEqualF32(
        const245_f(&instance),
        -1125900041060352.0,
        "f()"
    );
}
