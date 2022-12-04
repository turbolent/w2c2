
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.254.h"

void test() {
    const254Instance instance;
    const254Instantiate(&instance, resolveTestImports);
    printStart("const.254.wasm");
    assertEqualF32(
        const254_f(&instance),
        1125900175278080.0,
        "f()"
    );
}
