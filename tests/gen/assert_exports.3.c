
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.3.h"

void test() {
    m9_exportsX2E3Instance instance;
    m9_exportsX2E3Instantiate(&instance, resolveTestImports);
    printStart("exports.3.wasm");
}
