
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.416.h"

void test() {
    const416Instance instance;
    const416Instantiate(&instance, resolveTestImports);
    printStart("const.416.wasm");
    assertEqualF64(
        const416_f(&instance),
        1.584563250285287e+29,
        "f()"
    );
}
