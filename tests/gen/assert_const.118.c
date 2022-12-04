
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.118.h"

void test() {
    const118Instance instance;
    const118Instantiate(&instance, resolveTestImports);
    printStart("const.118.wasm");
}
