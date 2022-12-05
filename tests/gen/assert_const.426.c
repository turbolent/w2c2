
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.426.h"

void test() {
    const426Instance instance;
    const426Instantiate(&instance, resolveTestImports);
    printStart("const.426.wasm");
    assertEqualF64(
        const426_f(&instance),
        1.5845632502852875e+29,
        "f()"
    );
}
