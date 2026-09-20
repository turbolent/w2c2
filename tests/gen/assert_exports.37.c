
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.37.h"

void test() {
    m10_exportsX2E37Instance instance;
    m10_exportsX2E37Instantiate(&instance, resolveTestImports);
    printStart("exports.37.wasm");
}
