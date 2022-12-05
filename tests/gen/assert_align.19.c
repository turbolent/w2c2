
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_align.19.h"

void test() {
    align19Instance instance;
    align19Instantiate(&instance, resolveTestImports);
    printStart("align.19.wasm");
}
