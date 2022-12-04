
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.25.h"

void test() {
    const25Instance instance;
    const25Instantiate(&instance, resolveTestImports);
    printStart("const.25.wasm");
}
