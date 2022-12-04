
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.22.h"

void test() {
    const22Instance instance;
    const22Instantiate(&instance, resolveTestImports);
    printStart("const.22.wasm");
}
