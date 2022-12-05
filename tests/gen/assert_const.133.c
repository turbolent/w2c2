
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.133.h"

void test() {
    const133Instance instance;
    const133Instantiate(&instance, resolveTestImports);
    printStart("const.133.wasm");
}
