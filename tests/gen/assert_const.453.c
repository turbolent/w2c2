
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.453.h"

void test() {
    const453Instance instance;
    const453Instantiate(&instance, resolveTestImports);
    printStart("const.453.wasm");
    assertEqualF64(
        const453_f(&instance),
        -5e-324,
        "f()"
    );
}
