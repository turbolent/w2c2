
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.48.h"

void test() {
    m10_exportsX2E48Instance instance;
    m10_exportsX2E48Instantiate(&instance, resolveTestImports);
    printStart("exports.48.wasm");
}
