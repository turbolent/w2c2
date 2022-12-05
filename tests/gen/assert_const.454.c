
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.454.h"

void test() {
    const454Instance instance;
    const454Instantiate(&instance, resolveTestImports);
    printStart("const.454.wasm");
    assertEqualF64(
        const454_f(&instance),
        5e-324,
        "f()"
    );
}
