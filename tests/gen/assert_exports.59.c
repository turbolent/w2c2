
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.59.h"

void test() {
    m10_exportsX2E59Instance instance;
    m10_exportsX2E59Instantiate(&instance, resolveTestImports);
    printStart("exports.59.wasm");
}
