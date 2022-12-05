
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.406.h"

void test() {
    const406Instance instance;
    const406Instantiate(&instance, resolveTestImports);
    printStart("const.406.wasm");
    assertEqualF64(
        const406_f(&instance),
        4.149515568880995e+180,
        "f()"
    );
}
