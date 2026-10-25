
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.30.h"

void test() {
    m10_exportsX2E30Instance instance;
    m10_exportsX2E30Instantiate(&instance, resolveTestImports);
    printStart("exports.30.wasm");
}
