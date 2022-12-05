
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.54.h"

void test() {
    exports54Instance instance;
    exports54Instantiate(&instance, resolveTestImports);
    printStart("exports.54.wasm");
}
