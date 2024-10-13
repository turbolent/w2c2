
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_elem.7.h"

void test() {
    elem7Instance instance;
    elem7Instantiate(&instance, resolveTestImports);
    printStart("elem.7.wasm");
}
