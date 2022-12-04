
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.437.h"

void test() {
    const437Instance instance;
    const437Instantiate(&instance, resolveTestImports);
    printStart("const.437.wasm");
    assertEqualF64(
        const437_f(&instance),
        -1.5845632502852878e+29,
        "f()"
    );
}
