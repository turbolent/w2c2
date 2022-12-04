
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_export_imported_function.0.h"

void test() {
    exportimportedfunction0Instance instance;
    exportimportedfunction0Instantiate(&instance, resolveTestImports);
    printStart("export_imported_function.0.wasm");
}
