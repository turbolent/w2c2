
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.268.h"

void test() {
    const268Instance instance;
    const268Instantiate(&instance, resolveTestImports);
    printStart("const.268.wasm");
    assertEqualF32(
        const268_f(&instance),
        1125900041060352.0,
        "f()"
    );
}
