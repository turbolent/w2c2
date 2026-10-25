
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.43.h"

void test() {
    m10_exportsX2E43Instance instance;
    m10_exportsX2E43Instantiate(&instance, resolveTestImports);
    printStart("exports.43.wasm");
}
