
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.12.h"

void test() {
    const12Instance instance;
    const12Instantiate(&instance, resolveTestImports);
    printStart("const.12.wasm");
}
