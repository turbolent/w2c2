
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_elem.0.h"

void test() {
    elem0Instance instance;
    elem0Instantiate(&instance, resolveTestImports);
    printStart("elem.0.wasm");
}
