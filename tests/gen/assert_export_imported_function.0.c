
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_export_imported_function.0.h"

void test() {
    m26_exportX5FimportedX5FfunctionX2E0Instance instance;
    m26_exportX5FimportedX5FfunctionX2E0Instantiate(&instance, resolveTestImports);
    printStart("export_imported_function.0.wasm");
}
