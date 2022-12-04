
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.7.h"

void test() {
    exports7Instance instance;
    exports7Instantiate(&instance, resolveTestImports);
    printStart("exports.7.wasm");
}
