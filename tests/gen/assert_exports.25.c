
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.25.h"

void test() {
    exports25Instance instance;
    exports25Instantiate(&instance, resolveTestImports);
    printStart("exports.25.wasm");
}
