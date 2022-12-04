
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.21.h"

void test() {
    exports21Instance instance;
    exports21Instantiate(&instance, resolveTestImports);
    printStart("exports.21.wasm");
}
