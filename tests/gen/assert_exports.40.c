
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.40.h"

void test() {
    exports40Instance instance;
    exports40Instantiate(&instance, resolveTestImports);
    printStart("exports.40.wasm");
}
