
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.324.h"

void test() {
    const324Instance instance;
    const324Instantiate(&instance, resolveTestImports);
    printStart("const.324.wasm");
    assertEqualF64(
        const324_f(&instance),
        2.4099198651028847e-181,
        "f()"
    );
}
