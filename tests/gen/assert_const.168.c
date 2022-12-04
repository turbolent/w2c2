
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.168.h"

void test() {
    const168Instance instance;
    const168Instantiate(&instance, resolveTestImports);
    printStart("const.168.wasm");
}
