
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.41.h"

void test() {
    m10_exportsX2E41Instance instance;
    m10_exportsX2E41Instantiate(&instance, resolveTestImports);
    printStart("exports.41.wasm");
}
