
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.73.h"

void test() {
    m10_exportsX2E73Instance instance;
    m10_exportsX2E73Instantiate(&instance, resolveTestImports);
    printStart("exports.73.wasm");
}
