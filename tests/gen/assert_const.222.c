
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.222.h"

void test() {
    const222Instance instance;
    const222Instantiate(&instance, resolveTestImports);
    printStart("const.222.wasm");
    assertEqualF32(
        const222_f(&instance),
        8.88178631458362e-16,
        "f()"
    );
}
