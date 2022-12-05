
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.6.h"

void test() {
    exports6Instance instance;
    exports6Instantiate(&instance, resolveTestImports);
    printStart("exports.6.wasm");
}
