
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.61.h"

void test() {
    exports61Instance instance;
    exports61Instantiate(&instance, resolveTestImports);
    printStart("exports.61.wasm");
}
