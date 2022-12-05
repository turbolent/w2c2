
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.450.h"

void test() {
    const450Instance instance;
    const450Instantiate(&instance, resolveTestImports);
    printStart("const.450.wasm");
    assertEqualF64(
        const450_f(&instance),
        5e-324,
        "f()"
    );
}
