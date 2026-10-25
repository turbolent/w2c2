
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_bulk.4.h"

void test() {
    m6_bulkX2E4Instance instance;
    m6_bulkX2E4Instantiate(&instance, resolveTestImports);
    printStart("bulk.4.wasm");
    m6_bulkX2E4Export12_initX5Fpassive(&instance, 1u);
    printOK("init_passive(1u)");
    m6_bulkX2E4Export12_dropX5Fpassive(&instance);
    printOK("drop_passive()");
    m6_bulkX2E4Export12_dropX5Fpassive(&instance);
    printOK("drop_passive()");
    m6_bulkX2E4Export12_initX5Fpassive(&instance, 0u);
    m6_bulkX2E4Export12_initX5Fpassive(&instance, 0u);
    printOK("init_passive(0u)");
    m6_bulkX2E4Export11_dropX5Factive(&instance);
    printOK("drop_active()");
    m6_bulkX2E4Export11_initX5Factive(&instance, 0u);
    m6_bulkX2E4Export11_initX5Factive(&instance, 0u);
    printOK("init_active(0u)");
}
