
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_elem.12.h"

void test() {
    elem12Instance instance;
    elem12Instantiate(&instance, resolveTestImports);
    printStart("elem.12.wasm");
}
