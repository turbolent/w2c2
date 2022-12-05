
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.42.h"

void test() {
    exports42Instance instance;
    exports42Instantiate(&instance, resolveTestImports);
    printStart("exports.42.wasm");
}
