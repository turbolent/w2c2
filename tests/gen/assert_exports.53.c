
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.53.h"

void test() {
    exports53Instance instance;
    exports53Instantiate(&instance, resolveTestImports);
    printStart("exports.53.wasm");
}
