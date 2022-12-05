
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.247.h"

void test() {
    const247Instance instance;
    const247Instantiate(&instance, resolveTestImports);
    printStart("const.247.wasm");
    assertEqualF32(
        const247_f(&instance),
        -1125900041060352.0,
        "f()"
    );
}
