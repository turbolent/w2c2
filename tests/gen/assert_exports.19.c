
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.19.h"

void test() {
    exports19Instance instance;
    exports19Instantiate(&instance, resolveTestImports);
    printStart("exports.19.wasm");
}
