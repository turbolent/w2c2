
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.25.h"

void test() {
    m10_exportsX2E25Instance instance;
    m10_exportsX2E25Instantiate(&instance, resolveTestImports);
    printStart("exports.25.wasm");
}
