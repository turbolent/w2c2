
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.56.h"

void test() {
    exports56Instance instance;
    exports56Instantiate(&instance, resolveTestImports);
    printStart("exports.56.wasm");
}
