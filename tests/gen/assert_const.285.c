
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.285.h"

void test() {
    const285Instance instance;
    const285Instantiate(&instance, resolveTestImports);
    printStart("const.285.wasm");
    assertEqualF32(
        const285_f(&instance),
        -1125900041060352.0,
        "f()"
    );
}
