
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.270.h"

void test() {
    const270Instance instance;
    const270Instantiate(&instance, resolveTestImports);
    printStart("const.270.wasm");
    assertEqualF32(
        const270_f(&instance),
        1125900041060352.0,
        "f()"
    );
}
