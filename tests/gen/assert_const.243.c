
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.243.h"

void test() {
    const243Instance instance;
    const243Instantiate(&instance, resolveTestImports);
    printStart("const.243.wasm");
    assertEqualF32(
        const243_f(&instance),
        -1125900041060352.0,
        "f()"
    );
}
