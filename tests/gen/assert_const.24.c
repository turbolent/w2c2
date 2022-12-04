
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.24.h"

void test() {
    const24Instance instance;
    const24Instantiate(&instance, resolveTestImports);
    printStart("const.24.wasm");
}
