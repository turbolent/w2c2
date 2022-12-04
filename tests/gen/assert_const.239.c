
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.239.h"

void test() {
    const239Instance instance;
    const239Instantiate(&instance, resolveTestImports);
    printStart("const.239.wasm");
    assertEqualF32(
        const239_f(&instance),
        -1125899906842624.0,
        "f()"
    );
}
