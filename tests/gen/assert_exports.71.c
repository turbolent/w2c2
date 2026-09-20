
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.71.h"

void test() {
    m10_exportsX2E71Instance instance;
    m10_exportsX2E71Instantiate(&instance, resolveTestImports);
    printStart("exports.71.wasm");
}
