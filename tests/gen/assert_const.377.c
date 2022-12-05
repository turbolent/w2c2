
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.377.h"

void test() {
    const377Instance instance;
    const377Instantiate(&instance, resolveTestImports);
    printStart("const.377.wasm");
    assertEqualF64(
        const377_f(&instance),
        -5.357543035931338e+300,
        "f()"
    );
}
