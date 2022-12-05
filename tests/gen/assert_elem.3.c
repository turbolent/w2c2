
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_elem.3.h"

void test() {
    elem3Instance instance;
    elem3Instantiate(&instance, resolveTestImports);
    printStart("elem.3.wasm");
}
