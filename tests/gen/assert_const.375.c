
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.375.h"

void test() {
    const375Instance instance;
    const375Instantiate(&instance, resolveTestImports);
    printStart("const.375.wasm");
    assertEqualF64(
        const375_f(&instance),
        -5.357543035931337e+300,
        "f()"
    );
}
