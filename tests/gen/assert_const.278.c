
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.278.h"

void test() {
    const278Instance instance;
    const278Instantiate(&instance, resolveTestImports);
    printStart("const.278.wasm");
    assertEqualF32(
        const278_f(&instance),
        1125900175278080.0,
        "f()"
    );
}
