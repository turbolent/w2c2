
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_elem.2.h"

void test() {
    elem2Instance instance;
    elem2Instantiate(&instance, resolveTestImports);
    printStart("elem.2.wasm");
}
