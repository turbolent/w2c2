
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.224.h"

void test() {
    const224Instance instance;
    const224Instantiate(&instance, resolveTestImports);
    printStart("const.224.wasm");
    assertEqualF32(
        const224_f(&instance),
        8.88178631458362e-16,
        "f()"
    );
}
