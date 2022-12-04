
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.456.h"

void test() {
    const456Instance instance;
    const456Instantiate(&instance, resolveTestImports);
    printStart("const.456.wasm");
    assertEqualF64(
        const456_f(&instance),
        5e-324,
        "f()"
    );
}
