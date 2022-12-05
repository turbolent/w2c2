
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.413.h"

void test() {
    const413Instance instance;
    const413Instantiate(&instance, resolveTestImports);
    printStart("const.413.wasm");
    assertEqualF64(
        const413_f(&instance),
        -1.584563250285287e+29,
        "f()"
    );
}
