
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.20.h"

void test() {
    exports20Instance instance;
    exports20Instantiate(&instance, resolveTestImports);
    printStart("exports.20.wasm");
}
