
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_elem.4.h"

void test() {
    elem4Instance instance;
    elem4Instantiate(&instance, resolveTestImports);
    printStart("elem.4.wasm");
}
