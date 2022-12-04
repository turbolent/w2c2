
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.28.h"

void test() {
    const28Instance instance;
    const28Instantiate(&instance, resolveTestImports);
    printStart("const.28.wasm");
}
