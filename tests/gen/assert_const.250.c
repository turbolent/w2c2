
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.250.h"

void test() {
    const250Instance instance;
    const250Instantiate(&instance, resolveTestImports);
    printStart("const.250.wasm");
    assertEqualF32(
        const250_f(&instance),
        1125900175278080.0,
        "f()"
    );
}
