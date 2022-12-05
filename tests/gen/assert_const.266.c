
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.266.h"

void test() {
    const266Instance instance;
    const266Instantiate(&instance, resolveTestImports);
    printStart("const.266.wasm");
    assertEqualF32(
        const266_f(&instance),
        1125899906842624.0,
        "f()"
    );
}
