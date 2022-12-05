
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.431.h"

void test() {
    const431Instance instance;
    const431Instantiate(&instance, resolveTestImports);
    printStart("const.431.wasm");
    assertEqualF64(
        const431_f(&instance),
        -1.5845632502852875e+29,
        "f()"
    );
}
