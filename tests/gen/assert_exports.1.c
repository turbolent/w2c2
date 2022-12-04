
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.1.h"

void test() {
    exports1Instance instance;
    exports1Instantiate(&instance, resolveTestImports);
    printStart("exports.1.wasm");
}
