
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_elem.5.h"

void test() {
    elem5Instance instance;
    elem5Instantiate(&instance, resolveTestImports);
    printStart("elem.5.wasm");
}
