
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.22.h"

void test() {
    m10_exportsX2E22Instance instance;
    m10_exportsX2E22Instantiate(&instance, resolveTestImports);
    printStart("exports.22.wasm");
}
