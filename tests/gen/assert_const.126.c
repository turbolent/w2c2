
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.126.h"

void test() {
    const126Instance instance;
    const126Instantiate(&instance, resolveTestImports);
    printStart("const.126.wasm");
}
