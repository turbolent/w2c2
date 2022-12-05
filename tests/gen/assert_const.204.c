
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.204.h"

void test() {
    const204Instance instance;
    const204Instantiate(&instance, resolveTestImports);
    printStart("const.204.wasm");
    assertEqualF32(
        const204_f(&instance),
        8.881787373374805e-16,
        "f()"
    );
}
