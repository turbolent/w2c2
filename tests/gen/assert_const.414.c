
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.414.h"

void test() {
    const414Instance instance;
    const414Instantiate(&instance, resolveTestImports);
    printStart("const.414.wasm");
    assertEqualF64(
        const414_f(&instance),
        1.584563250285287e+29,
        "f()"
    );
}
