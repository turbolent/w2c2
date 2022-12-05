
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.37.h"

void test() {
    exports37Instance instance;
    exports37Instantiate(&instance, resolveTestImports);
    printStart("exports.37.wasm");
}
