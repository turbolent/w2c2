
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.381.h"

void test() {
    const381Instance instance;
    const381Instantiate(&instance, resolveTestImports);
    printStart("const.381.wasm");
    assertEqualF64(
        const381_f(&instance),
        -5.357543035931339e+300,
        "f()"
    );
}
