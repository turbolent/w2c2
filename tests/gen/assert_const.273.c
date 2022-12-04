
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.273.h"

void test() {
    const273Instance instance;
    const273Instantiate(&instance, resolveTestImports);
    printStart("const.273.wasm");
    assertEqualF32(
        const273_f(&instance),
        -1125900041060352.0,
        "f()"
    );
}
