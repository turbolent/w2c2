
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.339.h"

void test() {
    const339Instance instance;
    const339Instantiate(&instance, resolveTestImports);
    printStart("const.339.wasm");
    assertEqualF64(
        const339_f(&instance),
        -2.409919865102885e-181,
        "f()"
    );
}
