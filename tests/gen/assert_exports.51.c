
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.51.h"

void test() {
    exports51Instance instance;
    exports51Instantiate(&instance, resolveTestImports);
    printStart("exports.51.wasm");
}
