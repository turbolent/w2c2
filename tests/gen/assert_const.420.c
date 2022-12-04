
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.420.h"

void test() {
    const420Instance instance;
    const420Instantiate(&instance, resolveTestImports);
    printStart("const.420.wasm");
    assertEqualF64(
        const420_f(&instance),
        1.584563250285287e+29,
        "f()"
    );
}
