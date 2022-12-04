
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.286.h"

void test() {
    const286Instance instance;
    const286Instantiate(&instance, resolveTestImports);
    printStart("const.286.wasm");
    assertEqualF32(
        const286_f(&instance),
        1125900175278080.0,
        "f()"
    );
}
