
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.476.h"

void test() {
    const476Instance instance;
    const476Instantiate(&instance, resolveTestImports);
    printStart("const.476.wasm");
    assertEqualF64(
        const476_f(&instance),
        1.7976931348623157e+308,
        "f()"
    );
}
