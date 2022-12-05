
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.287.h"

void test() {
    const287Instance instance;
    const287Instantiate(&instance, resolveTestImports);
    printStart("const.287.wasm");
    assertEqualF32(
        const287_f(&instance),
        -1125900175278080.0,
        "f()"
    );
}
