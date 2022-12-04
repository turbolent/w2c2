
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.446.h"

void test() {
    const446Instance instance;
    const446Instantiate(&instance, resolveTestImports);
    printStart("const.446.wasm");
    assertEqualF64(
        const446_f(&instance),
        0.0,
        "f()"
    );
}
