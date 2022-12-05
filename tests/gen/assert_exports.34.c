
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.34.h"

void test() {
    exports34Instance instance;
    exports34Instantiate(&instance, resolveTestImports);
    printStart("exports.34.wasm");
}
