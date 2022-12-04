
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.404.h"

void test() {
    const404Instance instance;
    const404Instantiate(&instance, resolveTestImports);
    printStart("const.404.wasm");
    assertEqualF64(
        const404_f(&instance),
        4.149515568880995e+180,
        "f()"
    );
}
