
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.267.h"

void test() {
    const267Instance instance;
    const267Instantiate(&instance, resolveTestImports);
    printStart("const.267.wasm");
    assertEqualF32(
        const267_f(&instance),
        -1125899906842624.0,
        "f()"
    );
}
