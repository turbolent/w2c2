
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.59.h"

void test() {
    const59Instance instance;
    const59Instantiate(&instance, resolveTestImports);
    printStart("const.59.wasm");
}
