
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.427.h"

void test() {
    const427Instance instance;
    const427Instantiate(&instance, resolveTestImports);
    printStart("const.427.wasm");
    assertEqualF64(
        const427_f(&instance),
        -1.5845632502852875e+29,
        "f()"
    );
}
