
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_elem.8.h"

void test() {
    elem8Instance instance;
    elem8Instantiate(&instance, resolveTestImports);
    printStart("elem.8.wasm");
}
