
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.23.h"

void test() {
    exports23Instance instance;
    exports23Instantiate(&instance, resolveTestImports);
    printStart("exports.23.wasm");
}
