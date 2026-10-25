
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.61.h"

void test() {
    m10_exportsX2E61Instance instance;
    m10_exportsX2E61Instantiate(&instance, resolveTestImports);
    printStart("exports.61.wasm");
}
