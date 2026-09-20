
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.60.h"

void test() {
    m10_exportsX2E60Instance instance;
    m10_exportsX2E60Instantiate(&instance, resolveTestImports);
    printStart("exports.60.wasm");
}
