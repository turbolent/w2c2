
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.35.h"

void test() {
    exports35Instance instance;
    exports35Instantiate(&instance, resolveTestImports);
    printStart("exports.35.wasm");
}
