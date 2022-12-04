
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.376.h"

void test() {
    const376Instance instance;
    const376Instantiate(&instance, resolveTestImports);
    printStart("const.376.wasm");
    assertEqualF64(
        const376_f(&instance),
        5.357543035931338e+300,
        "f()"
    );
}
