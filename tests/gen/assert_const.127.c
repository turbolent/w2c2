
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.127.h"

void test() {
    const127Instance instance;
    const127Instantiate(&instance, resolveTestImports);
    printStart("const.127.wasm");
}
