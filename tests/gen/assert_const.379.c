
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.379.h"

void test() {
    const379Instance instance;
    const379Instantiate(&instance, resolveTestImports);
    printStart("const.379.wasm");
    assertEqualF64(
        const379_f(&instance),
        -5.357543035931338e+300,
        "f()"
    );
}
