
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.399.h"

void test() {
    const399Instance instance;
    const399Instantiate(&instance, resolveTestImports);
    printStart("const.399.wasm");
    assertEqualF64(
        const399_f(&instance),
        -4.149515568880995e+180,
        "f()"
    );
}
