
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.10.h"

void test() {
    exports10Instance instance;
    exports10Instantiate(&instance, resolveTestImports);
    printStart("exports.10.wasm");
}
