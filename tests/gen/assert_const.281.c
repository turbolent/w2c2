
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.281.h"

void test() {
    const281Instance instance;
    const281Instantiate(&instance, resolveTestImports);
    printStart("const.281.wasm");
    assertEqualF32(
        const281_f(&instance),
        -1125899906842624.0,
        "f()"
    );
}
