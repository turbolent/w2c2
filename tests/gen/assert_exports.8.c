
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.8.h"

void test() {
    exports8Instance instance;
    exports8Instantiate(&instance, resolveTestImports);
    printStart("exports.8.wasm");
}
