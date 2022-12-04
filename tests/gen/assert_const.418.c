
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.418.h"

void test() {
    const418Instance instance;
    const418Instantiate(&instance, resolveTestImports);
    printStart("const.418.wasm");
    assertEqualF64(
        const418_f(&instance),
        1.584563250285287e+29,
        "f()"
    );
}
