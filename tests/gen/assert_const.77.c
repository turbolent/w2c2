
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.77.h"

void test() {
    const77Instance instance;
    const77Instantiate(&instance, resolveTestImports);
    printStart("const.77.wasm");
}
