
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.474.h"

void test() {
    const474Instance instance;
    const474Instantiate(&instance, resolveTestImports);
    printStart("const.474.wasm");
    assertEqualF64(
        const474_f(&instance),
        1.7976931348623157e+308,
        "f()"
    );
}
