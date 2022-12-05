
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.72.h"

void test() {
    const72Instance instance;
    const72Instantiate(&instance, resolveTestImports);
    printStart("const.72.wasm");
}
