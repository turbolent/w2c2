
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_elem.13.h"

void test() {
    elem13Instance instance;
    elem13Instantiate(&instance, resolveTestImports);
    printStart("elem.13.wasm");
}
