
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.469.h"

void test() {
    const469Instance instance;
    const469Instantiate(&instance, resolveTestImports);
    printStart("const.469.wasm");
    assertEqualF64(
        const469_f(&instance),
        -1e-323,
        "f()"
    );
}
