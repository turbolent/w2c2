
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_elem.6.h"

void test() {
    elem6Instance instance;
    elem6Instantiate(&instance, resolveTestImports);
    printStart("elem.6.wasm");
}
