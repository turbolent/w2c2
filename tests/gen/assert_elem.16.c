
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_elem.16.h"

void test() {
    elem16Instance instance;
    elem16Instantiate(&instance, resolveTestImports);
    printStart("elem.16.wasm");
}
