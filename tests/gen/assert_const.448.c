
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.448.h"

void test() {
    const448Instance instance;
    const448Instantiate(&instance, resolveTestImports);
    printStart("const.448.wasm");
    assertEqualF64(
        const448_f(&instance),
        5e-324,
        "f()"
    );
}
