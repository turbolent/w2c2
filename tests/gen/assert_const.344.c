
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.344.h"

void test() {
    const344Instance instance;
    const344Instantiate(&instance, resolveTestImports);
    printStart("const.344.wasm");
    assertEqualF64(
        const344_f(&instance),
        2.409919865102885e-181,
        "f()"
    );
}
