
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.477.h"

void test() {
    const477Instance instance;
    const477Instantiate(&instance, resolveTestImports);
    printStart("const.477.wasm");
    assertEqualF64(
        const477_f(&instance),
        -1.7976931348623157e+308,
        "f()"
    );
}
