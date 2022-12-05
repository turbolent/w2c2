
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.132.h"

void test() {
    const132Instance instance;
    const132Instantiate(&instance, resolveTestImports);
    printStart("const.132.wasm");
}
