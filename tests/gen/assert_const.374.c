
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.374.h"

void test() {
    const374Instance instance;
    const374Instantiate(&instance, resolveTestImports);
    printStart("const.374.wasm");
    assertEqualF64(
        const374_f(&instance),
        5.357543035931337e+300,
        "f()"
    );
}
