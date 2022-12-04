
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.0.h"

void test() {
    exports0Instance instance;
    exports0Instantiate(&instance, resolveTestImports);
    printStart("exports.0.wasm");
}
