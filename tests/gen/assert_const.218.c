
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.218.h"

void test() {
    const218Instance instance;
    const218Instantiate(&instance, resolveTestImports);
    printStart("const.218.wasm");
    assertEqualF32(
        const218_f(&instance),
        8.88178631458362e-16,
        "f()"
    );
}
