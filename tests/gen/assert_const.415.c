
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.415.h"

void test() {
    const415Instance instance;
    const415Instantiate(&instance, resolveTestImports);
    printStart("const.415.wasm");
    assertEqualF64(
        const415_f(&instance),
        -1.584563250285287e+29,
        "f()"
    );
}
