
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.69.h"

void test() {
    m10_exportsX2E69Instance instance;
    m10_exportsX2E69Instantiate(&instance, resolveTestImports);
    printStart("exports.69.wasm");
}
