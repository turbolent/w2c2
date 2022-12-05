
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.424.h"

void test() {
    const424Instance instance;
    const424Instantiate(&instance, resolveTestImports);
    printStart("const.424.wasm");
    assertEqualF64(
        const424_f(&instance),
        1.5845632502852875e+29,
        "f()"
    );
}
