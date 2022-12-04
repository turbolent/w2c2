
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.39.h"

void test() {
    exports39Instance instance;
    exports39Instantiate(&instance, resolveTestImports);
    printStart("exports.39.wasm");
}
