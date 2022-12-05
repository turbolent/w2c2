
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.380.h"

void test() {
    const380Instance instance;
    const380Instantiate(&instance, resolveTestImports);
    printStart("const.380.wasm");
    assertEqualF64(
        const380_f(&instance),
        5.357543035931339e+300,
        "f()"
    );
}
