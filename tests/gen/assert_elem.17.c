
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_elem.17.h"

void test() {
    elem17Instance instance;
    elem17Instantiate(&instance, resolveTestImports);
    printStart("elem.17.wasm");
}
