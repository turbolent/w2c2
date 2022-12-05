
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.161.h"

void test() {
    const161Instance instance;
    const161Instantiate(&instance, resolveTestImports);
    printStart("const.161.wasm");
}
