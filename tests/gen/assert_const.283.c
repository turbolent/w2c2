
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.283.h"

void test() {
    const283Instance instance;
    const283Instantiate(&instance, resolveTestImports);
    printStart("const.283.wasm");
    assertEqualF32(
        const283_f(&instance),
        -1125900041060352.0,
        "f()"
    );
}
