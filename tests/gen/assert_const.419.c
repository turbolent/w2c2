
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.419.h"

void test() {
    const419Instance instance;
    const419Instantiate(&instance, resolveTestImports);
    printStart("const.419.wasm");
    assertEqualF64(
        const419_f(&instance),
        -1.584563250285287e+29,
        "f()"
    );
}
