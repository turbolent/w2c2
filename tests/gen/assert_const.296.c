
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.296.h"

void test() {
    const296Instance instance;
    const296Instantiate(&instance, resolveTestImports);
    printStart("const.296.wasm");
    assertEqualF32(
        const296_f(&instance),
        1.401298464324817e-45,
        "f()"
    );
}
