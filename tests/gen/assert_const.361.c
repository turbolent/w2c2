
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.361.h"

void test() {
    const361Instance instance;
    const361Instantiate(&instance, resolveTestImports);
    printStart("const.361.wasm");
    assertEqualF64(
        const361_f(&instance),
        -2.409919865102885e-181,
        "f()"
    );
}
