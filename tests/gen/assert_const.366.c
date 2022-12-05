
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.366.h"

void test() {
    const366Instance instance;
    const366Instantiate(&instance, resolveTestImports);
    printStart("const.366.wasm");
    assertEqualF64(
        const366_f(&instance),
        2.409919865102885e-181,
        "f()"
    );
}
