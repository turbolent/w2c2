
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.260.h"

void test() {
    const260Instance instance;
    const260Instantiate(&instance, resolveTestImports);
    printStart("const.260.wasm");
    assertEqualF32(
        const260_f(&instance),
        1125900175278080.0,
        "f()"
    );
}
