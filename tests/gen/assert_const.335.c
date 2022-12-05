
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.335.h"

void test() {
    const335Instance instance;
    const335Instantiate(&instance, resolveTestImports);
    printStart("const.335.wasm");
    assertEqualF64(
        const335_f(&instance),
        -2.409919865102885e-181,
        "f()"
    );
}
