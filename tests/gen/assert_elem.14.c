
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_elem.14.h"

void test() {
    elem14Instance instance;
    elem14Instantiate(&instance, resolveTestImports);
    printStart("elem.14.wasm");
}
