
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.269.h"

void test() {
    const269Instance instance;
    const269Instantiate(&instance, resolveTestImports);
    printStart("const.269.wasm");
    assertEqualF32(
        const269_f(&instance),
        -1125900041060352.0,
        "f()"
    );
}
