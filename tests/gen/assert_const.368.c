
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.368.h"

void test() {
    const368Instance instance;
    const368Instantiate(&instance, resolveTestImports);
    printStart("const.368.wasm");
    assertEqualF64(
        const368_f(&instance),
        2.409919865102885e-181,
        "f()"
    );
}
