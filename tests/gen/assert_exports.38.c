
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.38.h"

void test() {
    exports38Instance instance;
    exports38Instantiate(&instance, resolveTestImports);
    printStart("exports.38.wasm");
}
