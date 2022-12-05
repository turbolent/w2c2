
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.43.h"

void test() {
    exports43Instance instance;
    exports43Instantiate(&instance, resolveTestImports);
    printStart("exports.43.wasm");
}
