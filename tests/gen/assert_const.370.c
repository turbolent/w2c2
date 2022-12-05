
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.370.h"

void test() {
    const370Instance instance;
    const370Instantiate(&instance, resolveTestImports);
    printStart("const.370.wasm");
    assertEqualF64(
        const370_f(&instance),
        2.409919865102885e-181,
        "f()"
    );
}
