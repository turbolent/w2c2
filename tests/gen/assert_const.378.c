
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.378.h"

void test() {
    const378Instance instance;
    const378Instantiate(&instance, resolveTestImports);
    printStart("const.378.wasm");
    assertEqualF64(
        const378_f(&instance),
        5.357543035931338e+300,
        "f()"
    );
}
