
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.72.h"

void test() {
    m10_exportsX2E72Instance instance;
    m10_exportsX2E72Instantiate(&instance, resolveTestImports);
    printStart("exports.72.wasm");
}
