
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.20.h"

void test() {
    m10_exportsX2E20Instance instance;
    m10_exportsX2E20Instantiate(&instance, resolveTestImports);
    printStart("exports.20.wasm");
}
