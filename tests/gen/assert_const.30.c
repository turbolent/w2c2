
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.30.h"

void test() {
    const30Instance instance;
    const30Instantiate(&instance, resolveTestImports);
    printStart("const.30.wasm");
}
