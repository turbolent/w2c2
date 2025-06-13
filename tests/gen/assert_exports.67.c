
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.67.h"

void test() {
    exports67Instance instance;
    exports67Instantiate(&instance, resolveTestImports);
    printStart("exports.67.wasm");
}
