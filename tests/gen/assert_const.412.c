
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.412.h"

void test() {
    const412Instance instance;
    const412Instantiate(&instance, resolveTestImports);
    printStart("const.412.wasm");
    assertEqualF64(
        const412_f(&instance),
        1.584563250285287e+29,
        "f()"
    );
}
