
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.42.h"

void test() {
    m10_exportsX2E42Instance instance;
    m10_exportsX2E42Instantiate(&instance, resolveTestImports);
    printStart("exports.42.wasm");
}
