
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.57.h"

void test() {
    exports57Instance instance;
    exports57Instantiate(&instance, resolveTestImports);
    printStart("exports.57.wasm");
}
