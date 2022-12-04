
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.33.h"

void test() {
    exports33Instance instance;
    exports33Instantiate(&instance, resolveTestImports);
    printStart("exports.33.wasm");
}
