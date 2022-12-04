
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.421.h"

void test() {
    const421Instance instance;
    const421Instantiate(&instance, resolveTestImports);
    printStart("const.421.wasm");
    assertEqualF64(
        const421_f(&instance),
        -1.584563250285287e+29,
        "f()"
    );
}
