
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.436.h"

void test() {
    const436Instance instance;
    const436Instantiate(&instance, resolveTestImports);
    printStart("const.436.wasm");
    assertEqualF64(
        const436_f(&instance),
        1.5845632502852878e+29,
        "f()"
    );
}
