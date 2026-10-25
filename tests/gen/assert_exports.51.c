
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.51.h"

void test() {
    m10_exportsX2E51Instance instance;
    m10_exportsX2E51Instantiate(&instance, resolveTestImports);
    printStart("exports.51.wasm");
}
