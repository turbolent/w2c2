
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.275.h"

void test() {
    const275Instance instance;
    const275Instantiate(&instance, resolveTestImports);
    printStart("const.275.wasm");
    assertEqualF32(
        const275_f(&instance),
        -1125900041060352.0,
        "f()"
    );
}
