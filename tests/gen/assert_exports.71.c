
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.71.h"

void test() {
    exports71Instance instance;
    exports71Instantiate(&instance, resolveTestImports);
    printStart("exports.71.wasm");
}
