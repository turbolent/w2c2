
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.50.h"

void test() {
    exports50Instance instance;
    exports50Instantiate(&instance, resolveTestImports);
    printStart("exports.50.wasm");
}
