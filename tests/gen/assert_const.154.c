
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.154.h"

void test() {
    const154Instance instance;
    const154Instantiate(&instance, resolveTestImports);
    printStart("const.154.wasm");
}
