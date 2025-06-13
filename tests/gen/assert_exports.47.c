
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.47.h"

void test() {
    exports47Instance instance;
    exports47Instantiate(&instance, resolveTestImports);
    printStart("exports.47.wasm");
}
