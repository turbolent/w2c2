
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.23.h"

void test() {
    m10_exportsX2E23Instance instance;
    m10_exportsX2E23Instantiate(&instance, resolveTestImports);
    printStart("exports.23.wasm");
}
