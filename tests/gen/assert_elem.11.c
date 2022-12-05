
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_elem.11.h"

void test() {
    elem11Instance instance;
    elem11Instantiate(&instance, resolveTestImports);
    printStart("elem.11.wasm");
}
