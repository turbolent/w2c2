
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.369.h"

void test() {
    const369Instance instance;
    const369Instantiate(&instance, resolveTestImports);
    printStart("const.369.wasm");
    assertEqualF64(
        const369_f(&instance),
        -2.409919865102885e-181,
        "f()"
    );
}
