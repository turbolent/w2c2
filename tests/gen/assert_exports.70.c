
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.70.h"

void test() {
    exports70Instance instance;
    exports70Instantiate(&instance, resolveTestImports);
    printStart("exports.70.wasm");
}
