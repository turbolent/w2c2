
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.53.h"

void test() {
    m10_exportsX2E53Instance instance;
    m10_exportsX2E53Instantiate(&instance, resolveTestImports);
    printStart("exports.53.wasm");
}
