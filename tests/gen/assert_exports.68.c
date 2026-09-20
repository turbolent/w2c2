
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.68.h"

void test() {
    m10_exportsX2E68Instance instance;
    m10_exportsX2E68Instantiate(&instance, resolveTestImports);
    printStart("exports.68.wasm");
}
