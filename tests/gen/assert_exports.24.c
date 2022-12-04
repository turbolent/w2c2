
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.24.h"

void test() {
    exports24Instance instance;
    exports24Instantiate(&instance, resolveTestImports);
    printStart("exports.24.wasm");
}
