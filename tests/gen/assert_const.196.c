
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.196.h"

void test() {
    const196Instance instance;
    const196Instantiate(&instance, resolveTestImports);
    printStart("const.196.wasm");
    assertEqualF32(
        const196_f(&instance),
        8.88178631458362e-16,
        "f()"
    );
}
