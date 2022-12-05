
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.230.h"

void test() {
    const230Instance instance;
    const230Instantiate(&instance, resolveTestImports);
    printStart("const.230.wasm");
    assertEqualF32(
        const230_f(&instance),
        8.881784197001252e-16,
        "f()"
    );
}
