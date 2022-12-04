
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_elem.9.h"

void test() {
    elem9Instance instance;
    elem9Instantiate(&instance, resolveTestImports);
    printStart("elem.9.wasm");
}
