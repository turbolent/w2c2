
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_atomic.2.h"

void test() {
    atomic2Instance instance;
    atomic2Instantiate(&instance, resolveTestImports);
    printStart("atomic.2.wasm");
}
