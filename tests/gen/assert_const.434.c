
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.434.h"

void test() {
    const434Instance instance;
    const434Instantiate(&instance, resolveTestImports);
    printStart("const.434.wasm");
    assertEqualF64(
        const434_f(&instance),
        1.5845632502852875e+29,
        "f()"
    );
}
