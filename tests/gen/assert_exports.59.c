
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.59.h"

void test() {
    exports59Instance instance;
    exports59Instantiate(&instance, resolveTestImports);
    printStart("exports.59.wasm");
}
