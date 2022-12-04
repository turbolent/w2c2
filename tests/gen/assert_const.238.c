
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.238.h"

void test() {
    const238Instance instance;
    const238Instantiate(&instance, resolveTestImports);
    printStart("const.238.wasm");
    assertEqualF32(
        const238_f(&instance),
        1125899906842624.0,
        "f()"
    );
}
