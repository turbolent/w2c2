
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.237.h"

void test() {
    const237Instance instance;
    const237Instantiate(&instance, resolveTestImports);
    printStart("const.237.wasm");
    assertEqualF32(
        const237_f(&instance),
        -8.88178631458362e-16,
        "f()"
    );
}
