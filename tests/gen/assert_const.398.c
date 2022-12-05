
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.398.h"

void test() {
    const398Instance instance;
    const398Instantiate(&instance, resolveTestImports);
    printStart("const.398.wasm");
    assertEqualF64(
        const398_f(&instance),
        4.149515568880995e+180,
        "f()"
    );
}
