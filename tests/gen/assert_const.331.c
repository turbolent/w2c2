
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.331.h"

void test() {
    const331Instance instance;
    const331Instantiate(&instance, resolveTestImports);
    printStart("const.331.wasm");
    assertEqualF64(
        const331_f(&instance),
        -2.4099198651028847e-181,
        "f()"
    );
}
