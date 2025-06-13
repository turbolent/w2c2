
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.65.h"

void test() {
    exports65Instance instance;
    exports65Instantiate(&instance, resolveTestImports);
    printStart("exports.65.wasm");
}
