
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.66.h"

void test() {
    exports66Instance instance;
    exports66Instantiate(&instance, resolveTestImports);
    printStart("exports.66.wasm");
}
