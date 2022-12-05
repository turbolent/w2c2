
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.36.h"

void test() {
    exports36Instance instance;
    exports36Instantiate(&instance, resolveTestImports);
    printStart("exports.36.wasm");
}
