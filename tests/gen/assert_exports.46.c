
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.46.h"

void test() {
    exports46Instance instance;
    exports46Instantiate(&instance, resolveTestImports);
    printStart("exports.46.wasm");
}
