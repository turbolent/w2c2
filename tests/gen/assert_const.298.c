
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.298.h"

void test() {
    const298Instance instance;
    const298Instantiate(&instance, resolveTestImports);
    printStart("const.298.wasm");
    assertEqualF32(
        const298_f(&instance),
        1.401298464324817e-45,
        "f()"
    );
}
