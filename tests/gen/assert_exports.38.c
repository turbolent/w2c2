
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.38.h"

void test() {
    m10_exportsX2E38Instance instance;
    m10_exportsX2E38Instantiate(&instance, resolveTestImports);
    printStart("exports.38.wasm");
}
