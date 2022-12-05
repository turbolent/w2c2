
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.282.h"

void test() {
    const282Instance instance;
    const282Instantiate(&instance, resolveTestImports);
    printStart("const.282.wasm");
    assertEqualF32(
        const282_f(&instance),
        1125900041060352.0,
        "f()"
    );
}
