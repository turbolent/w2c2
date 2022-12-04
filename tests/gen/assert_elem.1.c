
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_elem.1.h"

void test() {
    elem1Instance instance;
    elem1Instantiate(&instance, resolveTestImports);
    printStart("elem.1.wasm");
}
