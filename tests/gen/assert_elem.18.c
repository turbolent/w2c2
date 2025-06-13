
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_elem.18.h"

void test() {
    elem18Instance instance;
    elem18Instantiate(&instance, resolveTestImports);
    printStart("elem.18.wasm");
}
