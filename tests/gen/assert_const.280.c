
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.280.h"

void test() {
    const280Instance instance;
    const280Instantiate(&instance, resolveTestImports);
    printStart("const.280.wasm");
    assertEqualF32(
        const280_f(&instance),
        1125899906842624.0,
        "f()"
    );
}
