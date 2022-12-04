
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_elem.15.h"

void test() {
    elem15Instance instance;
    elem15Instantiate(&instance, resolveTestImports);
    printStart("elem.15.wasm");
}
