
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.452.h"

void test() {
    const452Instance instance;
    const452Instantiate(&instance, resolveTestImports);
    printStart("const.452.wasm");
    assertEqualF64(
        const452_f(&instance),
        5e-324,
        "f()"
    );
}
