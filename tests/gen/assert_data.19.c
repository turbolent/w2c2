
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_data.19.h"

void test() {
    data19Instance instance;
    data19Instantiate(&instance, resolveTestImports);
    printStart("data.19.wasm");
}
