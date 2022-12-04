
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.192.h"

void test() {
    const192Instance instance;
    const192Instantiate(&instance, resolveTestImports);
    printStart("const.192.wasm");
    assertEqualF32(
        const192_f(&instance),
        8.88178631458362e-16,
        "f()"
    );
}
