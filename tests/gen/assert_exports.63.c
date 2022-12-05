
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.63.h"

void test() {
    exports63Instance instance;
    exports63Instantiate(&instance, resolveTestImports);
    printStart("exports.63.wasm");
}
