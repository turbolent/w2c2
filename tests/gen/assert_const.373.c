
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.373.h"

void test() {
    const373Instance instance;
    const373Instantiate(&instance, resolveTestImports);
    printStart("const.373.wasm");
    assertEqualF64(
        const373_f(&instance),
        -2.4099198651028857e-181,
        "f()"
    );
}
