
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.202.h"

void test() {
    const202Instance instance;
    const202Instantiate(&instance, resolveTestImports);
    printStart("const.202.wasm");
    assertEqualF32(
        const202_f(&instance),
        8.88178631458362e-16,
        "f()"
    );
}
