
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.64.h"

void test() {
    m10_exportsX2E64Instance instance;
    m10_exportsX2E64Instantiate(&instance, resolveTestImports);
    printStart("exports.64.wasm");
}
